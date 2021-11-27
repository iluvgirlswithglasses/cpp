
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 27 16:06:25 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define ll long long
const int N = 1e5+7;

int n, a, f[N];
int p, q[N];
ll  res;

int get(int i) {
	int r = 0;
	for (; i <= n; i+=i&-i) {
		r += f[i];
	}
	return r;
}

void upd(int i) {
	for (; i >= 1; i-=i&-i) {
		f[i]++;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a&1) {
			while (p) upd(q[--p]);
		} else {
			res += get(a+1);
			q[p++] = a;
		}
	}
	cout << res << "\n";
	return 0;
}
