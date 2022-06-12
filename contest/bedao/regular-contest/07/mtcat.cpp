
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Jun 12 11:56:52 2022
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

const int N = 1e6+7;
int n, h[N], jp[N], r[N];
vector<int> q;	// stack núi, xếp theo giảm dần

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> h[i];
	for (int i = 0; i < n; i++) cin >> jp[i];
	// r[n-1] = -1;
	//
	for (int i = n-1; i >= 0; i--) {
		// q[] không được phép tồn tại phần tử <= h[i]
		while (!q.empty() && q.back() <= h[i]) q.pop_back();
		// còn đủ núi cho nhảy không
		if (q.size() < jp[i]) 
			r[i] = -1;
		else 
			r[i] = q[q.size() - jp[i]];
		//
		q.push_back(h[i]);
	}
	for (int i = 0; i < n; i++)
		cout << r[i] << " ";
	cout << "\n";
	return 0;
}
