
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Nov 30 21:43:22 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

/**
 * defs & vars
 * */
const int N = 302, I = 1e9+7;
int srclen, deslen;
string src, des;
vector<int> loc[N];	// loc[i]: { vị trí của char `i` trong src }

/**
 * dp[i][j]:
 * 
 * thời gian ngắn nhất để viết xong chữ cái thứ `i`
 * nếu chữ cái `i` có index `j` trong chuỗi `src`
 * */
int dp[N][N];	// dp[deslen][srclen]

/**
 * tools
 * */
int get(int i, int j) {
	if (
		i < 0 || j < 0 || 
		i >= deslen || j >= srclen
	) {
		return I;
	}
	return dp[i][j];
}

/**
 * drivers
 * */
/*
void debug() {
	// cout << "loc:\n";
	// for (int i = 0; i < 26; i++) {
	// 	char c = 'a' + i;
	// 	cout << c << ": ";
	// 	for (int j: loc[i]) cout << j << " ";
	// 	cout << "\n";
	// }
	cout << "dp:\n";
	for (int i = 0; i < srclen; i++) {
		for (int j = 0; j < deslen; j++) {
			if (dp[j][i] < I)
				cout << dp[j][i] << " ";
			else
				cout << "I ";
		} cout << "\n";
	}
}
*/

void init() {
	for (int i = 0; i < deslen; i++)
	for (int j = 0; j < srclen; j++) {
		dp[i][j] = I;
	}
	for (int j: loc[des[0] - 'a']) {
		dp[0][j] = 0;	// có thể bắt đầu tại những vị trí này
	}
}

void prf() {
	int res = I;
	for (int i = 0; i < srclen; i++)
		res = min(res, dp[deslen-1][i]);
	if (res > 1000000) {
		cout << -1 << "\n";
	} else {
		cout << res << "\n";
	}
}

int main() {
	// inp
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> srclen >> deslen >> src >> des;
	for (int i = 0; i < srclen; i++) {
		loc[src[i] - 'a'].push_back(i);
	}
	init();
	// viết từ chữ cái thứ 2 -> des
	for (int i = 1; i < deslen; i++) {
		for (int j = 0; j < srclen; j++) if (src[j] == des[i]) {
			dp[i][j] = min(
				get(i-1, j-1),
				get(i-1, j+1)
			) + 1;
		}
		// teleport = xài ké đồng loại
		for (int j = 0; j < srclen; j++) {
			for (int k: loc[src[j] - 'a']) {
				dp[i][j] = min(dp[i][j], dp[i][k] + abs(j - k));
			}
		}
	}
	//
	prf();
	// debug();
	return 0;
}
