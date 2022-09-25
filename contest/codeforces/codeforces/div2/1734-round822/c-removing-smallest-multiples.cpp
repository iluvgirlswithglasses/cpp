
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Sep 23 19:29:09 2022
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
#include <unordered_set>
#include <map>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e6+7, I = 1e9+7, R = 1e9+7;
int n;

ll calc(unordered_set<int> &s, unordered_set<int> &t) {
	// s: must delete; t: must keep
	ll res = 0;
	for (int k = 1; k <= n; k++) {
		for (int mul = 1; k * mul <= n; mul++) {
			if (t.find(k*mul) != t.end())
				break;
			//
			unordered_set<int>::iterator it = s.find(k*mul);
			if (it != s.end()) {
				res += k;
				s.erase(it);
			}
		}
		if (s.size() == 0) return res;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//
	int tt; cin >> tt;
	while (tt--) {
		string str;
		cin >> n >> str;
		unordered_set<int> s, t;
		for (int i = 0; i < n; i++)
			if (str[i] == '0') s.insert(i+1);
			else t.insert(i+1);
		cout << calc(s, t) << "\n";
	}
	return 0;
}
