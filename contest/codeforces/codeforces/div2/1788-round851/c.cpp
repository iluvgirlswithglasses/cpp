
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Wed Mar  1 17:16:54 2023
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

const int N = 2e5+7;
int n;

void calc() {
	cout << "Yes\n";

	int md = n<<1|1, mn = md - (n>>1), mx = md + (n>>1);
	int cr = mn;

	// [min; mid]
	for (int x = 1, y = mn - x; x <= n; x+=2, y-=1) {	// sum inc: +1
		cout << x << " " << y << "\n";
	}
	// (mid; max]
	for (int x = 2, y = md + 1 - x; x < n; x+=2, y-=1) {
		cout << x << " " << y << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int tt; cin >> tt;
	while (tt--) {
		cin >> n;
		if (n&1)
			calc();
		else
			cout << "No\n";
	}
	return 0;
}
