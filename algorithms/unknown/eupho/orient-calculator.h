
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Mon Jun 17 09:04:03 2024
style:      C-Kernel with custom pointer rule
tab-width:  4 spaces

 /\_/\
( o.o )
 > ^ <

See more about the style at:
https://iluvgirlswithglasses.github.io/style/cpp
*/

#ifndef LIB__PREPROC__EXTRATOR__ORIENT_CALCULATOR_H
#define LIB__PREPROC__EXTRATOR__ORIENT_CALCULATOR_H

/** @! docs */

/** @! dependencies */
#include <dlib/matrix.h>
#include "../../param.h"

/** @! implementation */
namespace eupho
{
namespace preproc
{

class OrientCalculator
{
public:
    static constexpr size_t
        H = Param::FingerprintImgH,
        W = Param::FingerprintImgW;
    using inp_t = dlib::matrix<float, H, W>;    // normalized input image
    using gra_t = dlib::matrix<float, H, W>;    // gradient of the input image
    using ori_t = dlib::matrix<float>;          // orient image
    using ocl_t = dlib::matrix<float>;          // ocl for the orient image

    OrientCalculator();
    /*!
    Allocate memory for future orient calculations.
    !*/

    void load(const inp_t&);
    /*!
    Initiate the orient calculator for a normalized fingerprint image.
    The following constant properties are generated:
        - gx, gy, pxx, pyy, pxy
    !*/

    void calculate(long bs, ori_t&, ocl_t&) const;
    /*!
    Calculate the global orient map and OCL map of the input image.

    REQUIRES:
        - ori_t.nr() == ocl_t.nr() == inp_t.nr() / bs
        - ori_t.nc() == ocl_t.nc() == inp_t.nc() / bs

    ENSURES:
        ori_t(y, x) in range [0, pi]
        ocl_t(y, x) in range [0, 1]
    !*/

    void calculate(long bs, long t, long l, ori_t&, ocl_t&) const;
    /*!
    Calculate the orient map and the OCL map for the [t:d, l:r] region
    of the input image, where:
        - d = t + bs * ori_t.nr()
        - r = l + bs * ori_t.nc()
        - 0 <= t < d <= H
        - 1 <= l < r <= W
        - ori_t.nr() == ocl_t.nr() == (d - t) / bs
        - ori_t.nc() == ocl_t.nc() == (r - l) / bs

    ENSURES:
        ori_t(y, x) in range [0, pi]
        ocl_t(y, x) in range [0, 1]
    !*/

    void smoothen(const ori_t& src, ori_t& dst);
    /*!
    Smoothens an orientation image using a kind of gaussian blur.

    Passing multiple `src` of different sizes will cause this object
    to re-allocate `qx` and `qy` (see implementation), so avoid that.

    REQUIRES:
        - src.nr() == dst.nr()
        - src.nc() == dst.nc()

    ENSURES:
        dst(y, x) in range [0, pi]
    !*/

private:
    gra_t gx;   // gx[y, x] = gradient along Ox at point (y, x); aka. dx
    gra_t gy;   // gy[y, x] = gradient along Oy at point (y, x); aka. dy
    ori_t qx;   // qx[y, x] = cos(2ori(y, x)); aka. -phi'_x(y, x)
    ori_t qy;   // qy[y, x] = sin(2ori(y, x)); aka. -phi'_y(y, x)
    ori_t qt;   // a temporary matrix to calculate `qx` and `qy`

    /**
     * @! prefix matrices for xx, xy, and yy deviations --------------
     * */
    using pre_t = dlib::matrix<int64_t, H + 1, W + 1>;
    pre_t pxx;  // prefix array for dx * dx
    pre_t pyy;  // prefix array for dy * dy
    pre_t pxy;  // prefix array for dx * dy

    float sum(const pre_t& pre, long t, long l, long d, long r) const;

};

}   // namespace preproc
}   // namespace eupho

#endif  // LIB__PREPROC__EXTRATOR__ORIENT_CALCULATOR_H

