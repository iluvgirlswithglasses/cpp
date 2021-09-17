#include <math.h>
#include <iostream>
using namespace std;

/**
 * vars
 * */
const int nlim = 1e6;
const int klim = 21;	// k should be >= log(n) + 1
int n, k, plog[nlim+1];
// st[i][j] chứa giá trị min trong khoảng
// arr[i] đến arr[i + (1<<j) - 1]
int st[nlim][klim+1];

/**
 * sparse table
 * */
void build() {
	// tính trước các giá trị của log
	plog[1] = 0;
	for (int i = 2; i <= n; i++) {
		plog[i] = plog[i/2] + 1;
	}
	// dữ liệu vào
	for (int i = 0; i < n; i++) cin >> st[i][0];
	// quy hoạch động
	// chia 	[i; i + (1<<j) - 1] 				size (1 << j)
	// thành	[i; i + (1<<(j-1)) - 1] 			size (1 << (j-1))
	// và 		[i + (1<<(j-1)); i + (1<<j) - 1]	size (1 << (j-1))
	int k = ceil(log(n)) + 1;
	for (int j = 1; j <= k; j++) {
		for (int i = 0; i + (1<<j) <= n; i++) {
			st[i][j] = min(
				st[i][j-1],
				st[i + (1<<(j-1))][j-1]
			);
		}
	}
}

int query(int l, int r) {
	int j = plog[r - l + 1];
	// [l; r] 	= [l; l + (1<<j) - 1] giao [r - (1<<j) + 1; r];
	return min(
		st[l][j],
		st[r - (1<<j) + 1][j]
	);
}

/**
 * drivers
 * */
int main() {
	int q; cin >> q;
	cin >> n;
	build();
	//
	while (q--) {
		int l, r; cin >> l >> r;
		cout << query(l, r) << endl;
	}
	//
	system("pause");
	return 0;
}

