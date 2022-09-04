
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Sep  4 17:13:53 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, ll>
#define st first
#define nd second
#define mk make_pair

const int N = 1e5+7;
int n, k;
ll  dp[N];
deque<pi> q;	// q[i]: {index, val}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	q.push_back(mk(0, 0));
	for (int i = 1; i <= n; i++) {
		if (q.size() && i - q.front().st > k) q.pop_front();
		cin >> dp[i]; 
		if (q.front().nd > 0)
			dp[i] += q.front().nd;
		else
			q.clear();
		// q[i].nd > q[i+1].nd
		while (q.size() && q.back().nd <= dp[i]) q.pop_back();
		q.push_back(mk(i, max(dp[i], 0ll)));
	}
	cout << *max_element(dp, dp+n+1) << "\n";
	return 0;
}
