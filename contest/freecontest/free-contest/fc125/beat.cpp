
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Nov 30 14:05:22 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <cmath>
#include <stack>
using namespace std;

/*
	abc < xyz
-->	log(abc) < log(xyz)
--> log(a) + log(b) + log(c) < log(x) + log(y) + log(z)

hiển nhiên là hồi tui chưa học lớp 12, k thể nào có chuyện
tui nghĩ ra cách giải quyết này
*/

/**
 * @defs
 * */
const int N = 102, A = 102;
double lg[A];

struct pack {
	double val;
	int i, j, k;
	int x, y, z;	// pre

	void set(int a, int b, int c) {
		i = a, j = b, k = c;
	}

	void add(double x) {
		val += x;
	}

	void operator = (const pack& p) {
		val = p.val;
		x = p.i, y = p.j, z = p.k;
	}

	bool operator < (const pack& p) const {
		return val < p.val;
	}
};

/**
 * @vars
 * */
// a[i] start at 1
int n, a[3][N];
pack dp[N][N][N];

pack max(pack& a, pack& b, pack& c) {
	return max(a, max(b, c));
}

/**
 * @calc
 * */
void lcs() {
	// the only way to win this
	// is experience
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	for (int k = 1; k <= n; k++) {
		pack& ref = dp[i][j][k];
		ref.set(i, j, k);
		if (a[0][i] == a[1][j] && a[1][j] == a[2][k]) {
			ref = dp[i-1][j-1][k-1];
			ref.add( lg[a[0][i]] );
		} else {
			ref = max(
				dp[i-1][j][k],
				dp[i][j-1][k],
				dp[i][j][k-1]
			);
		}
	}
}

stack<int> backtracking() {
	stack<int> res;
	//
	for (int i = n, j = n, k = n; i > 0 && j > 0 && k > 0; ) {
		pack& cr = dp[i][j][k];
		//
		if (a[0][i] == a[1][j] && a[1][j] == a[2][k])
			res.push(a[0][i]);
		//
		i = cr.x, j = cr.y, k = cr.z;
	}
	//
	return res;
}

/**
 * @drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	for (int i = 2; i < A; i++)
		lg[i] = log(i); // base(e), not base 10 or 2
	//
	cin >> n;
	for (int i = 0; i < 3; i++)
	for (int j = 1; j <= n; j++)
		cin >> a[i][j];
	//
	lcs();
	stack<int> res = backtracking();
	cout << res.size() << "\n";
	while (res.size()) {
		cout << res.top() << " ";
		res.pop();
	}
	cout << "\n";
	return 0;
}
