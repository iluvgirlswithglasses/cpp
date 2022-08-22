#include <iostream>
#include <vector>
using namespace std;

const int N = 2e5+7;
int n, a[N], dp[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	//
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		dp[a[i]]++;
	}
	//
	int minVal = N, minIndex = -1;
	for (int i = 0; i < n; i++) {
		if (dp[a[i]] == 1 && a[i] < minVal) {
			minIndex = i+1;
			minVal = a[i];
		}
	}
	//
	cout << minIndex << endl;
	return 0;
}
