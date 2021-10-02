#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 5e3+7;
int n, m;
string s, t;

int calc() {
	vector<int> f(m+1, 0), g(m+1, 0);
	for (int i = 0; i <= m; i++) 
		f[i] = i, g[i] = i;
	//
	for (int i = 1; i <= n; i++) {
		f[0] = i; 
		for (int j = 1; j <= m; j++) {
			// f[j]: tối thiểu để biến t[0:j] thành s[0:i]
			if (s[i-1] == t[j-1]) {
				f[j] = g[j-1];
			} else {
				int a[] = {g[j], g[j-1], f[j-1]};
				f[j] = 1 + *min_element(a, a+3);
			}
		}
		swap(f, g);
	}
	return g[m];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s >> t;
	n = s.length(), m = t.length();
	cout << calc() << "\n";
	return 0;
}
