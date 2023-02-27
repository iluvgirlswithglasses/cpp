
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Feb 22 16:21:35 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 2e5+7, R = 1e9+7;
int n, a[N];
vector<int> mx, mn;

void calc() {
	int l = 0, r = n - 1;
	int crmin = 1, crmax = n;
	while (l + 2 < r) {	// l + 2 == r --> there're 3 items in the segment
		if (a[l] == crmin) {
			l++;
			crmin++;
			continue;
		}
		if (a[l] == crmax) {
			l++;
			crmax--;
			continue;
		}
		if (a[r] == crmin) {
			r--;
			crmin++;
			continue;
		}
		if (a[r] == crmax) {
			r--;
			crmax--;
			continue;
		}
		// shifted by 1
		cout << l + 1 << " " << r + 1 << "\n";
		return;
	}
	cout << "-1\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		calc();
	}
	return 0;
}
