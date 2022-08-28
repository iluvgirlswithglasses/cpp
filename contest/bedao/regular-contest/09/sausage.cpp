
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Aug 28 21:34:30 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e5+7, A = 102;

/**
 * @ vars
 * 
 * nCk = (n-1)C(k-1) + (n-1)Ck
 * */
int n, a[N];	// base 1
ll  nCk[N][3];
vector<int> loc[A];	// loc[a]: các vị trí xuất hiện của a
int dp[N][A];		// dp[i][a]: số lần a xuất hiện trong khoảng [0:i]

#include <cstdio>
void debug() {

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	nCk[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		nCk[i][0] = 1;
		for (int j = 1; j <= 2; j++) {
			nCk[i][j] = nCk[i-1][j-1] + nCk[i-1][j];
		}
	}
	//
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		loc[a[i]].push_back(i);
	}
	for (int x = 1; x < A; x++)
	for (int i = 1; i <= n; i++) {
		dp[i][x] = dp[i-1][x];
		if (a[i] == x) dp[i][x]++;
	}
	//
	ll res = 0;
	for (int x = 1; x < A; x++) {
		for (int l = 0; l < loc[x].size(); l++) 
		for (int r = l+1; r < loc[x].size(); r++) 
		if (loc[x][r] - loc[x][l] > 2) {
			// for other numbers: (left:right]
			int right = loc[x][r]-1, left = loc[x][l];
			for (int y = 1; y < A; y++) {

				res += nCk[ dp[right][y] - dp[left][y] ][2];
			}
		}
	}
	cout << res << "\n";
	debug();
	return 0;
}
