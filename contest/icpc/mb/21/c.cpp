
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct 08 14:54:34 2022
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

int calc(string &s) {
	s = "1" + s + "1";
	int res = 0;
	for (int l = 0, r = 2; r < s.length(); l++, r++) {
		if (s[l] == '1' && s[l+1] == '1' && s[l+2] == '1') res++;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		string s; cin >> s;
		cout << calc(s) << "\n";
	}
	return 0;
}
