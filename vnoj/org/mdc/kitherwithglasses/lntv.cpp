
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 26 20:35:42 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
using namespace std;

#define all(c) c.begin(), c.end()
#define ll long long
#define pi pair<int, int>
#define st first
#define nd second

const int N[10] = {
//  0  1  2  3  4  5  6  7  8  9
	6, 2, 5, 5, 4, 5, 6, 3, 7, 6, 
};

int s, x;

int sum(string str) {
	int res = 0;
	for (char i: str) res += N[i-'0'];
	return res;
}

string to_str(int i) {
	string str = to_string(i);
	str = string(6-str.length(), '0') + str;
	return str;
}

int find(int x) {
	if (x == 1000000) return -1;
	if (sum(to_str(x)) == s) return x;
	return find(x+1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> x;
	s = sum(to_str(x));
	cout << find(x+1) << "\n";
	return 0;
}
