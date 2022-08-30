
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Aug 30 20:26:47 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

/*
cơ bản là bài làm gốc (./sausage-sub.cpp) của tui
nhưng được bổ sung thêm suffix array, thay vì 1 cái prefix array đơn độc
*/

#define ll long long
const int N = 1e5+7, A = 102;
int n, a[N];
ll  pre[N][A], suf[N][A], cnt[A][A];

void gen() {
	for (int x = 1; x < A; x++) {
		for (int i = 1; i <= n; i++)
			pre[i][x] = pre[i-1][x] + (a[i] == x);
		for (int i = n; i >= 1; i--)
			suf[i][x] = suf[i+1][x] + (a[i] == x);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	gen();
	ll res = 0;
	for (int i = 1; i <= n; i++)
	for (int x = 1; x < A; x++) {
		res += suf[i+1][x] * cnt[x][a[i]];
		cnt[x][a[i]] += pre[i-1][x];
	}
	cout << res << "\n";
	return 0;
}
