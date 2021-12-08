
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Dec  8 21:47:55 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
using namespace std;

const int N = 5004, I = 1e6+7, R = 1e9+7;
int trie[I][26], triecnt = 1;
bool has[I];

void insert(string& s) {
	int p = 0;
	for (char i: s) {
		int nxt = i - 'a';
		if (trie[p][nxt] == 0) 
			trie[p][nxt] = triecnt++;
		p = trie[p][nxt];
	}
	has[p] = 1;
}

/**
 * @ drivers
 * */
int n;
string s;
int dp[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	n = s.length();
	//
	int k; cin >> k;
	while (k--) {
		string tmp; cin >> tmp;
		if (tmp.length() <= n) insert(tmp);
	}
	//
	dp[0] = 1;
	for (int i = n-1; i >= 0; i--) {
		int p = 0, res = 0;
		// tới luôn cho nó dễ, recurse thì khó vcđ
		for (int j = i, nxt = s[j] - 'a'; j < n && trie[p][nxt]; nxt = s[++j] - 'a') {
			p = trie[p][nxt];
			if (has[p]) {
				res += dp[n-j-1]; res %= R;
			}
		}
		dp[n-i] = res;
	}
	//
	cout << dp[n] << "\n";
	return 0;
}
