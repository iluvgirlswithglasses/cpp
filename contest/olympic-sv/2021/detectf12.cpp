
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct  2 17:25:24 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define ll long long
#define pi pair<ll, ll>
#define st first
#define nd second

const int N = 1007;
int  n, f0;
int  f1cnt, f2cnt;
ll   d;
pi   p[N];
bool mark[N];
vector<pi> f1;

ll dist(ll a, ll b, ll x, ll y) {
	return (a-x)*(a-x) + (b-y)*(b-y);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> f0 >> d;
	for (int i = 0; i < n; i++)
		cin >> p[i].st >> p[i].nd;
	// f0
	d *= d;
	mark[--f0] = true;
	// f1
	for (int i = 0; i < n; i++) if (!mark[i]) {
		if (dist(p[i].st, p[i].nd, p[f0].st, p[f0].nd) < d) {
			mark[i] = true;
			f1.push_back(p[i]);
		}
	}
	// f2
	for (pi &x: f1) {
		for (int i = 0; i < n; i++) if (!mark[i]) {
			if (dist(x.st, x.nd, p[i].st, p[i].nd) < d) {
				mark[i] = true;
				f2cnt++;
			}
		}
	}
	//
	cout << f1.size() << " " << f2cnt << "\n";
	return 0;
}
