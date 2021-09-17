#include <iostream>
#include <algorithm>
using namespace std;

const int M = 1e6+7;
int m, n, k, a[M]; 
long long p[M];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n >> k;
	for (int i = 1; i <= m; i++)
		cin >> a[i];
	sort(a+1, a+1+m, [](int i, int j){
		return i > j;
	});
	for (int i = 1; i <= m; i++)
		p[i] = p[i-1] + a[i];
	//
	long long res = -2;
	for (int i = 1, j = i+n-1; j <= m; i++, j++) {
		if (a[i] - a[j] <= k)
			res = max(res, p[j] - p[i-1]);
	}
	cout << res << "\n";
	return 0;
}
