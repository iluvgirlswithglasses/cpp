
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Feb 21 09:13:01 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

// kawashita yakusoku wasurenai yo
// me wo toji tashikameru
// oshiyoseta yami furiharatte susumu yo!

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

// good thing that there's no overlapping points

const int N = 1e5+7, R = 1e9+7;
int  n, m, a[N], b[N];
bool x[N<<1];

ll calc() {
	ll ans = 1;
	ll cnt[2] = {0, 0};
	cnt[x[0]]++;
	for (int i = 1; i < m; i++) {
		bool cur = x[i], tar = cur^1;
		if (cnt[tar] > 0) {
			ans = ans * cnt[tar] % R;
			cnt[tar]--;
		} else {
			cnt[cur]++;
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(a, a+n);
	sort(b, b+n);
	for (int u = 0, v = 0; u < n || v < n; ) {
		if (v == n || (u < n && a[u] < b[v])) {
			x[m++] = 0;	// computer
			u++;	
		} else {
			x[m++] = 1;	// socket
			v++;
		}
	}
	// 
	cout << calc() << "\n";
	return 0;
}
