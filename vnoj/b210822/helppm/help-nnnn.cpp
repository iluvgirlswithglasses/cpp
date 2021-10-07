#include <iostream>
using namespace std;

const int N = 504;
long long m, n, k, mat[N][N];	// mat[i][j] = sum( area(mat[1][1] -> mat[i][j]) )
long long res[5] = {300000, 0, 0, 0, 0};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
		int v; cin >> v;
		mat[i][j] = mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1] + v;
	}
	//
	for (int i0 = 1; i0 <= m; i0++) {
		for (int j0 = 1; j0 <= n; j0++) {
			for (int i1 = i0; i1 <= m; i1++) {
				for (int j1 = j0; j1 <= n; j1++) {
					int area = (i1 - i0 + 1) * (j1 - j0 + 1);
					if (area > res[0]) break;
					int s = mat[i1][j1] - mat[i1][j0-1] - mat[i0-1][j1] + mat[i0-1][j0-1];
					if (s >= k && area < res[0]) {
						res[0] = area;
						res[1] = i0, res[2] = j0, res[3] = i1, res[4] = j1;
					}
				}
			}
		}
	}
	//
	if (res[0] == 300000) {
		cout << "-1" << endl;
	} else {
		for (int i = 0; i < 5; i++) cout << res[i] << " "; cout << endl;
	}
	return 0;
}
