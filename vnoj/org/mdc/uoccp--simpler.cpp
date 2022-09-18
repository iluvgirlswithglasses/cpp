
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Sep 18 23:41:43 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// đây là bài làm học hỏi từ Kither
// còn đây mới là bài làm AC của tui: https://oj.vnoi.info/src/1525629

#include <iostream>
#include <set>
#include <cmath>
using namespace std;

#define ll long long
ll n;
set<ll> s;

bool isSqr(ll x) {
	ll y = sqrt(x);
	return y*y == x;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (ll i = 1; i*i*i <= n; i++) if (n % i == 0) {
		ll x = n/i;
		if (isSqr(x)) s.insert(x);
		if (x % i == 0) s.insert(i*i);
	}
	//
	if (s.size() == 1)
		cout << -1;
	else
		for (set<ll>::iterator i = ++s.begin(); i != s.end(); i++)
			cout << *i << " ";
	cout << "\n";
	return 0;
}
