
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Apr 21 16:14:08 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

#include <iostream>
#include <set>
#include <deque>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

multiset<int> s;
deque<int> q;

void q_add(int v) {
	q.push_back(v);
}

int q_pop() {
	if (s.size()) {
		set<int>::iterator i = s.begin();
		int ans = *i;
		s.erase(i);
		return ans;
	} else {
		int ans = q.front();
		q.pop_front();
		return ans;
	}
}

void q_sort() {
	while (q.size()) {
		s.insert(q.front());
		q.pop_front();
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q; cin >> q;
	while (q--) {
		int t, v; cin >> t;
		switch (t) {
		case 1:
			cin >> v; q_add(v);
			break;
		case 2:
			cout << q_pop() << "\n";
			break;
		case 3:
			q_sort();
			break;
		}
	}
	return 0;
}
