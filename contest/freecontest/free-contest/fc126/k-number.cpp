
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Dec 12 11:41:07 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cstring>
using namespace std;

/**
 * @ vars
 * */
const int N = 1e3+7;
int n, a[N];

/** 
 * @perf 
 * */
int cnt[N];

int calc(int k) {
	memset(cnt, 0, (n+1) * sizeof(cnt[0]));
	//
	for (int i = 0; i < k; i++) {
		cnt[a[i]]++;
	}
	//
	for (int i = 1; i + k <= n; i++) {
		if (cnt[a[i+k-1]] > 0) 
			cnt[a[i+k-1]]++;
		cnt[a[i-1]]--;
	}
	//
	for (int i = 1; i <= n; i++)
		if (cnt[i] > 0) return i;
	return -1;
}

/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		for (int i = 1; i <= n; i++)
			cout << calc(i) << " ";
		cout << "\n";
	}
	return 0;
}
