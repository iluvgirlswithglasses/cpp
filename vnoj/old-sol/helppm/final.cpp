#include <iostream>
using namespace std;

const int N = 504;
int m, n, k; 
int res[] = {N*N, 0, 0, 0, 0};	// {area, i0, j0, i1, j1};
long long mat[N][N];

void calc() {
	for (int l = 1; l <= n; l++) for (int r = l; r <= n; r++) {
		int high = 1, val = 0;
		for (int low = 1; low <= m; low++) {
			val += mat[low][r] - mat[low][l-1];
			//
			int pre_val = val, pre_high = high;
			while (val >= k) {
				pre_val = val, pre_high = high;
				val -= mat[high][r] - mat[high][l-1];
				high++;
			}
			if (pre_val >= k) {
				//
				int area = (low - pre_high + 1) * (l - r + 1);
				if (area < res[0]) {
					res[0] = area;
					res[1] = high, res[2] = l, res[3] = low, res[4] = r;
				}
			}
		}
	}
}

//
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++) for (int j = 1; j <= n; j++) {
		int v; cin >> v;
		mat[i][j] = mat[i][j-1] + v;
	}
	//
	calc();
	if (res[0] == N*N) {
		cout << "-1" << endl;
	} else {
		for (int i = 0; i < 5; i++) cout << res[i] << " "; cout << endl;
	}
	return 0;
}
