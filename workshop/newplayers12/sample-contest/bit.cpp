
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Oct 29 13:37:02 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
*/

#include <iostream>
#include <string>
using namespace std;

int res;
string s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	//
	int pre_cnt[2] = {0, 0};
	int pre_typ = s[0] - '0';
	pre_cnt[pre_typ]++;
	//
	for (int i = 1; i < s.length(); i++) {
		int a = s[i] - '0';
		if (a == pre_typ) {
			pre_cnt[a]++;
		} else {
			res = max(
				res,
				min(pre_cnt[0], pre_cnt[1]) << 1
			);
			pre_cnt[a] = 1;
		}
		pre_typ = a;
	}
	//
	res = max(
		res,
		min(pre_cnt[0], pre_cnt[1]) << 1
	);
	cout << res << "\n";
	return 0;
}
