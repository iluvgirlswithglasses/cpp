
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

	/**
	 * @ public operators
	 * */
	// if true --> |this| < |x|
	bool abs_less(const BigNum &x) const {
		if (d.size() == x.d.size()) {
			for (int i = d.size() - 1; i >= 0; i--)
				if (d[i] != x.d[i]) return d[i] < x.d[i];
		}
		return d.size() < x.d.size();
	}

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
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string a, b; cin >> a >> b;
	BigNum x(a), y(b);
	x.sub(y);
	x.print();
	return 0;
}
