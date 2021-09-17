#include <iostream>
#include <vector>
using namespace std;

#define ll long long
vector<pair<int, int>> a;

ll calc() {
	vector<int> f(4, 0);
	for (pair<int, int> e: a) {
		int c = e.first, v = e.second;
		for (int i = 3; i >= 0; i--) {
			int j = i - c;
			if (j < 0) break;
			f[i] = max(f[i], f[j] + v);
		}
	}
	return f[3];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; ll res = 0;
	//
	cin >> n;
	while (n--) {
		a.clear();
		int k; cin >> k;
		//
		vector<int> m(4, 0);
		//
		while (k--) {
			int c, v; cin >> c >> v;
			if (c == 1) {
				a.push_back({c, v});
			} else {
				m[c] = max(m[c], v);
			}
		}
		sort(a.begin(), a.end(), [](pair<int, int> i, pair<int, int> j){
			return i.second > b.second;
		});
		//
		if (m[2] > 0) a.push_back({2, m[2]});
		if (m[3] > 0) a.push_back({3, m[3]});
		res += calc();
	}
	cout << res << endl;
	return 0;
}
