
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 17 19:05:00 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int n;
string s;
vector<string> a;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	n = s.length();
	for (int i = 0; i < n; i++)
		a.push_back(s.substr(i, n-i) + s.substr(0, i));
	sort(a.begin(), a.end());
	cout << a[0] << "\n" << a[n-1] << "\n";
	return 0;
}

