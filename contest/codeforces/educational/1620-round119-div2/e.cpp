
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Dec 18 23:22:03 2021
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

/**
 * @ defs
 * */
const int I = 5e5+7;
struct command {
	// from index i, replace x with y
	int i, x, y;

	command(int _i, int _x, int _y) {
		i = _i, x = _x, y = _y;
	}
};

/**
 * @ vars
 * */
int q;
vector<int> arr;
vector<command> comm;
// to[i] == number that `i` gotta shift to
int to[I];

int get(int i) {
	if (to[i] == 0 || to[i] == i) return i;
	to[i] = get(to[i]);
	return to[i];
}

/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> q;
	comm.push_back(command(0, 0, 0));
	for (int i = 0; i < q; i++) {
		int t; cin >> t;
		if (t == 1) {
			int x; cin >> x;
			arr.push_back(x);
		} else {
			int x, y;
			cin >> x >> y;
			comm.push_back(
				command(arr.size(), x, y)
			);
		}
	}
	//
	for (int i = comm.size()-1; i > 0; i--) {
		command c = comm[i];
		int l = comm[i-1].i, r = c.i;
		to[c.x] = c.y;
		for (int j = l; j < r; j++)
			arr[j] = get(arr[j]);
	}
	//
	for (int i: arr)
		cout << i << " ";
	cout << "\n";
	return 0;
}
