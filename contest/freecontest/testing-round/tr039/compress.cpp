
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Nov 07 12:51:23 2022
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

string s; 

int calc() {
	for (int len = 1; len < s.length(); len++) if (s.length() % len == 0) {
		bool flag = true;
		for (int i = 0; i < len; i++) {
			for (int j = len; j < s.length(); j += len) {
				if (s[i] != s[j+i]) {
					flag = false;
					break;
				}
			}
		}
		if (flag) return len;
	}
	return s.length();
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	int len = calc();
	cout << s.length() / len << s.substr(0, len) << "\n";
	return 0;
}
