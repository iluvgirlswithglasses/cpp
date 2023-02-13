
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Feb 13 14:15:50 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

ll __gcd(ll a, ll b) {
	if (b == 0) return a;
	return __gcd(b, a%b);
}

ll gcd(ll a, ll b) {
	if (a < b) swap(a, b);
	return __gcd(a, b);
}

const int N = 54, I = 54;
int n, m, a[N];
int cnt[I];
ll  candidates[I];

void proc(int a) {
	for (int v = 2; v * v <= a; v++) {
		if (a % v == 0) {
			cnt[v]++;
			while (a % v == 0) a /= v;
		}
	}
	if (a > 1) cnt[a]++;
}

bool check(ll cr) {
	for (int i = 0; i < n; i++)
		if (gcd(a[i], cr) == 1) return false;
	return true;
}

ll calc() {
	ll ans = 1e18+7;
	for (int msk = 1; msk < (1<<m); msk++) {
		ll cr = 1;
		for (int i = 0; i < m; i++)
			if (msk>>i&1) cr *= candidates[i];
		if (check(cr))
			ans = min(ans, cr);
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		proc(a[i]);
	}
	for (int i = 2; i < I; i++)
		if (cnt[i] > 0) candidates[m++] = i;
	//
	cout << calc() << "\n";
	return 0;
}
