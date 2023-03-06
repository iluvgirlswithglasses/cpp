
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Mar  6 13:01:51 2023
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I firmly believe in the supremacy of the Euphonium
BTW I use Arch
*/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const char order[] = {'m', 'e', 'o', 'w'};
int n;
string s;

char uncap(char c) {
	if ('A' <= c && c <= 'Z') return c - 'A' + 'a';
	return c;
}

const char* calc() {
	int cr = 0;
	if (uncap(s[0]) != order[0]) return "no\n";
	for (int i = 1; i < n; i++) {
		if (uncap(s[i]) != order[cr]) {
			if (++cr == 4 || uncap(s[i]) != order[cr]) return "no\n";
		}
	}
	return cr == 3 ? "yes\n" : "no\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n >> s;
		cout << calc();
	}
	return 0;
}
