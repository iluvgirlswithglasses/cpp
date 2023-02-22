
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Feb 22 07:57:50 2023
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

const int N = 1e6+7, I = 1e9+7, R = 1e9+7;
ll a, b, n, m;

ll calc() {
	// 5 4
	// 3 1
	ll free = n / (m + 1);
	if (a <= b)
		return a * (n - free);
	// price for m + 1 potatoes
	ll am = a * m, bm = b * (m + 1);
	if (bm <= am)
		return b * n;	// there's no point going for discount
	// am < bm
	ll acnt = (n / (m + 1)) * (m + 1), bcnt = n - acnt;
	return b * bcnt + a * (acnt - free);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> a >> b >> n >> m;
		cout << calc() << "\n";
	}
	return 0;
}
