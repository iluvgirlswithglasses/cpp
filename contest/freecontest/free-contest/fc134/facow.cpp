
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Dec 26 17:29:40 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

/*
đôi một khác nhau
a[i] <= n
--> a[i] cũng chính là rank của con bò
*/
const int N = 1e3+7;
int n, sgl, dou, res, lim, a[N], p[N];
double chose[N];

void rm(int idx, int m) {
	lim--;
	for (int i = idx; i < n; i++) {
		if (a[i] == m) chose[i] = true;
		if (a[i] >= m) a[i]--;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> sgl >> dou;
	lim = n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> p[i];
	//
	for (int i = 0; i < n; i++) if (!chose[i]) {
		int rank_j = p[i] + 1;
		if (a[i] < rank_j && rank_j <= lim) {
			res += dou;
			rm(i, rank_j);
		} else {
			res += sgl;
		}
		rm(i, a[i]);
	}
	cout << res << "\n";
	return 0;
}
