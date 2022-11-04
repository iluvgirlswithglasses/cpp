
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Nov 04 10:44:36 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 1e6+7;

int n, q;
ll  p[N], d[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 1; i <= n; i++)
		cin >> p[i];
	sort(p+1, p+1+n, [](ll i, ll j){
		return i > j;
	});
	// make prefix sum
	for (int i = 1; i <= n; i++) {
		p[i] = p[i] + p[i-1];
		d[i] = p[i]<<1;
	}
	//
	while (q--) {
		int c, k;
		cin >> c >> k;
		
		int cnt = c / (k + 1);
		cout << d[cnt] + (p[c] - p[cnt]) << "\n";
	}
	return 0;
}
