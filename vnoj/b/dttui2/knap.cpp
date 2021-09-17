#include <iostream>
using namespace std;

const int N = 102, H = 12, M = 1e4+2;
int n, m, arr[N*H][2], dp[M];

void getinp() {
	int _n, w, v, a;
	cin >> _n >> m;
	for (int i = 0; i < _n; i++) {
		cin >> w >> v >> a;
		//
		for (int j = 0; a > 0; j++) {
			int cr = min(a, (1<<j));
			arr[n][0] += cr * w;
			arr[n][1] += cr * v;
			a -= cr; n++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// ifstream inp("test/inp.txt"); cin.rdbuf(inp.rdbuf());
	getinp();
	for (int i = 0; i < n; i++) {
		int w = arr[i][0], v = arr[i][1];
		for (int j = m; j > 0; j--) {
			int pre = j - w;
			if (pre < 0) break;
			dp[j] = max(dp[j], dp[pre] + v);
		}
	}
	//
	cout << dp[m] << "\n";
	return 0;
}
