
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Sep  1 23:42:16 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define all(c) c.begin(), c.end()
const int N = 22;
int n, aitoi[N];	// aitoi[a[i]] means a[i] to i

struct Team {
	int i, pt, w, l;	// w - l == GD

	bool operator == (const Team &t) const {
		return pt == t.pt && w == t.w && l == t.l;
	}

	void add(int _w, int _l) {
		w += _w, l += _l;
		if (_w > _l) pt += 3;
		if (_w == _l) pt++;
	}
} team[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1, x; i <= n; i++) {
		cin >> x;
		aitoi[x] = i;
		team[i].i = x;
	}
	for (int i = 0, a, b, x, y; i < n*(n-1); i++) {
		cin >> a >> b >> x >> y;
		team[aitoi[a]].add(x, y);
		team[aitoi[b]].add(y, x);
	}
	//
	sort(team+1, team+1+n, [](Team &a, Team &b){
		if (a.pt == b.pt) {
			if (a.w - a.l == b.w - b.l)
				return a.w > b.w;
			return a.w - a.l > b.w - b.l;
		}
		return a.pt > b.pt;
	});
	// res
	for (int i = 1; i <= n; i++) {
		if (team[i] == team[1])
			cout << team[i].i << " ";
		else
			break;
	}
	cout << "\n";
	return 0;
}
