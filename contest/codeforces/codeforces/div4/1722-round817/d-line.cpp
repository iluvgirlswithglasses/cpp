
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Sep 14 14:12:42 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N = 2e5+7;
// d[i]: how the sum will change if I rotate `i`
int n, d[N];
ll  sum;

void inp() {
	sum = 0;
	cin >> n;
	string s; cin >> s;
	for (int i = 0; i < n; i++) {
		int l = i, r = (n-(i+1));
		if (s[i] == 'L') {
			sum += l;
			d[i] = r - l;
		} else {
			sum += r;
			d[i] = l - r;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		inp();
		sort(d, d+n, [](int i, int j){return i > j;});
		for (int i = 0; i < n; i++) {
			sum += max(0, d[i]);
			cout << sum << " ";
		}
		cout << "\n";
	}
	return 0;
}
