
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Dec  4 20:59:51 2021
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

const int I = 1e9+7;
const int N = 3e5+7;
#define pi pair<int, int>
#define st first
#define nd second

int n, d[N], req[2], cur[2];
bool a[N];

void getinp() {
	pi* arr = new pi[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].st >> arr[i].nd;
	}
	sort(arr, arr+n);
	for (int i = 0; i < n; i++) {
		d[i] = arr[i].st;
		a[i] = arr[i].nd-1;
	}
	delete[] arr;
}

bool check() {
	return cur[0] >= req[0] && cur[1] >= req[1];
}

int calc() {
	int res = I;
	//
	for (int l = 0, r = 0; r < n; r++) {
		cur[a[r]]++;
		while (check()) {
			res = min(res, d[r] - d[l]);
			cur[a[l++]]--;
		}
	}
	//
	if (res == I) return -1;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> req[0] >> req[1];
	getinp();
	//
	cout << calc() << "\n";
	return 0;
}
