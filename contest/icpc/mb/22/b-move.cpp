
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Oct 27 09:53:41 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const ll N = 12, I = 1e9+7;
ll m, n, s;
ll a[N], b[N];

int find() {

	return 0;
}

bool possible() {

	return false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	//
	if (possible()) {
		int cnt = 0;
		while (s > 0) {
			cnt++;
			int i = find();
			s = (s*a[i] + b[i]) % m;
		}
		cout << cnt << "\n";	
	} else {
		cout << "-1\n";
	}
	return 0;
}
