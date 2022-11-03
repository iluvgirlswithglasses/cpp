
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Sep 16 16:42:44 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// after more than a year... this sol comes to public

#include <algorithm>
using namespace std;

const int N = 1e6+7, R = 1e9+7;
int n, a[N], negative_cnt;

int calc() {
	long long res = 1;
	for (int i = 0; i < n; i++)
		res = (res*a[i]) % R;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < 0) negative_cnt++;
	}
	sort(a, a+n);
	//
	if (negative_cnt&1) {
		a[negative_cnt-1] = 1;
	} else {
		int *p = find(a, a+n, 0);
		if (p != a+n) *p = 1;
	}
	cout << calc() << "\n";
	return 0;
}