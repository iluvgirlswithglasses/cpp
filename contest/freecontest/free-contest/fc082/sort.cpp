
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Nov 29 20:27:00 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
sẽ luôn có 1 cách làm trong n thao tác
nhưng tìm cách làm trong ít hơn n thao tác như thế nào ?
*/

#include <iostream>
using namespace std;

const int N = 1e6+7;
int n, res, cr, pos[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 1, a; i <= n; i++) {
		cin >> a;
		pos[a] = i;
	}
	for (int i = 2; i <= n; i++) {
		if (pos[i] > pos[i-1])
			res = max(res, ++cr);
		else
			cr = 0;
	}
	//
	cout << n - res - 1 << "\n";
	return 0;
}
