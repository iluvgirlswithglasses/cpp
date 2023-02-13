
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Feb 13 14:06:13 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// i've comeback !

#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 3e5+7;

int n;
char s[N];
ll cr = 1, ans = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	for (int i = 1; i <= n; i++) {
		if (s[i] == s[i-1]) {
			cr++;
		} else {
			ans += cr * (cr - 1) >> 1;
			cr = 1;
		}
	}
	cout << ans << "\n";
	return 0;
}
