
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Dec 24 15:13:47 2021
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

// tiếp tục ôn deque min max
const int N = 1e6+7;
int n, a[N], l[N], r[N];

void gen_l() {
	deque<int> q;
	for (int i = 0; i < n; i++) {
		while (q.size() && a[q.back()] >= a[i])
			q.pop_back();
		if (q.size())
			l[i] = q.back()+1;
		else
			l[i] = 0;
		q.push_back(i);
	}
}

void gen_r() {
	deque<int> q;
	for (int i = n-1; i >= 0; i--) {
		while (q.size() && a[q.back()] >= a[i])
			q.pop_back();
		if (q.size())
			r[i] = q.back() - 1;
		else
			r[i] = n-1;
		q.push_back(i);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	gen_l();
	gen_r();
	//
	int res = 0;
	for (int i = 0; i < n; i++)
		if (r[i] - l[i] + 1 >= a[i]) res = max(res, a[i]);
	cout << res << "\n";
	return 0;
}
