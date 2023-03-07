
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Mar  7 20:39:41 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 7, I = 1e9+7, R = 1e9+7;
int n;
ll m, a[N];

ll __gcd(ll a, ll b) {
	if (b == 0) return a;
	return __gcd(b, a%b);
}

ll gcd(ll a, ll b) {
	if (a < b) swap(a, b);
	return __gcd(a, b);
}

ll lcm(ll a, ll b) {
	return a / __gcd(a, b) * b;
}

ll calc() {
	m--;
	ll pt = lcm(a[0], a[1]);
	for (int i = 2; i < n; i++) pt = lcm(pt, a[i]);
	return 1 + m / pt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	for (int t = 1; t <= tt; t++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << "Case #" << t << ": " << calc() << "\n";
	}
	return 0;
}
