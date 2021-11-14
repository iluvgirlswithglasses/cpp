
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 14 13:37:43 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
#include <set>
using namespace std;

#define ll long long
const int L = 1<<10;

int n;
ll  res, cnt[L+7];

void getnum() {
	string s; cin >> s;
	set<int> a;
	for (char c: s) a.insert(c - '0');
	//
	int bitset = 0;
	for (int i: a) bitset |= 1<<i;
	cnt[bitset]++;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) 
		getnum();
	//
	for (int i = 1; i <= L; i++) {
		// haizzz.... bị gài chỗ 2 anh giống nhau y đúc này hơi bị lâu
		// phải đổi cách làm vì anh này luôn mà
		// cnt[i] choose 2
		res += (cnt[i] * (cnt[i]-1)) >> 1;
		for (int j = 0; j < i; j++) if (i&j) {
			// 
			res += cnt[i] * cnt[j];
		}
	}
	cout << res << "\n";
	return 0;
}

