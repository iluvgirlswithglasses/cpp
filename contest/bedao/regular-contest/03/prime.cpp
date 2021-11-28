
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 28 21:04:01 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
using namespace std;

const int I = 1e6+7, K = 8;
int cnt[I];
int pre[I][K];

void eratos() {
	vector<bool> prime(I, true);
	for (int i = 2; i < I; i++) if (prime[i]) {
		//
		for (int j = i; j < I; j+=i) {
			prime[j] = false;
			cnt[j]++;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	eratos();
	for (int k = 1; k < K; k++) {
		for (int i = 2; i < I; i++) {
			pre[i][k] = pre[i-1][k] + (cnt[i] == k);
		}
	}
	int q; cin >> q;
	while (q--) {
		int a, b, k; cin >> a >> b >> k;
		int res = pre[b][k] - pre[a-1][k];
		cout << res << "\n";
	}
	return 0;
}
