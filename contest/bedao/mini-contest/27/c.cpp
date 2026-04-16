
/*
author:     iluvgirlswithglasses
github:     https://github.com/iluvgirlswithglasses
created:    Thu Apr 16 21:30:56 2026
style:      C-Kernel with custom pointer rule
tab-width:  4 spaces

 /\_/\
( o.o )
 > ^ <

See more about the style at:
https://iluvgirlswithglasses.github.io/style/cpp
*/

#include <cinttypes>
#include <utility>
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

// some words from fallingstar:

/**
 * My fuckin' trash template for CP.
 * Update:
 * - Too much pragma.
 * - (Copied) new function for faster reading / writing (or not)
 * To read / write: just use cin / cout
 **/

static struct FastInput
{
    static constexpr int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    size_t chars_read = 0;
    size_t buf_pos = 0;
    FILE *in = stdin;
    char cur = 0;

    inline char get_char()
    {
        if (buf_pos >= chars_read) {
            chars_read = fread(buf, 1, BUF_SIZE, in);
            buf_pos = 0;
            buf[0] = (chars_read == 0 ? -1 : buf[0]);
        }
        return cur = buf[buf_pos++];
    }

    inline void tie(int) {}

    inline explicit operator bool() { return cur != -1; }

    inline static bool is_blank(char c) { return c <= ' '; }

    inline bool skip_blanks()
    {
        while (is_blank(cur) && cur != -1) {
            get_char();
        }
        return cur != -1;
    }

    inline FastInput& operator>>(char& c)
    {
        skip_blanks();
        c = cur;
        return *this;
    }

    inline FastInput& operator>>(string& s)
    {
        if (skip_blanks()) {
            s.clear();
            do {
                s += cur;
            } while (!is_blank(get_char()));
        }
        return *this;
    }

    template <typename T>
    inline FastInput& read_integer(T& n)
    {
        // unsafe, doesn't check that characters are actually digits
        n = 0;
        if (skip_blanks()) {
            int sign = +1;
            if (cur == '-') {
                sign = -1;
                get_char();
            }
            do {
                n += n + (n << 3) + cur - '0';
            } while (!is_blank(get_char()));
            n *= sign;
        }
        return *this;
    }

    template <typename T>
    inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(T& n)
    {
        return read_integer(n);
    }

    #if !defined(_WIN32) | defined(_WIN64)
    inline FastInput& operator>>(__int128& n)
    {
        return read_integer(n);
    }
    #endif

    template <typename T>
    inline typename enable_if<is_floating_point<T>::value, FastInput&>::type operator>>(T& n)
    {
        // not sure if really fast, for compatibility only
        n = 0;
        if (skip_blanks()) {
            string s;
            (*this) >> s;
            sscanf(s.c_str(), "%lf", &n);
        }
        return *this;
    }
} fast_input;

#define cin fast_input

static struct FastOutput
{
    static constexpr int BUF_SIZE = 1 << 20;
    char buf[BUF_SIZE];
    size_t buf_pos = 0;
    static constexpr int TMP_SIZE = 1 << 20;
    char tmp[TMP_SIZE];
    FILE *out = stdout;

    inline void put_char(char c)
    {
        buf[buf_pos++] = c;
        if (buf_pos == BUF_SIZE) {
            fwrite(buf, 1, buf_pos, out);
            buf_pos = 0;
        }
    }

    ~FastOutput()
    {
        fwrite(buf, 1, buf_pos, out);
    }

    inline FastOutput& operator<<(char c)
    {
        put_char(c);
        return *this;
    }

    inline FastOutput& operator<<(const char* s)
    {
        while (*s) {
            put_char(*s++);
        }
        return *this;
    }

    inline FastOutput& operator<<(const string& s)
    {
        for (int i = 0; i < (int) s.size(); i++) {
            put_char(s[i]);
        }
        return *this;
    }

    template <typename T>
    inline char* integer_to_string(T n)
    {
        // beware of TMP_SIZE
        char* p = tmp + TMP_SIZE - 1;
        if (n == 0) {
            *--p = '0';
        } else {
            bool is_negative = false;
            if (n < 0) {
                is_negative = true;
                n = -n;
            }
            while (n > 0) {
                *--p = (char) ('0' + n % 10);
                n /= 10;
            }
            if (is_negative) {
                *--p = '-';
            }
        }
        return p;
    }

    template <typename T>
    inline typename enable_if<is_integral<T>::value, char*>::type stringify(T n)
    {
        return integer_to_string(n);
    }

    #if !defined(_WIN32) || defined(_WIN64)
    inline char* stringify(__int128 n)
    {
        return integer_to_string(n);
    }
    #endif

    template <typename T>
    inline typename enable_if<is_floating_point<T>::value, char*>::type stringify(T n)
    {
        sprintf(tmp, "%.17f", n);
        return tmp;
    }

    template <typename T>
    inline FastOutput& operator<<(const T& n)
    {
        auto p = stringify(n);
        for (; *p != 0; p++) {
            put_char(*p);
        }
        return *this;
    }
} fast_output;

#define cout fast_output

typedef pair<int, int> pi;
typedef pair<int64_t, pair<int, int>> record;   // max cum, left, right
#define st first
#define nd second
#define all(c) c.begin(), c.end()
#define has(c, a) c.find(a) != c.end()

const int N = 1e5+7, I = 1e9+7, R = 1e9+7;
int64_t n, x, a[N];

// dp1[r] = best at `r` where no multiplication was done
// dp2[r] = best at `r` when multiplication is on-going
// dp3[r] = best at `r` where multiplication finished
int64_t dp1[N], dp2[N], dp3[N];


void solve()
{
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    dp1[1] = a[1];
    dp2[1] = a[1] * x;
    dp3[1] = a[1];
    int64_t best = max({dp1[1], dp2[1], dp3[1]});

    // -1 2 1 4  1
    // -2 4 2 8 -2
    // -1 2 3 5  5

    for (int i = 2; i <= n; ++i) {
        // no state can transition to this one other than itself
        dp1[i] = max({ dp1[i-1] + a[i], a[i] });

        // this one can either continue, or fired up from dp1
        dp2[i] = max({ dp2[i-1] + a[i] * x, dp1[i-1] + a[i] * x, a[i] * x });

        // anyone can transition to this guy, I guess?
        dp3[i] = max({ dp3[i-1] + a[i], dp2[i-1] + a[i], dp1[i-1] + a[i], a[i] });

        //
        best = max({ best, dp1[i], dp2[i], dp3[i] });

    }

    cout << best << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    // int tt; cin >> tt;
    int tt = 1;
    while (tt--) {
        solve();
    }
    return 0;
}

