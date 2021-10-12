
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Oct 12 09:20:25 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <algorithm>
using namespace std;

#define u64 unsigned long long
const int N = 1e5+7;
int n;
int* a[N];
u64 res;

void calc(int pos) {
	u64 crossings = 0;
	for (int i = 0; i < n-1; i++) {
		u64 dist = a[i+1][pos] - a[i][pos],
			loss = i,
			gain = n-1-i;
		crossings = crossings + gain - loss;
		res += dist*crossings;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		a[i] = new int[2];
		cin >> a[i][0] >> a[i][1];
	}
	//
	for (int pos = 0; pos < 2; pos++) {
		sort(a, a+n, [&](int *i, int *j){
			return i[pos] < j[pos];
		});
		calc(pos);
	}
	//
	cout << res << "\n";
	return 0;
}

