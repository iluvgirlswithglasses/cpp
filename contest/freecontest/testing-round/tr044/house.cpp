
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Feb 21 08:06:59 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 1e5+7;
int n, a, mx, ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	while (n--) {
		cin >> a;
		ans = max(ans, mx - a);
		mx = max(mx, a);
	}
	if (ans <= 0)
		cout << "Lo nang roi!\n";
	else
		cout << ans << "\n";
	return 0;
}
