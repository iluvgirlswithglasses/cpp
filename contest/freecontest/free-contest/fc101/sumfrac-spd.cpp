
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 05 17:58:29 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
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

typedef unsigned long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int I = 1e9+7;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

// https://en.wikipedia.org/wiki/Prime_gap
// --> max prime gap for this pb's constraints is 288
// --> we can brute force

struct Eratos {

	static const int I = 1e7+7;

	int  n, cnt;
	ll   p[Eratos::I];	// p[i] == the i-th prime, 0-indexed
	bool e[Eratos::I];	// e[i] == 0 --> `i` is prime

	void init(int _n) {
		n = _n;
		e[0] = e[1] = true;
		for (ll i = 2; i <= n; i++) if (e[i] == 0) {
			p[cnt++] = i;
			for (ll j = i*i; j <= n; j+=i) e[j] = true;
		}
	}

	bool is_prime(ll x) {
		if (x <= n)
			return !e[x];
		for (int _i = 0, i = p[0]; i * i <= x; i = p[++_i])
			if (x % i == 0) return false;
		return true;
	}
} er;

// document will come later
// https://github.com/iluvgirlswithglasses/cpp/contest/freecontest/free-contest/fc101/sumfrac.pdf

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	er.init((int) 1e7);
	int tt; cin >> tt;
	while (tt--) {	
		ll n; cin >> n;
		ll f, g;
		for (int i = n; i >= 2; i--) if (er.is_prime(i)) {
			f = i;
			break;
		}
		for (int i = n+1; i <= I; i++) if (er.is_prime(i)) {
			g = i;
			break;
		}
		
		ll y = f * g << 1;	// lcm(2*f, f*g)
		ll x = (f - 2)*g + ((n - f + 1) << 1);
		//     ^ before f  ^ after f
		
		ll k = gcd(y, x);
		x /= k;
		y /= k;
		cout << x << "/" << y << "\n";
	}
	return 0;
}
