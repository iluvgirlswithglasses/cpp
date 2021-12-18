
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Dec 18 23:53:27 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int I = 5e5+7;
int q;
int arr[I], n;
int com[I][3], m;
int to[I];

int get(int i) {
	if (to[i] == 0 || to[i] == i) return i;
	to[i] = get(to[i]);
	return to[i];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> q;
	for (int i = 0; i < q; i++) {
		int t; cin >> t;
		if (t == 1) {
			cin >> arr[n++];
		} else {
			com[++m][0] = n;
			cin >> com[m][1] >> com[m][2];
		}
	}
	//
	for (int i = m; i > 0; i--) {
		int l = com[i-1][0], r = com[i][0];
		int x = com[i][1], y = com[i][2];
		if (get(y) != x)
			to[x] = get(y);
		else
			to[x] = x;
		for (int j = l; j < r; j++) {
			arr[j] = get(arr[j]);
		}
	}
	//
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "\n";
	return 0;
}
