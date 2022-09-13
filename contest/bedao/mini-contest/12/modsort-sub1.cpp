
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Sep 13 10:46:02 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 2e5+7;
int n, k, a[N];

char* check() {
	for (int i = 0; i < n-1; i++)
		if (a[i] > a[i+1]) return "No\n";
	return "Yes\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << check();
	}
	return 0;
}
