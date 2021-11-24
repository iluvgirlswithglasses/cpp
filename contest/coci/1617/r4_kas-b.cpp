
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Nov 24 12:14:49 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define pi pair<int, int>
#define st first
#define nd second
const int N = 15;

int n, a[N];
vector<pi> res;

void recursion(vector<int>& st) {
	if (st.size() == n) {
		vector<int> s(3, 0);
		for (int i = 0; i < st.size(); i++)
			s[st[i]] += a[i];
		if (s[0] == s[1]) {
			res.push_back({s[0], s[2]});
		}
	} else {
		for (int i = 0; i < 3; i++) {
			st.push_back(i);
			recursion(st);
			st.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> st;
	recursion(st);
	pi p = *max_element(res.begin(), res.end());
	cout << p.st + p.nd << "\n";
	return 0;
}
