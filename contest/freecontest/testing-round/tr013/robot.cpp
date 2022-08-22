
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 20 15:44:12 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// giả sử đặt robot ở vị trí m
// --> các ô trong khoảng [m-l, m+r] fải trống
int n, m, k, l, r, res;
vector<int> f;

void get_lr() {
	int a, x = 0;
	for (int i = 0; i < m; i++) {
		cin >> a;
		if (a == 1) x--;
		if (a == 2) x++;
		//
		l = max(l, -x);
		r = max(r, +x);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> k;
	get_lr();
	f.resize(k);
	for (int i = 0; i < k; i++) 
		cin >> f[i];
	f.push_back(0); 
	f.push_back(n+1);
	sort(f.begin(), f.end());
	//
	for (int i = 0; i < f.size()-1; i++) {
		int start = f[i]+l+1;
		if (start + r >= f[i+1]) continue;
		res += f[i+1] - start - r;
	}
	cout << res << "\n";
	return 0;
}
