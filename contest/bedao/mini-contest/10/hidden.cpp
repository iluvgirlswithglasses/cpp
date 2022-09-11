
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Sep 11 11:20:45 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
using namespace std;

#define all(c) c.begin(), c.end()
#define pi pair<const int, int>
#define st first
#define nd second
/*
if a != T:
	lcm(x, y) == T
	T % a == 0

--> lcm(lcm(x, y), a) == T
*/

const int I = 1e9+7, S2I = 31622;
int a, t, x, y;

struct Prime {
	int  p[S2I], cnt;
	bool e[S2I];	// e[i] == 0 --> e[i] is prime

	void init() {
		e[0] = e[1] = 1;
		for (int i = 2; i < S2I; i++) if (e[i] == 0) {
			p[cnt++] = i;
			for (int j = i<<1; j < S2I; j+=i) e[j] = 1;
		}
	}

	vector<int> fact(int x) {
		vector<int> res;
		for (int _i = 0, i = p[0]; i*i <= x; i = p[++_i]) {
			while (x % i == 0) {
				res.push_back(i);
				x /= i;
			}
		}
		if (x > 1) res.push_back(x);
		return res;
	}
} pr;

bool typ1() {
	vector<int> f = pr.fact(t);
	if (f.size() == 1) return false;
	x = f[0], y = 1;
	for (int i = 1; i < f.size(); i++)
		y *= f[i];
	return true;
}

bool typ2() {
	vector<int> f = pr.fact(t);
	x = 1, y = 1;
	int i = 0;
	for (; i < f.size() && f[i] == f[0]; i++)
		x *= f[i];
	if (i == f.size()) return false;
	for (; i < f.size(); i++)
		y *= f[i];
	return true;
}

bool calc() {
	if (t == a) return typ1();
	if (t % a == 0) return typ2();
	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	pr.init();
	cin >> a >> t;
	if (calc())
		cout << x << " " << y << "\n";
	else
		cout << "-1\n";
	return 0;
}
