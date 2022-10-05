
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Oct 05 15:15:43 2022
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
#include <cstdio>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e5+7, I = 1e9+7, R = 1e9+7;
int n, k;
vector<int> s;

bool strict(vector<int> &a) {
	// make sure a[i-1] <= a[i] with every a[n-k+2: n]
	for (int i = n-k+2; i < n; i++)
		if (a[i] > a[i+1]) return false;
	return true;
}

bool flex(vector<int> &a) {
	// sum( a[1:n-k+1] ) == s[n-k+1]
	int stray = n-k+1;	// number of undeterminated elements
	int sum   = a[n-k+1];
	//
	int mx_element = sum / stray;
	if (sum % stray > 0) mx_element++;
	return mx_element <= a[n-k+2];
}

bool calc() {
	vector<int> a(n+2, 0);
	a[n+1] = I;
	for (int i = n; i >= n-k+1; i--)
		a[i] = s[i] - s[i-1];
	return strict(a) && flex(a);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n >> k;
		s.assign(n+2, 0);
		for (int i = 1; i <= k; i++)
			cin >> s[n-k+i];
		if (calc())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
