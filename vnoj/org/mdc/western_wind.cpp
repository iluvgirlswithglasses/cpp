
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

// chỉ cần nhân 10 các số lên là sẽ được làm việc với số nguyên

#define ld long double
const int N = 1e6+7;
int n;
int k, a[N], p[N];

// kiểm tra xem đáp án `t` có khả thi hay không
bool check(int t) {
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

void inp() {
	ld _k, _x;
	cin >> _k >> n;
	//
	k = _k*10;
	for (int i = 0; i < n; i++) {
		cin >> _x;
		a[i] = _x*10;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	inp();
	//
	int l = 0, r = 1e7;
	while (l < r) {
		int m = (l + r) >> 1;
		if (check(m)) 
			r = m;
		else
			l = m+1;
	}
	//
	cout << setprecision(1) << fixed << (ld) r/10.0 << "\n";
	return 0;
}
