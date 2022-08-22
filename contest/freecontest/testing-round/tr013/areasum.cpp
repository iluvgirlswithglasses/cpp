
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 20 18:11:01 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define ll long long
const int N = 1e5+7;
const ll  R = 1e9+7;

int n, m, x[N], y[N];

ll f(int n, int* x) {
	ll res = 0, crosses = 0;
	for (int i = 1; i < n; i++) {
		ll d = x[i+1] - x[i];
		crosses += n - i;		// đoạn này chịu trách nhiệm thêm cho n-i đoạn
		crosses -= i - 1;		// nhưng bớt được i-1 đoạn kết thúc ở điểm trước đó
		//
		res += d * crosses;
		res %= R;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		cin >> x[i];
	for (int j = 1; j <= m; j++) 
		cin >> y[j];
	//
	ll res = (f(n, x) * f(m, y)) % R;
	cout << res << "\n";
	return 0;
}
