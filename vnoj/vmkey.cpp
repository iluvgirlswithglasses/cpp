/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Dec 20 17:17:54 2021
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

// VNOI's server can handle this program, not my computer

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// cnt[i][j]:	số lần có số i đứng trước số j
int cnt[10][10];
// d[i][j]:		khoảng cách từ ô i đến ô j
int d[10][10] = {
//   0  1  2  3  4  5  6  7  8  9
	{0, 3, 4, 5, 2, 3, 4, 1, 2, 3},	// 0
	{3, 0, 1, 2, 1, 2, 3, 2, 3, 4},	// 1
	{4, 1, 0, 1, 2, 1, 2, 3, 2, 3},	// 2
	{5, 2, 1, 0, 3, 2, 1, 4, 3, 2},	// 3
	{2, 1, 2, 3, 0, 1, 2, 1, 2, 3},	// 4
	{3, 2, 1, 2, 1, 0, 1, 2, 1, 2},	// 5
	{4, 3, 2, 1, 2, 1, 0, 3, 2, 1},	// 6
	{1, 2, 3, 4, 1, 2, 3, 0, 1, 2},	// 7
	{2, 3, 2, 3, 2, 1, 2, 1, 0, 1},	// 8
	{3, 4, 3, 2, 3, 2, 1, 2, 1, 0},	// 9
};

// slot[i]: vị trí của số i trên bàn phím
// được sử dụng bởi calc
int slot[10];

void get_str() {
	string s;
	int n;
	//
	cin >> s;
	n = s.length();
	for (int i = 0; i < n-1; i++)
		cnt[ s[i]-'0' ][ s[i+1]-'0' ]++;
}

int calc() {
	int dist = 0;
	for (int i = 0; i < 10; i++) 
	for (int j = 0; j < 10; j++) {
		dist += cnt[i][j] * d[ slot[i] ][ slot[j] ];
	}
	return dist;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	get_str();
	for (int i = 0; i < 10; i++) slot[i] = i;
	//
	int res = 2e9+7;
	do {
		res = min(res, calc());
	} while (next_permutation(slot, slot+10));
	//
	cout << res << "\n";
	return 0;
}
