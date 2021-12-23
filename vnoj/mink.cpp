
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Dec 23 13:12:47 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <queue>
using namespace std;

const int N = 2e4+7;
int n, k, a[N];

void calc() {
	deque<int> q;
	//
	for (int i = 0; i < n; i++) {
		while (q.size() && a[q.back()] >= a[i]) q.pop_back();
		q.push_back(i);
		if (i - q.front() + 1 > k) q.pop_front();
		//
		if (i >= k-1) {
			cout << a[q.front()] << " ";
		}
	}
	//
	cout << "\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> a[i];
		calc();
	}
	return 0;
}
