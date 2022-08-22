
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Feb 12 16:47:55 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <set>
using namespace std;

#define ll long long
const int N = 1e5+7;
int r, c, k;
set<int> xrow, xcol;	// row and col that can't be deleted
ll row, col, rlost, clost, coli;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> r >> c >> k;
	while (k--) {
		int x, y;
		cin >> x >> y;
		xrow.insert(x-1);
		xcol.insert(y-1);
	}
	//
	for (int i = 0; i < r; i++)
		if (xrow.find(i) == xrow.end()) row++;
	for (int i = 0; i < c; i++)
		if (xcol.find(i) == xcol.end()) col++;
	//
	rlost = row * c;
	clost = col * r;
	coli  = row * col;
	cout << (ll) r * c - rlost - clost + coli << "\n";
	return 0;
}
