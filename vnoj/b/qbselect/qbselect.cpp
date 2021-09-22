#include <iostream>
using namespace std;

/*
1000, 1010, 1001, 0100, 0101, 0010, 0001, 0000
*/
const char bits[] = {8, 10, 9, 4, 5, 2, 1, 0};
const int B = sizeof(bits);	// / sizeof(bits[0]);
const int N = 1e4+7, I = 3e4+7;

int n, a[5][N], dp[11][N];	// dp[max(bits)+1][N];
int maxx = -I;	// max(a[i][j]);

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			maxx = max(maxx, a[i][j]);
		}
	}
	//
	
	return 0;
}
