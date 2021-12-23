
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Dec 23 20:09:39 2021
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

const int N = 1004;
//  f[i] = số hàng liên tiếp có cột `i` là 1
// fl[i] = x sao cho mọi f[x:i] >= f[i]
// fr[i] = x sao cho mọi f[i:x] >= f[i]
int m, n, f[N], fl[N], fr[N];

void gen_l() {
	deque<int> q;
	q.push_back(-1);
	for (int i = 0; i < n; i++) {
		while (q.size() && f[q.back()] >= f[i]) {
			q.pop_back();
		}
		if (q.size())
			fl[i] = q.back()+1;	// q.back() là số gần i nhất có f < f[i]
		else
			fl[i] = 0;
		q.push_back(i);
	}
}

void gen_r() {
	deque<int> q;
	for (int i = n-1; i >= 0; i--) {
		while (q.size() && f[q.back()] >= f[i]) {
			q.pop_back();
		}
		if (q.size())
			fr[i] = q.back()-1;
		else
			fr[i] = n-1;
		q.push_back(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int res = 0;
	cin >> m >> n;
	//
	while (m--) {
		for (int i = 0, a; i < n; i++) {
			cin >> a;
			f[i] = a==1 ? f[i]+1 : 0;
		}
		gen_l();
		gen_r();
		//
		for (int i = 0; i < n; i++)
			res = max(res, f[i] * (fr[i] - fl[i] + 1));
	}
	cout << res << "\n";
	return 0;
}
