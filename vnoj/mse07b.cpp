
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Nov 25 17:48:46 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <set>
using namespace std;

#define pi pair<int, int>
#define st first
#define nd second

set<pi> s;

void insert(int k, int p) {
	s.insert({p, k});
}

int hit_and_run(set<pi>::iterator p) {
	int k = p->nd;
	s.erase(p);
	return k;
}

int front() {
	if (s.size() == 0) return 0;
	return hit_and_run(--s.end());
}

int back() {
	if (s.size() == 0) return 0;
	return hit_and_run(s.begin());
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, a, b;
	while (cin >> t) {
		switch (t) {
			case 0:
				return 0;
			case 1:
				cin >> a >> b;
				insert(a, b);
				break;
			case 2:
				cout << front() << "\n";
				break;
			case 3:
				cout << back() << "\n";
				break;
		}
	}
	return 0;
}
