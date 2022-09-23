
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Sep 23 19:19:25 2022
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
int n;

int calc() {
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n;
		// floor 1
		cout << "1\n";
		// other floors
		for (int i = 2; i <= n; i++) {
			for (int j = 1; j <= i; j++) {
				if (j == 1) cout << "1 ";
				else if (j == i) cout << "1 ";
				else cout << "0 ";
			}
			cout << "\n";
		}
	}
	return 0;
}
