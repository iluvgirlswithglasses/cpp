
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Fri Apr 21 15:21:52 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
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

const int N = 117;
int n;
char s[N], a[N];

void gen() {
	// generate all possible strings
	a[0] = '0'; a[1] = '0';
	for (int i = 2; i < N - 2; i++)
		a[i] = a[i-2] == '0' ? '1' : '0';
}

string check(int ss) {
	string ans;
	for (int i = 0, j = ss; i < n; i++) {
		if (s[i] == a[j]) ans += a[j++];
	}
	return ans;
}

string calc() {
	string ans;
	for (int i = 0; i < 4; i++) {
		// transform `s` into `a`
		string cr = check(i);
		if (cr.length() > ans.length()) ans = cr;
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	gen();
	cin >> s;
	n = strlen(s);
	cout << calc() << "\n";
	return 0;
}
