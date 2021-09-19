#include <iostream>
#include <vector>
using namespace std;

const int N = 1e3+7;
int n, m;
vector<bool> a[N];

void brute(int cr_i, int cr_j) {
	
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		a[i].resize(m);
		for (int j = 0; j < m; j++) {
			bool k; cin >> k; 
			a[i][j] = k;
		}
	}
	return 0;
}
