
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Mon Jun 17 09:38:30 2024
style:      C-Kernel with custom pointer rule
tab-width:  4 spaces

 /\_/\
( o.o )
 > ^ <

See more about the style at:
https://iluvgirlswithglasses.github.io/style/cpp
*/

#include "orient-calculator.h"
#include <dlib/image_transforms.h>
#include <cmath>
#include <iostream>

namespace eupho
{
namespace preproc
{

/**
 * @! init funcs -----------------------------------------------------
 * */
OrientCalculator::OrientCalculator()
{
}

void OrientCalculator::load(const inp_t& img)
{
    dlib::sobel_edge_detector(img, gx, gy);

    for (long r = 1; r <= H; ++r) {
        for (long c = 1; c <= W; ++c) {
            // prefix matrices keeps 4-digit precision
            int64_t dy = static_cast<int64_t>(gy(r-1, c-1) * 16384);    // mul 2^14
            int64_t dx = static_cast<int64_t>(gx(r-1, c-1) * 16384);    // mul 2^14

            pxx(r, c) = dx * dx + pxx(r-1, c) + pxx(r, c-1) - pxx(r-1, c-1);
            pyy(r, c) = dy * dy + pyy(r-1, c) + pyy(r, c-1) - pyy(r-1, c-1);
            pxy(r, c) = dx * dy + pxy(r-1, c) + pxy(r, c-1) - pxy(r-1, c-1);
        }
    }

    // !TODO: Remove this after all tests are finished
    const auto prefix_assert = [](const pre_t& p) {
        for (long r = 0; r < p.nr(); ++r) {
            if (p(r, 0) != 0) {
                std::cout << "found garbage memory in prefix array\n";
                return;
            }
        }
    };
    prefix_assert(pxx);
    prefix_assert(pyy);
    prefix_assert(pxy);
}


/**
 * @! public methods -------------------------------------------------
 * */
void OrientCalculator::calculate(
    long bs,
    ori_t& ori, ocl_t& ocl
) const
{
    calculate(bs, 0, 0, ori, ocl);
}

void OrientCalculator::calculate(
    long bs,
    long off_t, long off_l,
    ori_t& ori, ocl_t& ocl
) const
{
    // iterate through every block
    for (long i = 0; i < ori.nr(); ++i) {
        for (long j = 0; j < ori.nc(); ++j) {

            long t = off_t + bs * i;
            long l = off_l + bs * j;
            long d = t + bs;
            long r = l + bs;

            float a = sum(pxx, t, l, d, r);
            float b = sum(pyy, t, l, d, r);
            float c = sum(pxy, t, l, d, r);

            // calculate the orientation of the (i, j) block
            ori(i, j) = (Param::Pi + std::atan2f(2 * c, a - b)) / 2;

            // calculate the orientation certainty level of the (i, j) block
            float sumPart = a + b;
            float mulPart = std::sqrtf((a - b) * (a - b) + 4 * c * c);
            if (sumPart + mulPart > 0)
                ocl(i, j) = (sumPart - mulPart) / (sumPart + mulPart);
            else
                ocl(i, j) = 1;  // no gradient --> no orientation certainty

        }
    }
}

void OrientCalculator::smoothen(const ori_t& src, ori_t& dst)
{
    /** ---- memory allocation ---- */
    qx.set_size(src.nr(), src.nc());
    qy.set_size(src.nr(), src.nc());
    qt.set_size(src.nr(), src.nc());

    const float* isrc;
    float* itmp;

    /** ---- calculate `qx` (aka. phi'_x) ---- */
    for (isrc = src.begin(), itmp = qt.begin(); isrc < src.end(); ++isrc, ++itmp)
        *itmp = std::cosf(2 * (*isrc));
    dlib::gaussian_blur(qt, qx, 1, 5);

    /** ---- calculate `qy` (aka. phi'_y) ---- */
    for (isrc = src.begin(), itmp = qt.begin(); isrc < src.end(); ++isrc, ++itmp)
        *itmp = std::sinf(2 * (*isrc));
    dlib::gaussian_blur(qt, qy, 1, 5);

    /** ---- merge result ---- */
    float* o = dst.begin();
    float* y = qy.begin();
    float* x = qx.begin();
    for (; o < dst.end(); ++o, ++y, ++x) {
        *o = atan2f(*y, *x) / 2;
        if (*o < 0)
            *o += Param::Pi;
    }

    /*!
    The calculation of phi'_x, phi'_y, and `dst` here has a subtle
    difference from those in academic PoinCare papers.

    If you search for every line with the `atan2` function, you would
    see that I always map the range [-pi, +pi] of the said function to
    [0, +2pi]. That's because I don't wanna work with negative number.

    As a consequence, there are discrepancies here and there. For ex-
    ample: My `qx[y, x]` is actually equal to `-phi'_x(y, x)`; simi-
    larly, `qy[y, x] = -phi'_y(y, x)`. All the formulars can be found
    in my Lost Chapter The Second (the codex book) and should be re-
    written into official document someday.
    !*/
}


/**
 * @! private methods ------------------------------------------------
 * */
float OrientCalculator::sum(
    const pre_t& pre,
    long t, long l, long d, long r
) const
{
    // using numpy inclusive-exclusive range:
    // sum( dev[t:d, l:r] ) = pre[d, r] - pre[t, r] - pre[d, l] + pre[t, l];
    int64_t raw = pre(d, r) - pre(t, r) - pre(d, l) + pre(t, l);
    return raw >> 28;
}


}   // namespace preproc
}   // namespace eupho

