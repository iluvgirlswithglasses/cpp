
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Jan 17 21:42:27 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

// duyệt theo đường chéo
// giống bài trò chơi con mã
// tuần 1 bồi dưỡng thành phố

/**
 * @ vars
 * */
const int I = 3e6+7;
int h, w;
long long res;

/**
 * @ eratos
 * */
int p[I], isp[I], pcnt;

void eratos(int to) {
	for (int i = 2; i <= to; i++) if (!isp[i]) {
		p[pcnt++] = i;
		for (int j = i + i; j <= to; j+=i) isp[j] = true;
	}
	p[pcnt] = I;
}

/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> h >> w;
	if (h > w) swap(h, w);
	eratos(h+w);
	//
	for (int i = 0; p[i] <= h+w; i++) {
		int start = max(1, p[i] - w);
		int end = min(p[i]-1, h);
		res += end - start + 1;
	}
	cout << res << "\n";
	return 0;
}
