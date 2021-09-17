#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long

const int N = 1e3+7;
int n, k;
ll a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; a[i] += a[i-1];
	}
	//
	vector<ll> v;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < i; j++) {
			v.push_back(a[i] - a[j]);
		}
	}
	sort(v.begin(), v.end(), [](ll i, ll j){
		return i > j;
	});
	cout << v[k-1] << endl;
	return 0;
}
