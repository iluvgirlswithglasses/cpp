
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Oct 01 21:53:08 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstring>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1007, K = 52;
// dp[x][i]: độ dài của dãy dài nhất chia `k` dư `x` khi xét tới `a[i]`
int n, k, a[N], dp[K][N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	dp[0][0] = 0;
	for (int x = 1; x < k; x++)
		dp[x][0] = -N;	// or -inf
	//
	for (int i = 1; i <= n; i++) {
		for (int x = 0; x < k; x++) {
			/*
			(pre + a[i]) % k == x
			--> pre%k + a[i]%k == x || x + k
			*/
			dp[x][i] = max(
				dp[x][i-1],		// skip this
				dp[(x - (a[i]%k) + k) % k][i-1] + 1	// thêm a[i] vào, kích thước +1
			);
		}
	}
	cout << dp[0][n] << "\n";
	return 0;
}
