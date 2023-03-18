
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Mar 16 19:04:17 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

// usage: convert a matrix to binary

#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 12;

int n, m, h;
ll  b[N][N];

void prf(ll x) {
	for (int i = h-1; i >= 0; i--)
		cout << (x>>i&1);
	cout << " ";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> b[i][j];
			h = max(h, 64 - __builtin_clzll(b[i][j]));
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			prf(b[i][j]);
		}
		cout << "\n";
	}
	return 0;
}
