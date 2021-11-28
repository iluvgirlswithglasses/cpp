
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sun Nov 28 22:09:22 2021
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

#define ll long long

struct dog {
	int y, t, i;

	bool operator < (const dog& d) {
		return y < d.y;
	}
};

const int N = 2e5+7;
int n, k;
dog a[N];
ll collisions = 0;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i].y;
		a[i].i = i;
	}
	for (int i = 0; i < n; i++)
		cin >> a[i].t;
	//
	sort(a, a+n);	// dưới lên 
	while (k--) {
		// x + 0.5
		for (int i = 0; i < n - 1; i++) {
			if (
				a[i+1].y - a[i].y == 1 && 	// cách 1m
				a[i+1].t < a[i].t 			// th trên xuống th dưới lên
			) {
				collisions++;

				a[i].t = -1;
				a[i+1].t = 1;

				a[i+1].y--;
				a[i].y++;

				swap(a[i], a[i+1]);
			}
		}
		// x + 1
		for (int i = 0; i < n; i++) {
			a[i].y += a[i].t;
		}
		for (int i = 0; i < n-1; i++) {
			if (a[i].y == a[i+1].y) {
				collisions++;
				int tmp = a[i].t;
				a[i].t = a[i+1].t;
				a[i+1].t = tmp;
				swap(a[i], a[i+1]);
			}
		}
	}
	cout << collisions << "\n";
	sort(a, a+n, [](dog& i, dog& j){
		return i.i < j.i;
	});
	for (int i = 0; i < n; i++)
		cout << a[i].y << " ";
	cout << "\n";
	return 0;
}
