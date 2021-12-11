
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Dec 11 22:46:45 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

// dãy `n` số có tối đa `n-1` giá trị khác nhau
// với mỗi `m` số đầu liên tiếp, có thể tạo ra `n-m` == `k` giá trị khác nhau
int n, k, i;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	//
	for (i = 1; i <= n - k; i++)
		cout << i << " ";
	//
	for (i = 0; n - k + 1 + i < n - i; i++)
		cout << n - i << " " << n - k + 1 + i << " ";
	//
	if (n - k + 1 + i == n - i)
		cout << n - i;
	//
	cout << "\n";
	return 0;
}
