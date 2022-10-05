
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Oct 05 14:29:54 2022
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

const int N = 1e5+7, I = 1e9+7, R = 1e9+7;
int  n;
bool t[N];

ll pyfirst(vector<int> &pyro, vector<int> &cryo) {
	// pyro.size() >= cryo.size()
	ll res   = pyro[0];
	int diff = pyro.size() - cryo.size();
	// 
	for (int i: cryo) 
		res += i<<1;
	for (int i = pyro.size()-1; i >= max(1, diff); i--)
		res += pyro[i]<<1;
	for (int i = 1; i < diff; i++)
		res += pyro[i];
	return res;
}

ll crfirst(vector<int> &pyro, vector<int> &cryo) {
	// pyro.size() >= cryo.size()
	ll res   = cryo[0];
	int diff = pyro.size() - cryo.size();
	//
	for (int i = 1; i < cryo.size(); i++)
		res += cryo[i]<<1;
	for (int i = pyro.size()-1; i >= diff; i--)
		res += pyro[i]<<1;
	for (int i = 0; i < diff; i++)
		res += pyro[i];
	return res;
}

ll sum(vector<int> &v) {
	ll res = 0;
	for (int i: v) res += i;
	return res;
}

ll calc(vector<int> &pyro, vector<int> &cryo) {
	// pyro.size() >= cryo.size()
	if (cryo.size() == 0)
		return sum(pyro);
	return max(pyfirst(pyro, cryo), crfirst(pyro, cryo));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> t[i];
		vector<int> pyro;
		vector<int> cryo;
		for (int i = 0; i < n; i++) {
			int a; cin >> a;
			if (t[i] == 0) pyro.push_back(a);
			if (t[i] == 1) cryo.push_back(a);
		}
		sort(all(pyro));
		sort(all(cryo));
		if (pyro.size() < cryo.size())
			cout << calc(cryo, pyro) << "\n";
		else
			cout << calc(pyro, cryo) << "\n";
	}
	return 0;
}
