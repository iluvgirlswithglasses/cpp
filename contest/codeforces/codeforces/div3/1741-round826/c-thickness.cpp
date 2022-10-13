
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Oct 13 10:11:16 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 2004;
int n, a[N];

int calc(int start, int sum) {
	int s = 0;
	int len = 0;
	for (int l = start, r = start; r < n; r++) {
		s += a[r];
		if (s > sum) 
			return n;
		if (s == sum) {
			len = max(len, r - l + 1);
			s = 0;
			l = r+1;
		}
	}
	if (s > 0) return n;
	return len;
}

int brute() {
	int res = n;
	// sum of the first segment
	int sum = 0;
	// len of the first segment
	for (int len = 1; len <= n; len++) {
		sum += a[len-1];
		res = min(
			res, max(len, calc(len, sum))
		);
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << brute() << "\n";
	}
	return 0;
}
