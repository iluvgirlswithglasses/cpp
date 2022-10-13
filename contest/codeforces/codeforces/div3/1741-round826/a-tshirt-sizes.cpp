
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Oct 13 09:42:00 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
#include <map>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

map<char, int> val = {
	{'S', 0}, {'M', 1}, {'L', 2},
};

char compare(int x, int y) {
	if (x < y) return '<';
	if (x > y) return '>';
	return '=';
}

char compare(string a, string b, int n, int m) {
	if (a[n-1] != b[m-1])
		return compare(val[a[n-1]], val[b[m-1]]);
	if (a[n-1] == 'L')
		return compare(a.length(), b.length());
	if (a[n-1] == 'S')
		return compare(b.length(), a.length());
	return '=';	// M
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		string a, b;
		cin >> a >> b;
		cout << compare(a, b, a.length(), b.length()) << "\n";
	}
	return 0;
}
