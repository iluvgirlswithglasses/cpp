#include <iostream>
using namespace std;

const int N = 204, R = 1e9+7;
int n, a, arr[N];

int calc(int i, int sum, int cnt) {
    // Base case
    if (i == n) {
        if (sum == 0 && cnt > 0)
            return 1;
        else
            return 0;
    }
    int ans = 0;
    ans += calc(i + 1, sum, cnt);
    ans += calc(i + 1, sum + arr[i], cnt + 1);
    return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> a;
		for (int i = 0; i < n; i++) {
			cin >> arr[i]; arr[i] -= a;
		}
		cout << calc(0, 0, 0) << endl;
	}
	//
	return 0;
}
