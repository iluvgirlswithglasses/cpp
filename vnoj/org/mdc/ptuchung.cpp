
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 26 18:34:09 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <set>

using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int I = 1e5+7;
int n, m;
bool cached[I];
set<int> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		cached[a] = true;
	}
	for (int i = 0, a; i < m; i++) {
		cin >> a;
		if (cached[a]) s.insert(a);
	}
	//
	for (int i: s) cout << i << " ";
	cout << "\n";
	return 0;
}
