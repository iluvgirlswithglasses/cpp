
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 24 22:47:50 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <queue>
using namespace std;

int n, h;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		priority_queue<int> q;
		int a = 0, b = 0;
		cin >> n >> h;
		for (int i = 0; i < n; i++) {
			cin >> a;
			q.push(a);
		}
		a = q.top(); q.pop();
		b = q.top(); q.pop();
		//
		int turn = (h/(a+b)) << 1;
		h %= a+b;
		if (h > 0) {
			if (h > a) {
				turn += 2;
			} else {
				turn += 1;
			}
		}
		cout << turn << "\n";
	}
	return 0;
}

