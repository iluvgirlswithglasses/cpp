
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Tue Sep 13 10:46:02 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define all(c) c.begin(), c.end()
#define st first
#define nd second

const int N = 2e5+7;

/*
b[i] = a[i] % k
loc[r] = { array of `i` which `a[i] % k == r` }
*/
int n, k, a[N], b[N];
map<int, vector<int>> loc;

/*
abs(a[i] - a[i+1]) % k != 0 --> b[i] != b[i+1]

there's always a way to bubble sort if I can swap every `i` and `i+1`
but if there's a pair of `i` and `i+1` which I am forbidden to swap
then a[i] must be <= a[i+1]

in this problem,
all i need to do is to check for every pair of `i` `j` where:
	- `i < j`
	- `b[i] == b[j]` (can't swap)
if all of these pair returns `a[i] <= a[j]` then it means sorting is possible
otherwise, impossible
*/

const char* check() {
	for (pair<const int, vector<int>> &r: loc) {
		int pre = 0;
		for (int i: r.nd) if (b[i] == r.st) {
			if (pre <= a[i])
				pre = a[i];
			else
				return "No\n";
		}
	}
	return "Yes\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		loc.clear();
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			b[i] = a[i] % k;
			loc[b[i]].push_back(i);
		}
		cout << check();
	}
	return 0;
}
