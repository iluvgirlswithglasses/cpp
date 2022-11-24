
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Nov 24 10:11:30 2022
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

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

int n, mn = 1, mx = 10, len;
string s[(int) 1e6+7];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	len = s[0].length();
	while (--len) {
		mn *= 10;
		mx *= 10;
	}
	mx--;
	for (int i = 0; i < n; i++)
		mn = max(mn, stoi(s[i]));
	cout << mn << " " << mx << "\n";
	return 0;
}
