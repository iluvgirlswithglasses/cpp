#include <iostream>
using namespace std;

const int N = 1e3+7;
// lr: số ô liên tiếp từ trái sang phải
// td: số ô liên tiếp từ trên xuống dưới
// di: diagonal dp
int m, n, lr[N][N], td[N][N], di[N][N];

int f(int i, int j) {
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			int v; cin >> v;
			if (v) {
				lr[i][j] = lr[i][j-1]+1;
				td[i][j] = td[i-1][j]+1;
			}
	}
	// cout << "\n"; prf(lr); prf(td);
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			di[i][j] = f(i, j);
		}
	}
	return 0;
}
