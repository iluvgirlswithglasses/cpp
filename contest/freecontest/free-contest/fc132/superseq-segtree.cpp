
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Dec  5 22:50:15 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/**
 * Độ dài của mảng con luôn là n*(n+1)/2
 * --> m lớn nhất được chọn là 447
 * --> dùng segtree đếm :)))
 * 
 * O(n * sqrt(n) * 447 * log(n))
 * chetme k dc :))
 * */

#include <iostream>
using namespace std;

/**
 * @vars
 * */
const int N = 1e5+7, I = 448;
int n;
int f[I][N<<1];

void build() {
	for (int v = 1; v < I; v++)
	for (int i = n-1; i > 0; i--) {
		f[v][i] = f[v][i<<1] + f[v][i<<1|1];
	}
}

// lấy ra số có giá trị v trong khoảng [l:r)
int get(int v, int l, int r) {
	int res = 0;
	for (l+=n, r+=n; l < r; l>>=1, r>>=1) {
		if (l&1) res += f[v][l++];
		if (r&1) res += f[v][--r];
	}
	return res;
}

// kiểm tra xem đoạn [l:r) có thỏa yêu cầu hay k
bool check(int l, int r, int to) {
	for (int i = 1; i <= to; i++) {
		if (get(i, l, r) != i) return false;
	}
	return true;
}

/**
 * @drivers
 * */
// tạo trước dãy cấp số cộng 
int sigma[I];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int i = 1; i < I; i++)
		sigma[i] = sigma[i-1] + i;
	//
	cin >> n;
	for (int i = 0, a; i < n; i++) {
		cin >> a;
		if (a < I) f[a][i+n]++;
	}
	build();
	//
	int res = 0;
	for (int r = 1; r <= n; r++)
	for (int i = 1, l = r - sigma[1]; l >= 0; l = r - sigma[++i]) {
		if (check(l, r, i)) res++;
	}
	cout << res << "\n";
	return 0;
}
