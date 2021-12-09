
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Dec  9 21:46:27 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstring>
using namespace std;

/**
 * @ defs
 * */
struct pack {
	// gọi độ rực rỡ là `k`
	double k;
	int l, r;

	pack(int b, int c) {
		l = b, r = c;
	}
};

const int N = 1e5+7;
int n;
char s[N];

/**
 * @ perf
 * */
int diff, has[26];

pack calc(int d) {
	diff = 0;
	memset(has, 0, 26 * sizeof(has[0]));
	pack p(0, -1);
	//
	for (int l = 0, r = 0, c = s[r]; r < n; c = s[++r]) {
		if (has[c]++ == 0) diff++;
		while (diff > d) {
			if (--has[s[l++]] == 0) diff--;
		}
		if (diff == d && r - l > p.r - p.l) {
			p.l = l, p.r = r;
		}
	}
	//
	p.k = (double) d / (p.r - p.l + 1);
	return p;
}

/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		s[i] -= 'a';
	//
	double res = 1e9+7;
	int l, r;
	// gọi độ khác biệt là `d`
	for (int d = 1; d <= 26; d++) {
		pack p = calc(d);
		if (p.k < res) {
			res = p.k;
			l = p.l, r = p.r;
		}
	}
	cout << l+1 << " " << r+1 << "\n";
	return 0;
}
