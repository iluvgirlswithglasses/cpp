
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 12 22:27:47 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long

struct Person {
	int x, y, d, id;

	bool operator < (const Person &p) const {
		if (d == p.d)
			return id < p.id;
		return d < p.d;
	}
};

Person quickPerson(int d) {
	Person p;
	p.d = d;
	return p;
}

const int N = 2e5+7;
int n;
Person p[N];

int calc() {
	vector<Person> positive;
	set<Person> negative;
	int zeroCnt = 0;
	for (int i = 0; i < n; i++) {
		Person &k = p[i];
		k.id = i;
		k.d = k.y - k.x;
		if (k.d > 0)
			positive.push_back(k);
		else if (k.d < 0)
			negative.insert(k);
		else
			zeroCnt++;
	}
	//
	int res = 0;
	for (Person &k: positive) {
		// k.d + l.d >= 0 --> l.d >= -k.d
		if (negative.size()) {
			set<Person>::iterator it = negative.lower_bound(quickPerson(-k.d));
			if (it != negative.end()) {
				res++;
				negative.erase(it);

			} else {
				zeroCnt++;
			}
		} else {
			// being positive but can't carry anyone
			// --> becomes zero
			zeroCnt++;
		}
	}
	res += zeroCnt/2;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++) cin >> p[i].x;
		for (int i = 0; i < n; i++) cin >> p[i].y;
		cout << calc() << "\n";
	}
	return 0;
}
