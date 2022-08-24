
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Aug 24 18:48:31 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define u32 unsigned int

/*
Giả sử cho P = 3000, X = 2100
Ông nào tham lam mệnh giá từ trên xuống, thối cho ngta 2100 + 500 + 200 + 200 thì chết

Các mệnh giá tiền mặc định thì luôn tham lam được

Có X vô thì đ, phải trâu thôi
*/

const u32 v[] = {50000, 20000, 10000, 5000, 2000, 1000, 500, 200, 100, 50, 20, 10, 5, 2, 1, 0};
u32 x, p;

u32 get(u32 x) {
	u32 res = 0;
	for (u32 i = 0; x > 0; i++) {
		res += x / v[i];
		x %= v[i];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> x;
	while (cin >> p) {
		// không bao giờ cần quá 60000 tờ X
		u32 mn = 1e9+7;
		for (u32 i = 0; i < 60000 && i*x <= p; i++) {
			mn = min(mn, i + get(p - i*x));
		}
		cout << mn << " ";
	}
	cout << "\n";
	return 0;
}
