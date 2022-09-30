
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Sep 30 15:48:36 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <map>
#include <set>
#include <cmath>
using namespace std;

/*
mấu chốt thứ nhất:
	trong lúc biến đổi phần tử xuất hiện nhiều lần nhất,
	chúng ta có thể rảnh tay cùng lúc thay đổi các phần tử còn lại

	do đó, bài toán suy biến thành:
		cho một dãy `m` số giống nhau, 
		hỏi tốn bao nhiêu bước để dãy trở thành `m` số riêng biệt

mấu chốt thứ 2:
	giả sử ta có `4` bước

	số cách áp dụng `4` bước này lên một số bất kỳ trong dãy 
	được biểu hiện bằng bitmask có 4 bit, ví dụ: 
		0001 (chỉ áp dụng bước 1)
		0101 (áp dụng bước 1 & 3)
		1111 (áp dụng cả 4 bước)

	mà các số trong dãy đều bằng nhau,
	do đó, với `4` bước có thể tạo ra tối đa `2^4` số riêng biệt

--> đáp án của bài toán sẽ là: 
    ceil(log2(số lần xuất hiện của số xuất hiện nhiều nhất))
*/

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<const int, int>
#define st first
#define nd second

const int N = 1e5+7;
int n;
map<int, int> m;
set<int> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		m.clear();
		s.clear();
		cin >> n;
		for (int i = 0; i < n; i++) {
			int x; cin >> x;
			m[x]++;
		}
		//
		for (pi &p: m) s.insert(p.nd);
		cout << ceil(log2(*s.rbegin())) << "\n";
	}
	return 0;
}
