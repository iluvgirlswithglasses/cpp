
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Jul 21 19:13:32 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <map>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<const int, int>
#define st first
#define nd second

const int N = 1e5+7;
int n, m, r[N];
map<int, int> l;	// l[i]: id of tour that start at city `i`

void calc() {
	for (int i = 1; i <= n; i++) {
		map<int, int>::iterator j = l.upper_bound(r[i]);
		if (j != l.end()) {
			cout << "YES\n";
			cout << i << " " << j->nd << "\n";
			return;
		}
	}
	//
	cout << "NO\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		int a; cin >> a >> r[i];
		l[a] = i;
	}
	calc();
	return 0;
}
