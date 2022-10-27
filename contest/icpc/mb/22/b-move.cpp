
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Oct 27 09:53:41 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const ll N = 12, I = 1e6+7;
ll m, n, s;
ll a[N], b[N];

int calc() {
	deque<pi> q;
	q.push_back({s, 0});	// {vertice, depth}
	//
	while (q.size()) {
		pi p = q.front(); q.pop_front();
		for (int i = 0; i < n; i++) {
			int v = (a[i] * p.st + b[i]) % m;
			if (v == 0)
				return p.nd + 1;
			q.push_back({v, p.nd + 1});
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n >> s;
	for (int i = 0; i < n; i++)
		cin >> a[i] >> b[i];
	cout << calc() << "\n";
	return 0;
}
