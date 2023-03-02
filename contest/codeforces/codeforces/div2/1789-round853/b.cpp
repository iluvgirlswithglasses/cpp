
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Mar  2 16:23:13 2023
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

const int N = 1e5+7, I = 1e9+7, R = 1e9+7;
int  n, m;
char s[N];

int calc() {
	bool flag = false;
	int  cnt = 0;

	for (int l = 0, r = n-1; l < r; l++, r--) {
		if (!flag && s[l] != s[r]) {
			cnt++;
			flag = true;
		} else if (flag && s[l] == s[r]) {
			flag = false;
		}
	}

	return cnt <= 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n >> s;
		if (calc())
			cout << "Yes\n";
		else
			cout << "No\n";
	}
	return 0;
}
