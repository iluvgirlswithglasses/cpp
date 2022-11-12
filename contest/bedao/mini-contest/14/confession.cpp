
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 12 10:38:57 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

int n, k;
string s, t;
int require[26];

bool res() {
	for (int i = k; i < (n>>1); i++)
		if (s[i] != s[n-1-i]) return false;
	//
	memset(require, 0, sizeof(require));
	for (int i = 0; i < k; i++) {
		require[t[i] - 'a']++; 
		require[s[i] - 'a']--;
	}
	for (int i = 0; i < 26; i++)
		if (require[i] != 0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n >> k >> s;
		// contruct the final string
		t = string(n, '-');
		for (int i = n>>1; i < n; i++)
			t[i] = s[i];
		for (int i = 0; i < (n>>1); i++)
			t[i] = t[n-1-i];
		//
		if (res())
			cout << "Yes\n" << t << "\n";
		else 
			cout << "No\n";
	}
	return 0;
}
