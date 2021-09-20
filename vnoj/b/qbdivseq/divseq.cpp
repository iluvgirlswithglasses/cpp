#include <iostream>
using namespace std;

const int N = 1e5+7;
int n, a[N], dp[N];

// `dp[i]` chứa phần tử lớn nhất thuộc tập thứ i
// `dp[]` giảm đơn điệu
int calc() {
	int s = 0;
	dp[s++] = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < dp[s-1]) {
			dp[s++] = a[i];
		} else {
			int l = 0, r = s-1;
			while (l < r) {
				int m = (l + r) >> 1;
				if (dp[m] <= a[i]) {
					r = m;
				} else {
					l = m+1;
				}
			}
			dp[r] = a[i];
		}
	}
	return s;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	//
	cout << calc() << "\n";
	return 0;
}
