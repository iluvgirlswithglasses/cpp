#include <iostream>
#include <set>
using namespace std;

const int W = 1e3+7, N = 1e4+7;
// n-items, knapsack's weight, items' size (weight), items' value, 
// value dp, items count dp, items index id
int n, w, s[N], v[N], dpv[W], dpc[W], dpi[W];

void calc() {
	for (int i = 0; i < n; i++) {
		for (int j = w; j >= 0; j--) {
			if (j - s[i] < 0) break;
			//
			int pre = j - s[i], val = dpv[pre] + v[i];
			if (val > dpv[i]) {
				dpv[j] = val;
				dpc[j] = dpc[pre] + 1;
				// dpi[j] = i;
			}
		}
	}
}

int main() {
	int t; cin >> t;
	while (t--) {
		// inp
		cin >> n >> w;
		for (int i = 0; i < n; i++) cin >> s[i];
		for (int i = 0; i < n; i++) cin >> v[i];
		// calc
		calc();
		cout << dpv[w] << " " << dpc[w] << endl;
		// print items indexes

	}
	//
	system("pause");
	return 0;
}
