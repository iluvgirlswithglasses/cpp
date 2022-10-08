
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct  8 10:13:05 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define ll long long

const int N = 1e6+7;
int n;
ll  s[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	//
	for (int i = 1; i <= n; i++) {
		for (int j = i<<1; j <= n; j+=i) s[j] += i;
	}
	//
	bool check = false;
	for (int i = 2; i <= n; i++) {
		int j = s[i];
		if (i < j && j <= n && s[j] == i) {
			check = true;
			cout << i << " " << j << "\n";
		}
	}
	if (!check) cout << -1 << "\n";
	return 0;
}
