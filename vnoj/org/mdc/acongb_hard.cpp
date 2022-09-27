
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Sep 27 18:36:16 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
this file is deprecated

a better version:
	trick/bignum/bignum.cpp
*/

// no need for python
// imma create my own bignum lib soon

const int BASE = 1e4, L = 4;

// only handle POSITIVE INTEGER
struct BigNum {
	vector<int> d;

	BigNum(string &s) {
		d.resize(s.length()/L + 1, 0);
		for (int i = 0; i < s.length(); i++) {
			int x = (s.length() - 1 - i) / 4;
			d[x] = d[x]*10 + (s[i] - '0');
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
		while (d.size() >= 2 && d.back() == 0) d.pop_back();
	}

	void to_str() {
	    if (d.back() > 0) 
	    	printf("%d", d.back());
		for (int i = d.size()-2; i >= 0; i--)
			printf("%04d", d[i]);
		printf("\n");
	}

	void add(const BigNum &x) {
		if (x.d.size() > d.size()) d.resize(x.d.size());
		for (int i = 0; i < x.d.size(); i++)
			d[i] += x.d[i];
		fix();
	}

	void sub(const BigNum &x) {
		for (int i = 0; i < x.d.size(); i++)
			d[i] -= x.d[i];
		fix();
	}

	bool operator < (const BigNum &x) const {
		if (d.size() == x.d.size()) {
			for (int i = d.size() - 1; i >= 0; i--)
				if (d[i] != x.d[i]) return d[i] < x.d[i];
		}
		return d.size() < x.d.size();
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string a, b;
	cin >> a >> b;
	bool aneg = (a[0] == '-'), bneg = (b[0] == '-');
	//
	if (!aneg && !bneg) {
		// a > 0 && b > 0
		BigNum a_num(a), b_num(b);
		a_num.add(b_num);
		a_num.to_str();
	} else if (aneg && !bneg) {
		// a < 0 && b > 0
		a = a.substr(1, a.length()-1);
		BigNum a_num(a), b_num(b);
		if (a_num < b_num) {
			b_num.sub(a_num);
			b_num.to_str();
		} else {
			a_num.sub(b_num);
			printf("-"); a_num.to_str();
		}
	} else if (!aneg && bneg) {
		// a > 0 && b < 0
		b = b.substr(1, b.length()-1);
		BigNum a_num(a), b_num(b);
		if (b_num < a_num) {
			a_num.sub(b_num);
			a_num.to_str();
		} else {
			b_num.sub(a_num);
			printf("-"); b_num.to_str();
		}
	} else {
		// a < 0 && b < 0
		a = a.substr(1, a.length()-1);
		b = b.substr(1, b.length()-1);
		BigNum a_num(a), b_num(b);
		a_num.add(b_num);
		printf("-"); a_num.to_str();
	}
	return 0;
}
