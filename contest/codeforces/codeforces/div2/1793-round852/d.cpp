
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Feb 26 18:14:12 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

#include <iostream>
using namespace std;

/*
strat:

find subs that dont have 1
find subs that have 1, but dont have 2
find subs that have 1 and 2, but dont have 3
find subs that have 1 2 3, but dont have 4
...
*/

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

ll c2(ll n) { return n < 2 ? 0 : n * (n - 1) >> 1; }

/** @ vars */
const int N = 2e5+7;
int  n, a[N], b[N], aloc[N], bloc[N];
bool has[N];
ll   ans;

/** @ utils */
void without_one() {
	// choose all
	ans = 1;
	// choose only 1 element
	for (int i = 0; i < n; i++) {
		// the case where a[i] == b[i] == 1 is covered elsewhere
		if (a[i] == 1 || b[i] == 1) continue;
		ans++;
	}
	// choose the subarrays that dont have 1
	int l = aloc[1], r = bloc[1];
	if (l > r) swap(l, r);
	ans += c2(l) + c2(r-l-1) + c2(n-r-1);	// [0; l) + (l; r) + (r; n)
}

void move_cursor(int &l, int &r, int tl, int tr) {
	for (int i = tl; i < l; i++) 
		has[a[i]] = true, has[b[i]] = true;
	for (int i = r+1; i <= tr; i++) 
		has[a[i]] = true, has[b[i]] = true;
	l = min(l, tl);
	r = max(r, tr);
}

/** @ drivers */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		aloc[a[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
		bloc[b[i]] = i;
	}
	without_one();
	//
	int l = aloc[1], r = bloc[1];
	if (l > r) swap(l, r);
	for (int i = l; i <= r; i++)
		has[a[i]] = true, has[b[i]] = true;

	for (int m = 1; m < n; m++) {
		// find segments that has `1..m` but dont have `m+1`
		int nl = aloc[m+1], nr = bloc[m+1];
		if (nl > nr) swap(nl, nr);

		if (nl < l && r < nr) {
			// [l, r] inside [nl, nr]
			ans += (ll) (l - nl) * (nr - r);
			move_cursor(l, r, nl, nr);	// compulsory range [l, r] to [nl, nr]
		} else if (l < nl && nr < r) {
			// [nl, nr] inside [l, r]
			
		} else if (nr < l) {
			// [nl, nr] is on the left of [l, r]
			// --> pair any (nr, l] with [r, n)
			ans += (ll) (l - nr) * (n - r);
			move_cursor(l, r, nl, r);	// compulsory range [l, r] to [nl, r]
		} else if (r < nl) {
			// [l, r] is on the left of [nl, nr]
			// --> pair any [0, l] with [r, nl)
			ans += (ll) (l + 1) * (nl - r);
			move_cursor(l, r, l, nr);	// compulsory range [l, r] to [l, nr]
		} else {
			// [nl, nr] intersect [l, r]
			move_cursor(l, r, min(l, nl), max(r, nr));
		}
	}
	//
	cout << ans << "\n";
	return 0;
}
