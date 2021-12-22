
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Dec 22 19:54:15 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
thực lực:	https://oj.vnoi.info/submission/578749

còn code này thì... không trong sạch, vì đã liếc qua sol trước

nể khả năng tối ưu của các cao nhân thật
em kém cỏi, cùng ý tưởng nhưng không thể tối ưu được
*/

#include <iostream>
#include <set>
using namespace std;

const int N = 2e5+7;
// a[i]: power của node i
// p[i]: cha của node i
// x[i]: set mà node i đang sử dụng trong s
int n, a[N], p[N], x[N];
multiset<int> s[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i] >> p[i];
		x[i] = i;
	}
	// vì node con luôn được nhập sau node cha
	// nên duyệt kiểu này thì trước khi vào 1 node cha,
	// tất cả các node con đều đã được xử lý
	// well... sau pha này chắc em phải đi nâng cấp 
	// cục code vmsalary của em thôi
	for (int i = n; i >= 1; i--) {
		multiset<int>& cr_set     = s[ x[i] ];
		multiset<int>& parent_set = s[ x[p[i]] ];
		// thêm i vào lis
		multiset<int>::iterator pointer = cr_set.lower_bound(a[i]);
		if (pointer != cr_set.end())
			cr_set.erase(pointer);
		cr_set.insert(a[i]);
		// merge
		if (cr_set.size() > parent_set.size()) {
			cr_set.insert(parent_set.begin(), parent_set.end());
			x[p[i]] = x[i];
		} else {
			parent_set.insert(cr_set.begin(), cr_set.end());
			x[i] = x[p[i]];
		}
	}
	//
	cout << s[x[0]].size() << "\n";
	return 0;
}
