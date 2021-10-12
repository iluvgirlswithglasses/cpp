
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Oct 12 11:32:09 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
using namespace std;

const int N = 1e5+7;
// dp[i]: số bước nhảy tối đa có thể thực hiện khi đứng ở cột i
int n, q, a[N], dp[N];

void gendp() {
	for (int i = n-1; i >= 0; i--) {
		// tmp
		for (int j = i+1; j < n; j++) 
		if (a[i] < a[j]) {
			dp[i] = dp[j] + 1;
			break;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	gendp();
	//
	for (int i = 0; i < q; i++) {
		int v; cin >> v;
		cout << dp[v-1] << "\n";
	}
	return 0;
}

