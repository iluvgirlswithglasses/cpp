
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Feb 17 16:29:32 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

// basically 1e12 % 2048 == 0
// calculate 10^x / 2046 into a / b and you'll notice the pattern of `b`

#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const ll R = 1e9+9;		// prime number

string s, t;

ll head_check(string s) {
	return 0ll;
}

ll tail_check(string t) {
	return 0ll;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	if (s.length() <= 12) {
		cout << tail_check(s) << "\n";
	} else {
		t = s.substr(s.length() - 12, 12);
		s = s.substr(0, s.length() - 12);
		ll ans = head_check(s) * tail_check(t) % R;
		cout << ans << "\n";
	}
	return 0;
}
