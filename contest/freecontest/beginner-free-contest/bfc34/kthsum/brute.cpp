#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1e3+7;
int n, k, a[N], b[N];
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	//
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v.push_back(a[i] + b[j]);
		}
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < k; i++)
		cout << v[i] << " ";
	cout << "\n";
	return 0;
}
