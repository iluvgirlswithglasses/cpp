
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 19 21:46:38 2022
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

int calc() {
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n >> x >> y;
		if (x != 0 && y != 0) {
			// phải có 1 số == 0, vì sẽ có ng k thắng game nào
			cout << "-1\n";
		} else {
			x = max(x, y);
			if (x == 0)
				cout << "-1\n";
			else if ((n-1) % x == 0) {
				for (int k = 0; k < (n-1)/x; k++) {
					int turn = 2 + k*x;
					for (int i = 0; i < x; i++) {
						cout << turn << " ";
					}
				}
				cout << "\n";
			} else {
				cout << "-1\n";
			}
		}
	}
	return 0;
}
