
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Jan 11 13:35:32 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
const int N = 1007;
const ll  I = 2e18;

// dp[i][j]: minimum cost to go to position `i`
// where `i` is accessed from `j`
int n;
ll a[N], dp[N][N];
// can[i][j] == true --> can access to `i` from `j`
bool can[N][N];

void init() {
	// dp[i][j] == I --> can't access i from j
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++) {
		dp[i][j] = I;
	}
	//
	dp[0][0] = 0;
	can[1][0] = true;
}

ll calc() {
	for (int i = 1; i < n; i++)
	for (int j = 0; j < i; j++) if (can[i][j]) { // can go to `i` from `j`
		int dist = i - j;
		// can go backward to `j` from `i` too
		can[j][i] = true;
		// can go to i+1 by step backward then lunge forward
		can[i+1][j] = true;
		// can go the next point which d from `i` = dist + 1
		if (i + dist + 1 < n) 
			can[i+dist+1][i] = true;
		// the cost to go to `i` from `j`
		dp[i][j] = min(
			dp[j][j + dist - 1],
			j-dist+1 >= 0 ? dp[j][j - dist + 1] : I
		) + a[i];
		// the cost to go backward to `j`
		dp[j][i] = dp[i][j] + a[j];
	}
	//
	return *min_element(dp[n-1], dp[n-1] + n);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// freopen("LOCO.INP", "r", stdin);
	// freopen("LOCO.OUT", "w", stdout);
	//
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	init();
	cout << calc() << "\n";
	return 0;
}
