
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct  8 10:08:13 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define ll long long

struct Eratos {

	static const int I = 1e6+7;

	int  n, cnt;
	int  p[Eratos::I];	// p[i] == the i-th prime, 0-indexed
	bool e[Eratos::I];	// e[i] == 0 --> `i` is prime

	void init(int _n) {
		n = _n;
		e[0] = e[1] = true;
		for (ll i = 2; i <= n; i++) if (!e[i]) {
			p[cnt++] = i;
			for (ll j = i*i; j <= n; j+=i) e[j] = true;
		}
	}
} er;

int n, h; 

int get_h(int x) {
	int res = 0;
	for (char c: to_string(x)) res += c - '0';
	return res;
}

vector<int> calc() {
	vector<int> res;
	for (int i = 0; i < er.cnt; i++)
		if (get_h(er.p[i]) == h) res.push_back(er.p[i]);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> h;
	er.init(n);
	vector<int> res = calc();
	if (res.size())
		for (int i: res) cout << i << " ";
	else
		cout << -1;
	cout << "\n";
	return 0;
}
