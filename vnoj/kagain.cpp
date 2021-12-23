
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Dec 23 21:32:10 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <queue>
using namespace std;

// tác dụng của từng biến ?
// đọc trong qbrect

const int N = 3e4+7;
int n, a[N], fl[N], fr[N];

void gen_l() {
	deque<int> q;
	for (int i = 0; i < n; i++) {
		while (q.size() && a[q.back()] >= a[i])
			q.pop_back();
		//
		if (q.size())
			fl[i] = q.back()+1;
		else
			fl[i] = 0;
		q.push_back(i);
	}
}

void gen_r() {
	deque<int> q;
	for (int i = n-1; i >= 0; i--) {
		while (q.size() && a[q.back()] >= a[i])
			q.pop_back();
		//
		if (q.size())
			fr[i] = q.back()-1;
		else
			fr[i] = n-1;
		q.push_back(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int res = 0, l, r;
		//
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		gen_l();
		gen_r();
		//
		for (int i = 0; i < n; i++) {
			int cr = a[i] * (fr[i] - fl[i] + 1);
			if (cr > res) {
				res = cr;
				l = fl[i];
				r = fr[i];
			}
		}
		//
		cout << res << " " << l+1 << " " << r+1 << "\n";
	}
	return 0;
}
