
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Thu May  7 09:27:39 2026
style:      C-Kernel with custom pointer rule
tab-width:  4 spaces

 /\_/\
( o.o )
 > ^ <

See more about the style at:
https://iluvgirlswithglasses.github.io/style/cpp
*/

#pragma GCC optimize ("O3")

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdint>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
using namespace std;

#include "softmax.h"
// int get_batch(double* logits, double* values) { return 0; }
// void submit(double result) {}

void solve(int Q)
{
    vector<double> logits(8 * Q);
    vector<double> values(8 * Q);
    vector<double> exp_logits(8 * Q);
    double cum_logits;

    for (int i = 0; i < Q; ++i) {
        int cont = get_batch(&logits[i * 8], &values[i * 8]);
        for (int j = i * 8; j < i * 8 + 8; ++j) {
            exp_logits[j] = exp(logits[j]);
            if (j == 0) {
                cum_logits = exp_logits[0];
                continue;
            }
            cum_logits += exp_logits[j];
        }

        double ans = 0;
        for (int j = 0; j < i * 8 + 8; ++j)
            ans += values[j] * exp_logits[j] / cum_logits;

        submit(ans);
        if (!cont)
            break;
    }
}

