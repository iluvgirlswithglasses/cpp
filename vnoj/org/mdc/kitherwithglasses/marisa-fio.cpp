
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 28 11:48:37 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// some words from fallingstar:

/**
 * My fuckin' trash template for CP.
 * Update: 
 * - Too much pragma.
 * - (Copied) new function for faster reading / writing (or not)
 * To read / write: just use cin / cout
 **/

static struct FastInput {
	static constexpr int BUF_SIZE = 1 << 20;
	char buf[BUF_SIZE];
	size_t chars_read = 0;
	size_t buf_pos = 0;
	FILE *in = stdin;
	char cur = 0;

	inline char get_char() {
		if (buf_pos >= chars_read) {
			chars_read = fread(buf, 1, BUF_SIZE, in);
			buf_pos = 0;
			buf[0] = (chars_read == 0 ? -1 : buf[0]);
		}
		return cur = buf[buf_pos++];
	}

	inline void tie(int) {}

	inline explicit operator bool() {
		return cur != -1;
	}

	inline static bool is_blank(char c) {
		return c <= ' ';
	}

	inline bool skip_blanks() {
		while (is_blank(cur) && cur != -1) {
			get_char();
		}
		return cur != -1;
	}

	inline FastInput& operator>>(char& c) {
		skip_blanks();
		c = cur;
		return *this;
	}

	inline FastInput& operator>>(string& s) {
		if (skip_blanks()) {
			s.clear();
			do {
				s += cur;
			} while (!is_blank(get_char()));
		}
		return *this;
	}

	template <typename T>
	inline FastInput& read_integer(T& n) {
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
	inline typename enable_if<is_integral<T>::value, FastInput&>::type operator>>(T& n) {
		return read_integer(n);
	}

	#if !defined(_WIN32) | defined(_WIN64)
	inline FastInput& operator>>(__int128& n) {
		return read_integer(n);
	}
	#endif

	template <typename T>
	inline typename enable_if<is_floating_point<T>::value, FastInput&>::type operator>>(T& n) {
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

static struct FastOutput {
	static constexpr int BUF_SIZE = 1 << 20;
	char buf[BUF_SIZE];
	size_t buf_pos = 0;
	static constexpr int TMP_SIZE = 1 << 20;
	char tmp[TMP_SIZE];
	FILE *out = stdout;

	inline void put_char(char c) {
		buf[buf_pos++] = c;
		if (buf_pos == BUF_SIZE) {
			fwrite(buf, 1, buf_pos, out);
			buf_pos = 0;
		}
	}

	~FastOutput() {
		fwrite(buf, 1, buf_pos, out);
	}

	inline FastOutput& operator<<(char c) {
		put_char(c);
		return *this;
	}

	inline FastOutput& operator<<(const char* s) {
		while (*s) {
			put_char(*s++);
		}
		return *this;
	}

	inline FastOutput& operator<<(const string& s) {
		for (int i = 0; i < (int) s.size(); i++) {
			put_char(s[i]);
		}
		return *this;
	}

	template <typename T>
	inline char* integer_to_string(T n) {
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
	inline typename enable_if<is_integral<T>::value, char*>::type stringify(T n) {
		return integer_to_string(n);
	}

	#if !defined(_WIN32) || defined(_WIN64)
	inline char* stringify(__int128 n) {
		return integer_to_string(n);
	}
	#endif

	template <typename T>
	inline typename enable_if<is_floating_point<T>::value, char*>::type stringify(T n) {
		sprintf(tmp, "%.17f", n);
		return tmp;
	}

	template <typename T>
	inline FastOutput& operator<<(const T& n) {
		auto p = stringify(n);
		for (; *p != 0; p++) {
			put_char(*p);
		}
		return *this;
	}
} fast_output;

#define cout fast_output

typedef long long ll;
typedef long double ld;
typedef pair<ld, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 1e5+7;
const int ZERO = -1, NEG = 0, POS = 1;

int n;
int t[N];
ld  a[N];

int calc() {
	// result
	int rlen  = 0;
	ld  rbest = 0.0;
	// iteration
	// dp[0]: {max sum, start from}
	// while dp[1] is min sum
	vector<pi> dp(2, {0.0, N});

	for (int i = 0; i < n; i++) {
		// meet zero --> reset all
		if (t[i] == ZERO) {
			dp[0] = dp[1] = {0.0, N};
			continue;
		}
		// meet positive --> things get simple
		else if (t[i] == POS) {
			// create positive sequence if not exists
			dp[POS].nd = min(i, dp[POS].nd);
			// x*y is compressed into log(x) + log(y)
			dp[POS].st += a[i];
			// if exists a negative sequence --> update it
			if (dp[NEG].nd < N) dp[NEG].st += a[i];
		}
		// meet negative --> swapping things
		else if (t[i] == NEG) {
			swap(dp[0], dp[1]);
			dp[NEG].nd = min(i, dp[NEG].nd);

			dp[NEG].st += a[i];
			if (dp[POS].nd < N) dp[POS].st += a[i];
		}

		// update the result
		if (dp[POS].st > rbest) {
			rbest = dp[POS].st;
			rlen  = i - dp[POS].nd + 1;
		} else if (dp[POS].st == rbest) {
			rlen = max(rlen, i - dp[POS].nd + 1);
		}
	}

	return rlen;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			ll x; cin >> x;
			if (x < 0)
				t[i] = NEG, x = -x;
			else if (x == 0)
				t[i] = ZERO;
			else
				t[i] = POS;
			a[i] = log(x);
		}
		cout << calc() << "\n";
	}
	return 0;
}
