
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Sep 18 09:27:23 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define ll long long
const int R = 1e9+7;
int n, a;
ll  s, h, k;

void radd(ll &x, ll y) {
	x += y;
	if (x >= R) x -= R;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	while (n--) {
		cin >> a;
		radd(s, a);
		/*
		nếu có 1 vòng tròn lẻ 1 người, sẽ có 1 người `z` đứng giữa:
			- một người có id lớn hơn (gọi là x)
			- một người có id nhỏ hơn (gọi là y)
		--> `x - z + z - y == x - y`
		--> `z` bị thừa
		--> có thể vứt `z` ra để tạo thành vòng chẵn

		sau đó, có thể gộp tất cả các vòng chẵn này thành một vòng duy nhất
		vòng lớn này có `h` cạnh, `h` đỉnh, id cao nhất là `s`

		cuối cùng, chỉ cần tính kết quả của vòng lớn này,
		ta có được kết quả bài toán
		*/ 
		// radd(h, a&~(1));

		// để khỏi phải xử lý phép chia khi chia lấy dư thì ta cho k = h/2
		radd(k, a>>1);
	}
	// các cạnh của vòng có thể chia thành `k` cặp,
	// mỗi cặp có tổng bằng `(s-k)*2`
	ll res = (s-k+R) * k << 1;
	cout << (res % R) << "\n";
	return 0;
}
