
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Sep 27 21:43:51 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct BigNum {

	const int BASE = 1e4, LOG = 4;

	vector<int> d;
	bool negative;

	/**
	 * @ utils
	 * */
	BigNum(string &s) {
		negative = (s[0] == '-');
		d.resize((s.length() - negative)/LOG + 1, 0);
		for (int i = 0; i < s.length() - negative; i++) {
			int x = (s.length() - negative - 1 - i) / LOG;
			d[x] = d[x]*10 + (s[i + negative] - '0');
		}
	}

	void fix() {
		d.push_back(0);
		for (int i = 0; i < d.size() - 1; i++) {
			d[i+1] += d[i] / BASE;
			d[i] %= BASE;
			if (d[i] < 0) {
				d[i] += BASE;
				d[i+1]--;
			}
		}
		while (d.size() > 1 && d.back() == 0) d.pop_back();
	}

	void print() {
		if (negative)
			printf("-");
	    if (d.back() > 0) 
	    	printf("%d", d.back());
		for (int i = d.size()-2; i >= 0; i--)
			printf("%04d", d[i]);
		printf("\n");
	}

	string to_str() {
		string s = "";
		if (negative)
			s += "-";
		if (d.back() > 0)
			s += to_string(d.back());
		for (int i = d.size()-2; i >= 0; i--) {
			string t = to_string(d[i]);
			s += string(4 - t.length(), '0') + t;
		}
		return s;
	}

	/**
	 * @ comparators
	 * */
	// true --> |this| == |x|
	bool abs_equal(const BigNum &x) const {
		if (d.size() != x.d.size()) return false;
		for (int i = d.size() - 1; i >= 0; i--)
			if (d[i] != x.d[i]) return false;
		return true;
	}

	// true --> this = x
	bool equal(const BigNum &x) const {
		return negative == x.negative && abs_equal(x);
	}

	// general comparator for |this| != |x|
	bool abs_compare(const BigNum &x, bool (*f)(int, int)) const {
		if (d.size() == x.d.size()) {
			for (int i = d.size() - 1; i >= 0; i--)
				if (d[i] != x.d[i]) return (*f)(d[i], x.d[i]);
		}
		return (*f)(d.size(), x.d.size());
	}

	// true --> |this| < |x|
	bool abs_less(const BigNum &x) const {
		return abs_compare(x, [](int i, int j){return i < j;});
	}

	// true --> |this| > |x|
	bool abs_greater(const BigNum &x) const {
		return abs_compare(x, [](int i, int j){return i > j;});
	}

	// true --> this < x
	bool less(const BigNum &x) const {
		if (negative != x.negative)
			return negative;
		if (!negative)
			return abs_less(x);
		return abs_greater(x);
	}

	// true --> this > x
	bool greater(const BigNum &x) const {
		if (negative != x.negative)
			return !negative;
		if (!negative)
			return abs_greater(x);
		return abs_less(x);
	}

	// true --> this >= x
	bool lessequal(const BigNum &x) const {
		return !greater(x);
	}

	// true --> this <= x
	bool greaterequal(const BigNum &x) const {
		return !less(x);
	}

	/**
	 * @ private operators
	 * */
	// only adds directly (skips negative/positive) to `vector<int> d`
	void __add(const BigNum &x) {
		if (x.d.size() > d.size()) d.resize(x.d.size());
		for (int i = 0; i < x.d.size(); i++)
			d[i] += x.d[i];
		fix();
	}

	// only subtracts directly to `vector<int> d`
	// condition: |this| >= |x|
	void __sub(const BigNum &x) {
		for (int i = 0; i < x.d.size(); i++)
			d[i] -= x.d[i];
		fix();
	}

	// condition: |this| < |x|
	void __negsub(const BigNum &x) {
		d.resize(x.d.size());
		for (int i = 0; i < x.d.size(); i++)
			d[i] = x.d[i] - d[i];
		fix();
	}

	// only multiplies directly to `vector<int> d`
	void __mul(const BigNum &x) {
		vector<int> v(d.size() + x.d.size() + 1);
		for (int i = 0; i < d.size(); i++) {
			for (int j = 0; j < x.d.size(); j++) {
				v[i+j  ] += d[i] * x.d[j];
				v[i+j+1] += v[i+j] / BASE;
				v[i+j  ] %= BASE;
			}
		}
		d = v;
		fix();
	}

	/**
	 * @ public operators
	 * */
	void add(const BigNum &x) {
		if (negative == x.negative) {
			__add(x);
		} else {
			if (abs_less(x)) {
				negative ^= 1;
				__negsub(x);
			} else {
				__sub(x);
			}
		}
	}

	void sub(const BigNum &x) {
		if (negative != x.negative) {
			__add(x);
		} else {
			if (abs_less(x)) {
				negative ^= 1;
				__negsub(x);
			} else {
				__sub(x);
			}
		}
	}

	void mul(const BigNum &x) {
		if (x.negative) negative ^= 1;
		__mul(x);
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string a, b; cin >> a >> b;
	BigNum x(a), y(b);
	x.mul(y);
	x.print();
	string s = x.to_str();
	cout << s << "\n";
	return 0;
}
