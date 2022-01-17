
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Jan 17 09:36:02 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 2e3+7;

struct robot {
	int x, r, q;
};

int n, k;
robot e[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> e[i].x >> e[i].r >> e[i].q;
	//
	long long res = 0;
	for (int i = 0; i < n; i++)
	for (int j = i+1; j < n; j++) {
		if (
			abs(e[i].x - e[j].x) <= min(e[i].r, e[j].r) &&
			abs(e[i].q - e[j].q) <= k
		) {
			res++;
		}
	}
	cout << res << "\n";
	return 0;
}
