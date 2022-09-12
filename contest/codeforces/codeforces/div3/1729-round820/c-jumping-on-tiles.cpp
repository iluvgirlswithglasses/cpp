
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 12 21:56:46 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 2e5+7;
int n;
pi a[N];

// int mincost;
vector<int> calc() {
	vector<int> res;
	for (int l = 0; l < n; l++) if (a[l].nd == 1) {
		for (int i = l; ; i++) {
			res.push_back(a[i].nd);
			if (a[i].nd == n) break;
		}
		return res;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		string s; cin >> s;
		n = s.length();
		for (int i = 0; i < n; i++)
			a[i] = {s[i] - 'a' + 1, i+1};
		if (s[0] > s[n-1])
			sort(a, a+n, [](pi &i, pi &j){
				if (i.st == j.st)
					return i.nd < j.nd;
				return i > j;
			});
		else
			sort(a, a+n);
		//
		vector<int> res = calc();
		cout << abs(s[0] - s[n-1]) << " " << res.size() << "\n";
		for (int i: res)
			cout << i << " ";
		cout << "\n";
	}
	return 0;
}
