
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Dec  4 11:39:54 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
done: 12:01pm (22mins)
*/

#include <iostream>
#include <set>
using namespace std;

#define pi pair<int, int>
#define st first
#define nd second
#define mkpair make_pair

const int N = 1e3+7, K = 102;
int n, k, a[N][K];
set<pi> s;

int org[K], wincnt;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// freopen("SUPERSCH.INP", "r", stdin);
	// freopen("SUPERSCH.OUT", "w", stdout);
	//
	cin >> n >> k;
	n--;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < k; j++)
		cin >> a[i][j];
	for (int i = 0; i < k; i++) {
		int x; cin >> x;
		s.insert(mkpair(x, i+1));
	}
	//
	for (int i = 0; i < k; i++) {
		int mi = a[0][i];
		for (int j = 1; j < n; j++)
			mi = min(mi, a[j][i]);
		//
		set<pi>::iterator p = s.lower_bound(mkpair(mi, 0));
		if (p != s.begin()) {
			p--;
			wincnt++;
			org[i] = p->nd;
			s.erase(p);
		}
	}
	//
	cout << wincnt << "\n";
	for (int i = 0; i < k; i++) {
		if (org[i] > 0) {
			cout << org[i] << " ";
		} else {
			cout << s.begin()->nd << " ";
			s.erase(s.begin());
		}
	}
	cout << "\n";
	return 0;
}
