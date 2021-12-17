
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Dec 17 18:58:26 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
tui hoàn toàn k bik cách giải bài này dưới O(n^4)
cũng ráng submit trc khi xem sol
*/

#include <iostream>
using namespace std;

int __gcd(int a, int b) {
	if (b == 0) return a;
	return __gcd(b, a%b);
}

int gcd(int a, int b) {
	if (a > b) return __gcd(a, b);
	return __gcd(b, a);
}

const int R = 1e9;
const int N = 100;
int m, n, cr, a[N][N], f[N][N], res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n;
	//
	for (int i = 0; i < m; i++) {
		// bắt đầu ở cột 1 --> khởi động với 1 cách đi
		f[i][0] = 1;
		// cả hàng đầu trừ cột cuối
		for (int j = 0; j < n-1; j++) {
			cin >> a[i][j];
			// những ô có thể dịch chuyển đến ô này
			for (int y = 0; y <= i; y++)
			for (int x = 0; x <= j; x++)
			if  (y != i || x != j)
			if  (gcd(a[i][j], a[y][x]) != 1) {
				//
				f[i][j] += f[y][x];
				f[i][j] %= R;
			}
		}
		// riêng cột cuối
		cin >> cr;
		for (int y = 0; y <= i; y++)
		for (int x = 0; x < n-1; x++)
		if  (gcd(cr, a[y][x]) != 1) {
			res = (res + f[y][x]) % R;
		}
	}
	cout << res << "\n";
	return 0;
}
