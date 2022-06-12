
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Jun 12 21:20:35 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
With `L=4`
I'll encode the 2-way rail to 1-way rail like this:
	`arr[2*L] = {0 1 2 3 4 3 2 1}`
So that at `T=k`, the train should be at station `arr[k]`;

Position of station X in arr: `X` and `2*L - X`
*/

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long

const int N = 3e5+7;
ll  n, l, l2, st[N], ti[N];
ll  cost = 0;
ll  neko = 0;
ll  curr = 0;

ll secondx(ll x) {
	if (x == 0) return x;
	return l2 - x;
}

ll forward(ll to) {
	ll cost = 0;
	if (curr <= to) {
		cost = to - curr;
		curr = to;
	} else if (curr <= secondx(to)) {
		cost = secondx(to) - curr;
		curr = secondx(to);
	} else {
		cost = l2 - curr + to;
		curr = to;
	}
	return cost;
}

void calc() {
	for (int i = 0; i <= n; i++) {
		// ll oldcost = cost;
		// cout << "from:" << curr << " neko:" << neko << " drop:" << st[i] << " wait:" << ti[i];
		cost += forward(neko);			// time for catching neko
		cost += forward(st[i]);			// time for moving to next shop
		neko = st[i];					// neko is now at the next shop
		cost += ti[i];					// time for shopping
		curr = (curr + ti[i]) % l2;		// the train's position after neko's finished shopping
		// cout << " cost:" << cost - oldcost << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> l;
	l2 = l<<1;
	for (int i = 0; i < n; i++)
		cin >> st[i];
	for (int i = 0; i < n; i++)
		cin >> ti[i];
	st[n] = 0;
	ti[n] = 0;
	//
	calc();
	cout << cost << "\n";
	return 0;
}
