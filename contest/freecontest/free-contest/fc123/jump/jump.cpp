
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Oct 12 11:59:02 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <queue>
using namespace std;

const int N = 1e5+7, I = 1e9+7;
// dp[i]: số bước nhảy tối đa có thể thực hiện khi đứng ở cột i
int n, q, a[N], dp[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	//
	deque<int> dq;
	dq.push_back(n);
	a[n] = I;
	dp[n] = -1;
	for (int i = n-1; i >= 0; i--) {
		// vì từ cột x nhảy đến cột y gần nhất
		// nên làm như thế này là ổn
		// không cần fải làm như submission 1

		// nếu bé hơn thằng đứng trước thì k bao giờ tới lượt :3
		while (a[dq.front()] <= a[i]) dq.pop_front();
		dp[i] = dp[dq.front()] + 1;
		dq.push_front(i);
	}
	//
	for (int i = 0; i < q; i++) {
		int v; cin >> v;
		cout << dp[v-1] << "\n";
	}
	return 0;
}

