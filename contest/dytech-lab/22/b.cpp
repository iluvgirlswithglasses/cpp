
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 19 14:46:26 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 1e5+7, I = 1e9+7, R = 1e9+7;
int n, a[N];

// tại iteration thứ i, người thứ j:
// nếu `j + n*i` lẻ   --> người này k mất cái bánh nào
// nếu `j + n*i` chẵn --> mất 1 cái

int calc() {
	vector<pi> candidate;	// { iteration survived, index }
	for (int j = 0; j < n; j++) {
		if (n&1) {
			// `n` lẻ --> luân phiên
			if (j&1) {
				// vì lượt đầu không mất, nên được +1 lượt cuối
				candidate.push_back(
					{(a[j] + 1)*2 + 1, j}
				);
			} else {
				candidate.push_back(
					{(a[j] + 1)*2, j}
				);
			}
		} else {
			// `n` chẵn --> th nào có lượt k mất bánh thì vĩnh viễn k mất bánh
			//              th nào mất rồi là mất luôn
			if (!(j&1)) {
				// tank đc a[j] + 1 lượt
				candidate.push_back({a[j] + 1, j});
			}
		}
	}
	return (*min_element(all(candidate))).nd;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		cout << calc() << "\n";
	}
	return 0;
}
