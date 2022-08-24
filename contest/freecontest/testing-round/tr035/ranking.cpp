
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Aug 24 18:08:21 2022
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

const int N = 1e5+7;
int n, a[N], mx;
bool already[N];
long long res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (!already[a[i]]) mx++;
		already[a[i]] = true;
	}
	sort(a+1, a+1+n);
	// the following forloop always reduces `mx` value by 1 at its beginning
	mx++;
	for (int i = 1; i <= n; i++) {
		if (a[i] != a[i-1]) mx--;
		res += mx;
	}
	cout << res << "\n";
	return 0;
}
