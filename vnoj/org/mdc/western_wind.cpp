
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Sep 16 20:57:06 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <iomanip>
using namespace std;

// như các bạn đã biết
// tiêu đề & cách dẫn văn của bài tập này là 1 reference đến Kither
// chúc các bạn giải bài vui vẻ

#define ld long double
const int N = 1e5+7;
int n;
ld k, a[N], p[N];

// kiểm tra xem đáp án `t` có khả thi hay không
bool check(ld t) {
	/*
	trong t giây, người lính thứ nhất sẽ chạy đến vị trí `t`

	cũng trong khoảng thời gian đó, 
	người lính tiếp sẽ đứng ở vị trí càng xa người lính đầu càng tốt, 
	nhưng vẫn phải ở trong phạm vi K
	*/
	p[0] = t;
	for (int i = 1; i < n; i++) {
		/*
		`p[i-1] + k`: phạm vi phủ sóng của người `i-1`
		còn `a[i] + t` là để phòng ngừa chuyện `k` quá lớn
		*/
		p[i] = min(a[i] + t, p[i-1] + k);
		// từ `a[i]` không thể đến `p[i]` trong thời gian `t`
		if (abs(p[i] - a[i]) > t) return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> k >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	//
	ld l = 0, r = 1e6;
	int q = 1000;
	while (q--) {
		// [l:r]
		ld m = (l+r)/2.0;
		if (check(m)) 
			r = m;
		else
			l = m;
	}
	cout << setprecision(1) << fixed << r << "\n";
	return 0;
}
