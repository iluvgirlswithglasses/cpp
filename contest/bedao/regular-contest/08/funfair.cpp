
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Aug 20 15:16:23 2022
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

#define all(c) c.begin(), c.end()
#define ll long long

const int N = 1e6+7;
const ll  I = 1e15+7;
/**
 * if a[i] < x 
 * --> divide a[] into a[:i] and a[i+1:]
 *     those dividers are stored in d[]
 * */
int n, x, y, le, ri, a[N], d[N], dcnt;
ll  res = -I;

void kadane(int l, int r) {
	bool flag = false;
	ll   s = 0;
	for (int i = l, j = l; i < r; i++) {
		s += a[i];
		if (a[i] <= y) 
			flag = true;
		if (flag && s > res) 
			res = s, le = j, ri = i;
		if (s < 0) 
			s = 0, flag = false, j = i+1;
	}
}

void reverse_kadane(int l, int r) {
	bool flag = false;
	ll   s = 0;
	for (int i = r-1, j = i; i >= l; i--) {
		s += a[i];
		if (a[i] <= y) 
			flag = true;
		if (flag && s > res) 
			res = s, le = i, ri = j;
		if (s < 0) 
			s = 0, flag = false, j = i-1;
	}
}

void calc(int l, int r) {
	kadane(l, r);
	reverse_kadane(l, r);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> x >> y;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < x) d[++dcnt] = i;
	}
	d[++dcnt] = n+1;
	for (int i = 0; i < dcnt; i++)
		calc(d[i]+1, d[i+1]);	// [l:r)
	cout << res << "\n" << le << " " << ri << "\n";
	return 0;
}
