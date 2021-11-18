
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Nov 18 20:44:04 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
     01  02  03  04  05  06  07  08  09  10  11  12  13  14  15  16  17  18  19  20  
 1   __
 2       __
 3       __  __
 4   __      __  __
 5   __      __  __  __
 6   __          __  __  __
 7   __          __  __  __  __
 8   __              __  __  __  __
 9   __              __  __  __  __  __
 10  __                  __  __  __  __  __
 11  __                  __  __  __  __  __  __
 12  __      __              __  __  __  __  __  __
 13  __      __              __  __  __  __  __  __  __
 14  __      __                  __  __  __  __  __  __  __
 15  __      __                  __  __  __  __  __  __  __  __
 16  __      __  __                  __  __  __  __  __  __  __  __
 17  __      __  __                  __  __  __  __  __  __  __  __  __
 18  __      __  __                      __  __  __  __  __  __  __  __  __
 19  __      __  __                      __  __  __  __  __  __  __  __  __  __
 20  __      __  __  __                      __  __  __  __  __  __  __  __  __  __

*/

#include <iostream>
using namespace std;

int calc(int n) {
	int cnt = 0;
	//
	while (n > 0) {
		int to = n>>1;
		cnt += n - to;
		n = to>>1;
	}
	//
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		cout << calc(n) << "\n";
	}
	return 0;
}

