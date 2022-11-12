
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 12 15:00:37 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 5e5+7;

// p[i]: prefix array of y[]
int n;
pi  a[N];	// {x, y}
ll  p[N], res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i].st >> a[i].nd;
	sort(a, a+n);
	p[0] = a[0].nd;
	for (int i = 1; i < n; i++)
		p[i] = p[i-1] + a[i].nd;
	// default value
	res = a[0].nd;
	// F[l, r] = p[r] - p[l-1] - x[r] + x[l]
	// --> store `- p[l-1] + x[l]`
	set<ll> s;
	s.insert(a[0].st);
	for (int r = 1; r < n; r++) {
		res = max(
			max(res, a[r].nd), 
			p[r] - a[r].st + *--s.end()
		);
		s.insert(- p[r-1] + a[r].st);
	}
	cout << res << "\n";
	return 0;
}
