
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 08 18:57:20 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
using namespace std;

// gọi i^2 là ước chính phương của n
// --> i <= sqrt(n)

// duyệt lần lượt từ 2 -> sqrt(n)
// độ phức tạp: O(n)
int n; 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	bool found = false;
	for (int i = 2; i*i <= n; i++) {
		if (n % (i*i) == 0) {
			cout << i*i << " ";
			found = true;
		}
	}
	//
	if (!found) cout << -1 << "\n";
	return 0;
}

