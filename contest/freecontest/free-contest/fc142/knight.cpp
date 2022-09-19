
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 19 19:59:16 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int MOV_X[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
const int MOV_Y[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int a, b, x, y;

const char* calc() {
	for (int i = 0; i < 8; i++)
		if (a + MOV_X[i] == x && b + MOV_Y[i] == y) return "Yes\n";
	return "No\n";
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> a >> b >> x >> y;
	cout << calc();
	return 0;
}
