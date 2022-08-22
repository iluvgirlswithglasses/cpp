/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Jun 22 13:27:25 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
basically... a[i] <= 100

and every customer will IMMEDIATELY buy an item if they have enough of money,
they do not wish to buy as much as they can

so... this can turn out to be much easier
*/

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e5+7;
// a[i]:		price at shop `i`
// pre[i]:		prefix sum array of a[]
// nxt[i][j]:	the next shop after `i` that has the price equal to or less than `j`
int n, q, a[N], pre[N], nxt[N][101];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		pre[i] = pre[i-1] + a[i];
	}
	// generating nxt[][]
	for (int i = n; i > 1; i--) {
		for (int j = i-1; j > 0; j--) {
			nxt[j][ a[i] ] = i;
			if (a[j] <= a[i]) break;
		}
	}
	for (int i = 1; i <= n; i++) 
		for (int j = 2; j <= 100; j++)
			if ((nxt[i][j-1] && nxt[i][j-1] < nxt[i][j]) || nxt[i][j] == 0) 
				nxt[i][j] = nxt[i][j-1];
	//
	while (q--) {
		// x: money that the customer has
		// s: the shop that the customer starts at
		int x, s, e; cin >> x >> s;
		// customer will clear all shop in range [s:e]
		e = upper_bound(pre+s, pre+1+n, x + pre[s-1]) - pre - 1;
		int cnt = e - s + 1;
		// if they can not buy all the shop on their way
		if (e < n) {
			// then they will have this much money left
			x = x + pre[s-1] - pre[e];
			// in case of the customer can not buy anything at first shop
			if (e < s) e = s;
			// just brute force to get how many shop
			// they can go from now
			// complexity for this task is O(100)
			while (x > 0) {
				if (nxt[e][x]) {
					cnt++;
					e = nxt[e][x];
					x -= a[e];
				} else {
					break;
				}
			}
		}
		// the result
		cout << cnt << "\n";
	}
	return 0;
}
