#include <iostream>
using namespace std;

const int N = 1e5+7, R = 2111992;
int n, k, dp[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    dp[0] = 1;
    for (int i = 1; i < k + 1; i++)
    	// có thêm 1 cách so với trước
    	dp[i] = dp[i-1] + 1;
    for (int i = k + 1; i <= n; i++)
    	// số khả năng bằng tổng của:
    	
		dp[i] = (dp[i-1] + dp[i-k-1]) % R;
	//
    cout << dp[n] << endl;
    return 0;
}

