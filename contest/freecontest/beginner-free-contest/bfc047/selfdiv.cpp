
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Oct 10 21:17:26 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

void check(vector<int> &res, int i) {
	string s = to_string(i);
	for (char c: s) {
		if (c == '0' || i % (c - '0') != 0) return;
	}
	res.push_back(i);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int l, r; cin >> l >> r;
	vector<int> res;
	for (int i = l; i <= r; i++) 
		check(res, i);
	//
	cout << res.size() << "\n";
	for (int i: res) 
		cout << i << "\n";
	return 0;
}
