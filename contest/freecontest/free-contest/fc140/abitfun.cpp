
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct  8 08:29:11 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
two things I found out after 1 hour being stuck at this

first:
	(a|b) == (a^b) + (a&b)
second:
	(a|b) + (a&b) == a + b

the first one is simple, right?

the point of the second one is that: 
you add the overlapped bit to the OR operation, and that's it
*/

#include <iostream>
#include <map>
using namespace std;

#define ll long long

const int N = 1e5+7;
int n;
ll  k, a[N];

ll calc() {
	ll res = 0;
	map<ll, int> m;	// m[i]: number of `i` read
	for (int j = 0; j < n; j++) {
		/*
		call a = a[j], x = a[i]

		a^x + (a|x + a&x) == a + k
		--> a^x + a + x == a + k
		--> a^x = k - x
		--> a = (k - x)^x
		*/
		res += m[ a[j] ];
		m[ (k - a[j])^a[j] ]++;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << calc() << "\n";
	}
	return 0;
}
