#include <iostream>
using namespace std;

const int N = 1e3+7;
// lr: số ô liên tiếp từ trái sang phải
// td: số ô liên tiếp từ trên xuống dưới
// di: diagonal dp
int m, n, lr[N][N], td[N][N], di[N][N];
int a[N][N];	// bruh, yêu cầu của qbsqr & qbrect là khác nhau

void prf(int a[][N]) {
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cout << a[i][j] << " ";
		} cout << "\n";
	}
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n;
	int best = 0;
	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j]; a[i][j]++;
			if (a[i][j] == a[i][j-1]) {
				lr[i][j] = lr[i][j-1] + 1;
			} else {
				lr[i][j] = 1;
			}
			//
			if (a[i][j] == a[i-1][j]) {
				td[i][j] = td[i-1][j] + 1;
			} else {
				td[i][j] = 1;
			}
			//
			if (a[i][j] == a[i-1][j-1]) {
				di[i][j] = min(di[i-1][j-1] + 1, min(lr[i][j], td[i][j]));
			} else {
				di[i][j] = 1;
			}
			best = max(best, di[i][j]);
	}
	// cout << "\n"; prf(lr); prf(td);
	cout << best << "\n";
	return 0;
}
