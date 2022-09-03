
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Sep  2 11:53:14 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second
const int N = 1e5+7, C = 36;
int n, s[N], cnt[C][N];
char t[N];

void inp() {
	cin >> n >> (t+1);
	for (int i = 1; i <= n; i++) {
		if ('0' <= t[i] && t[i] <= '9')
			s[i] = t[i] - '0';			// num:  [0:10)
		if ('a' <= t[i] && t[i] <= 'z')
			s[i] = t[i] - 'a' + 10;		// char: [10:36)
	}
}

bool check(int l, int r) {
	bool flag = false;
	for (int c = 0; c < C; c++) {
		if ((cnt[c][r] - cnt[c][l-1]) & 1) {
			if (flag) return false;
			flag = true;
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	inp();
	for (int i = 1; i <= n; i++) {
		for (int c = 0; c < C; c++) cnt[c][i] = cnt[c][i-1];
		cnt[s[i]][i]++;
	}
	//
	return 0;
}
