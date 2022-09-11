
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Sep 11 20:34:39 2022
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
#include <algorithm>
using namespace std;

int n;
vector<int> res;

bool calc(int i) {
	int cnt = 0;
	for (int j = 0; j < 9; j++)
		if (i>>j&1) cnt += j+1;
	return cnt == n;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		res.clear();
		cin >> n;
		for (int i = 1; i < (1<<9); i++) if (calc(i)) {
			string s;
			for (int j = 0; j < 9; j++) 
				if (i>>j&1) s = s + (char) ('1' + j);
			res.push_back(stoi(s));
		}
		cout << *min_element(res.begin(), res.end()) << "\n";
	}
	return 0;
}
