
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 20 12:10:30 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <map>
using namespace std;

#define ll long long
#define st first
#define nd second
const int N = 3007;

int n, k;
ll a;
map<ll, int> dct;	// dct[i]: số số mang ước i

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a;
		ll j;
		for (j = 1; j * j < a; j++) if (a % j == 0) {
			dct[j]++;
			dct[a/j]++;
		}
		if (j * j == a) dct[j]++;
	}
	//
	for (map<ll, int>::iterator p = --dct.end(); ; --p) {
		if (p->nd >= k) {
			cout << p->st << "\n";
			break;
		}
	}
	return 0;
}

