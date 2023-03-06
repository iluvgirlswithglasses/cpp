
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Mar  6 13:14:47 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
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

const int N = 26;
int n, k;
string s;
int cnt[N<<1];

int calc() {
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int mn = min(cnt[i], cnt[N + i]);
		ans += mn;
		cnt[i] -= mn;
		cnt[N + i] -= mn;
	}
	//
	for (int i = 0; i < N; i++) if (cnt[i] > 0 || cnt[N + i] > 0) {
		int mx = min(k, abs(cnt[i] - cnt[N + i]) >> 1);
		k -= mx;
		ans += mx;
		if (k == 0) return ans;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n >> k >> s;
		memset(cnt, 0, sizeof(cnt));
		for (char c: s) {
			if ('a' <= c && c <= 'z') 
				cnt[c - 'a']++;
			else 
				cnt[c - 'A' + N]++;
		}
		cout << calc() << "\n";
	}
	return 0;
}
