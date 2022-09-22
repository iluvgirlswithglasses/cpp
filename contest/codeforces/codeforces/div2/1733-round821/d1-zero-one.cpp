
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Sep 22 14:15:51 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
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

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e6+7, I = 1e9+7, R = 1e9+7;
int n, x, y;
string a, b;
vector<int> diff;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		diff.clear();
		cin >> n >> x >> y >> a >> b;
		for (int i = 0; i < n; i++)
			if (a[i] != b[i]) diff.push_back(i);
		int d = diff.size();
		if (d&1) {
			cout << "-1\n";
		} else if (d == 2 && diff[0] + 1 == diff[1]) {
			if ((y<<1) < x)
				cout << (y<<1) << "\n";
			else
				cout << x << "\n";
		} else {
			cout << 1ll*(d>>1)*y << "\n";
		}
	}
	return 0;
}
