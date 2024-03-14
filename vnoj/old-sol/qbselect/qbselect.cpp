
/**
 * WARNING:
 * 
 * This code is the embodiment of terror
 * Proceed with preparation
 * */

#include <iostream>
using namespace std;

/*
1000, 1010, 1001, 0100, 0101, 0010, 0001, 0000
*/
const int bits[] = {8, 10, 9, 4, 5, 2, 1, 0};
const int B = sizeof(bits) / sizeof(bits[0]);
const int N = 1e4+7, I = 3e4+7;

int n, a[5][N], dp[8][N];
int maxx = -I;	// max(a[i][j]);

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 1; j <= n; j++) 
		{
			cin >> a[i][j];
			maxx = max(maxx, a[i][j]);
		}
	}
	if (maxx <= 0) 
	{
		cout << maxx << "\n";
		return 0;
	}
	//
	for (int j = 1; j <= n; j++) 
	{
		for (int _b=0, b=bits[0]; _b < B; b=bits[++_b]) 
		{
			for (int i = 0; i < 4; i++) if (b>>i&1)
				dp[_b][j] += a[i][j]; 
			//
			int crbest = -I;
			for (int _c=0, c=bits[0]; _c < B; c=bits[++_c]) 
			{
				if ((c|b) == (c^b)) 
					crbest = max(crbest, dp[_c][j-1]);
			}
			dp[_b][j] += crbest;
		}
	}
	//
	int res = -I;
	for (int i = 0; i < 8; i++) 
		res = max(res, dp[i][n]);
	cout << res << "\n";
	return 0;
}
