
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 13 18:11:45 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
hôm nay vừa code vừa nghe nhạc Việt mình hay nghe hồi xưa
hiếm khi làm vậy, vì làm vậy năng xuất rất tệ & rất mất tập trung

nhưng mà rất chill...
có vị hoài niệm
*/

#include <iostream>
#include <algorithm>
using namespace std;

struct block {
	int h, a;

	void set(int _h, int _a) {
		h = _h, a = _a;
	}
};

const int N = 400*5+7, A = 40007;
int n, maxh;
block b[N];
bool dp[A];	// dp[i] == true --> can reach `i`

void getinp() {
	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		int h, a, c; cin >> h >> a >> c;
		maxh += h*c;
		// any integer number can be displayed in:
		// 2^x + 2^y + ... + X
		for (int i = 1; c >= i; i<<=1) {
			b[n++].set(h*i, a);
			c -= i;
		}
		if (c > 0) b[n++].set(h*c, a);
	}
	sort(b, b+n, [](block &i, block &j){
		return i.a < j.a;
	});
	maxh = min(maxh, b[n-1].a);
}

int calc() {
	dp[0] = true;
	for (int i = 0; i < n; i++) {
		for (int h = b[i].a; h - b[i].h >= 0; h--) if (dp[h - b[i].h]) {
			dp[h] = true;
		}
	}
	//
	for (int i = maxh; i >= 0; i--) {
		if (dp[i]) return i;
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	getinp();
	cout << calc() << "\n";
	return 0;
}

