
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 19 14:38:41 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const int N = 1e3;
int n, a[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	//
	int turn = 0;
	for (int it = 0; ; it++) {
		for (int i = 0; i < n; i++) {
			turn++;
			a[i] -= (turn+1)/2;
			a[(i+1) % n] += (turn+1)/2;
			if (a[i] < 0) break;
		}
		cout << "iteration " << it << ": ";
		for (int i = 0; i < n; i++) {
			cout << a[i] << " ";
		}
		cout << "\n";
		//
		if (*min_element(a, a+n) < 0) break;
	}
	return 0;
}
