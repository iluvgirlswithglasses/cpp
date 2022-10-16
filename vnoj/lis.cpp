
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 16 19:13:41 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 3e4+7, I = 2e9+7;
int n, a[N], dp[N];

int calc() {
	dp[0] = -I;
	dp[n-1] = I;
	//
	int p = 0;
	for (int i = 1; i <= n; i++) {
		int l = 0, r = p;
		while (l < r) {
			int m = (l + r + 1) >> 1;
			if (dp[m] < a[i])
				l = m;
			else
				r = m-1;
		}
		if (l == p)
			dp[++p] = a[i];
		else
			dp[l+1] = a[i];
	}
	return p;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	cout << calc() << "\n";
	return 0;
}
