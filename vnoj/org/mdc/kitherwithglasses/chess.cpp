
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Oct 23 08:16:48 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cmath>
using namespace std;

/*
k = (a * b) + ((a+1) * (b+1))
  = 2ab + a + b + 1
--> a = (k - b - 1)/(2b + 1)
*/

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const ll LIM = 1e6+7;
ll k, a, b;

ll calc(ll i, ll j) {
	return (i * j) + ((i+1) * (j+1));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> k;
	for (ll i = 1; i < LIM && i < k; i++) {
		ll j = (k - i - 1) / (i<<1|1);
		if (i > j)
			break;
		if (calc(i, j) == k && i * j > a * b) {
			b = i;
			a = j;
		}
	}
	if (a == 0 || b == 0)
		cout << "-1\n";
	else
		cout << a << " " << b << "\n";
	return 0;
}
