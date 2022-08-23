
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Aug 23 15:36:24 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
mấy bài dạng này thường luôn có trick
ví dụ như bài này là:
	nếu có 2n số âm thì đổi cho mớ âm đó thành dương hết
	nếu có 2n+1 số âm thì mình sẽ có thể biến đổi sao cho trên bàn chỉ còn đúng 1 số âm,
	số âm đó là số có giá trị tuyệt đối bé nhất của bàn cờ lúc đầu
*/

#include <iostream>
using namespace std;

#define ll long long
int n, m, a, mn=1e9, cnt;
ll res;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++) {
		cin >> a;
		if (a < 0) cnt++;
		res += abs(a);
		mn = min(mn, abs(a));
	}
	if (cnt&1) res -= mn<<1;
	cout << res << "\n";
	return 0;
}
