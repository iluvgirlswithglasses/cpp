
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Dec 22 14:00:28 2022
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

/** @ vars */
const int N = 1e5+7, K = 32, I = 10, R = 1e9+7;
int n, k;
char a[N];
/*
dp[n][k][i]: 
	ways to end a `k`-len sequence with digit `i % 2`
*/
int dp[K][2];

/** @ utils */
int add(int a, int b) {
	int c = a + b;
	if (c >= R) return c - R;
	return c;
}

int sub(int a, int b) {
	int c = a - b;
	return c < 0 ? c + R : c;
}

/** @ drivers */
int calc() {
	for (int i = 0; i < n; i++) {
		int parity = (a[i] - '0') & 1;
		// merge sequences
		for (int len = k; len > 1; len--) {
			dp[len][parity] = add(dp[len][parity], add(dp[len-1][0], dp[len-1][1]));
		}
		// add a new sequence
		if (a[i] != '0') dp[1][parity] = add(dp[1][parity], 1);
	}
	return dp[k][0];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	cin >> k;
	cout << calc() << "\n";
	return 0;
}
