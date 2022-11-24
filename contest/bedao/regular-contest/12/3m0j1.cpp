
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Nov 24 10:31:22 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

const string TYP[] = {
	";-)",		// 0.
	";-(",		// 1
	":)",		// 2
	":(",		// 3.
	":-\\",		// 4.
	":-P",		// 5.
	":D",		// 6.
	":C",		// 7.
	":-0",		// 8.
	":-|",		// 9.
	"8-0",		// 10.
	":-E",		// 11.
	":-X",		// 12.
	":~(",		// 13.
	"[:|||:]"	// 14.
};

map<char, int> cnt;
vector<int> appear;
string s;

void erase(int id, int n) {
	for (char c: TYP[id])
		cnt[c] -= n;
}

void check_unique(char c, int id) {
	if (cnt[c] > 0) {
		appear.push_back(id);
		erase(id, cnt[c]);
	}
}

void req_check_unique(int id) {
	int mn = 1e6+7;;
	for (char c: TYP[id])
		mn = min(mn, cnt[c]);
	if (mn > 0) {
		appear.push_back(id);
		erase(id, mn);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	for (char c: s)
		cnt[c]++;

	check_unique('\\', 4);
	check_unique('P', 5);
	check_unique('D', 6);
	check_unique('C', 7);
	check_unique('8', 10);
	check_unique('E', 11);
	check_unique('X', 12);
	check_unique('~', 13);

	check_unique('0', 8);
	check_unique('[', 14);
	check_unique('|', 9);

	req_check_unique(0);
	req_check_unique(1);
	req_check_unique(2);
	req_check_unique(3);
	

	// export
	for (int i: appear) {
		cout << TYP[i] << "\n";
	}
	return 0;
}
