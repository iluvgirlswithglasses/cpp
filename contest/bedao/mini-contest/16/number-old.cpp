
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Dec 22 09:42:01 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

/**
 * @ vars
 * 
 * nCk = (n-1)C(k-1) + (n-1)Ck
 * */
const int N = 1e5+7, K = 31, R = 1e9+7;
// p[i]: how many zeros in range[0:i]
int n, k, nCk[N][K], p[N];
char a[N];

int add(int a, int b) {
	int c = a + b;
	if (c >= R) return c - R;
	return c;
}

int sub(int a, int b) {
	int c = a - b;
	return c < 0 ? c + R : c;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// @ inp
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> k;

	p[0] = a[0] == '0';
	for (int i = 1; i < n; i++)
		p[i] = p[i-1] + (a[i] == '0');

	// @ init
	nCk[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		nCk[i][0] = 1;
		for (int j = 1; j <= min(i, k); j++) {
			nCk[i][j] = add(nCk[i-1][j-1], nCk[i-1][j]);
		}
	}

	// @ cal
	int base = nCk[n][k];
	// eliminate collections starting with zero
	for (int i = 0; i <= n-k; i++)
		if (a[i] == '0') base = sub(base, nCk[n-i-1][k-1]);
	// eliminate collections ending with an odd number
	for (int i = k-1; i < n; i++)
		if ((a[i] - '0')&1) base = sub(base, nCk[i][k-1]);
	// the first and the second elimination overlap at
	// sequences beginning with 0 and ending with an odd number
	
	cout << base << "\n";

	return 0;
}
