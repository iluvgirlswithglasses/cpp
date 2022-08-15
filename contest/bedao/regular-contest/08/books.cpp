
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Aug 15 15:02:47 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second
const int N = 1e5+7;

int n, q;
bool got[N];
vector<int> req;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> q;
	while (q--) {
		int x; cin >> x;
		req.push_back(x);
	}
	for (int i = req.size()-1; i >= 0; i--) {
		if (!got[req[i]]) cout << req[i] << " ";
		got[req[i]] = true;
	}
	for (int i = 1; i <= n; i++) if (!got[i]) {
		cout << i << " ";
	}
	cout << "\n";
	return 0;
}
