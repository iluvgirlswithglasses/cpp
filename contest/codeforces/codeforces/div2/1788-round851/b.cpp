
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Mar  1 10:51:05 2023
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

const int N = 1e9+7;
string n, x, y;

void calc() {
	int len = n.length();
	x = string(len, '0');
	y = string(len, '0');
	bool carry = 0;

	for (int i = 0; i < len; i++) {
		int d = n[i] - '0';
		x[i] = (d>>1) + '0';
		y[i] = (d>>1) + '0';
		if (d&1) {
			if (carry) { x[i]++; carry ^= 1; }
			else { y[i]++; carry ^= 1; }
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n;
		calc();
		cout << stoi(x) << " " << stoi(y) << "\n";
	}
	return 0;
}
