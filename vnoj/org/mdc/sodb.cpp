
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Sep 20 10:14:37 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int __gcd(int a, int b) {
	if (b == 0) return a;
	return __gcd(b, a%b);
}

int gcd(int a, int b) {
	if (a < b) swap(a, b);
	return __gcd(a, b);
}

int n, m;
vector<int> a, b;

vector<int> calc() {
	vector<int> res = {m};
	for (int i = 2; i * i <= m; i++) if (m % i == 0) {
		res.push_back(i);
		if (i * i != m) res.push_back(m / i);
	}
	sort(res.begin(), res.end());
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			b.push_back(abs(a[i] - a[j]));
	//
	m = b[0];
	for (int i: b) m = gcd(m, i);
	//
	if (m > 1) {
		for (int i: calc())
			cout << i << " ";
		cout << "\n";
	} else {
		cout << "-1\n";
	}
	return 0;
}
