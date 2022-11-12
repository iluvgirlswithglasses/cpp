
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 12 11:14:00 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

/*
gcd(a, b) == n 
--> min(b) == n

(a * b)/gcd(a, b) == n**2
--> a * b == n**3
--> a == n**2
*/

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const ll R = 1e9+7;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		ll n; 
		cin >> n; n %= R;
		ll s = n * n;
		cout << (s + n) % R << "\n";
	}
	return 0;
}
