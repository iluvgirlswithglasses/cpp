#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define pi pair<int, int>
#define st first
#define nd second

const int N = 1e4+7, K = 3e4+7;
// i thuộc p[k] --> có một yêu cầu bắt đầu tại t=i và kết thúc tại t=k
vector<int> p[K];
int n, k, f[K];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e; cin >> s >> e;
		p[e].push_back(s);
		k = max(k, e);
	}
	//
	for (int i = 1; i <= k; i++) {
		f[i] = f[i-1];
		for (int &j: p[i]) {
			// quy tắc:
			// với i, j là hai giá trị thời gian, i < j
			// delta t = j - i
			// chứ không phải j-i+1
			f[i] = max(f[i], f[j] + i - j);
		}
	}
	cout << f[k] << "\n";
	return 0;
}
