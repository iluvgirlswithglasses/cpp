
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Jan 13 15:49:49 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

/*
ý tưởng:
do n khá nhỏ,
ta tạo chỉnh hợp dãy `n` mục tiêu
trong đó, thứ tự của mục tiêu trong dãy cũng chính là thứ tự đào mục tiêu ấy lên
ta chọn chỉnh hợp cho thời gian ngắn nhất
*/

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

/** 
 * @ defs
 * */
#define pi pair<int, int>
#define st first
#define nd second

const int S = 504, N = 12;
const int START = 1, TARGET = 2, PATH = 3, BLOCKED = 4;

/** 
 * @ vars 
 * */
int h, w, m[S][S];

/**
 * @ inp
 * */
void assign(int i, int j, int t) {
	if (i >= 0 && j >= 0 && i < h && j < w && m[i][j] != BLOCKED)
		m[i][j] = t;
}

void getinp() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		string s; cin >> s;
		for (int j = 0; j < w; j++) {
			char c = s[j];
			switch (c) {
				case '@':
					assign(i, j, START);
					break;
				case '!':
					assign(i, j, TARGET);
					break;
				case '.':
					assign(i, j, PATH);
					break;
				case '#':
				case '~':
					assign(i, j, BLOCKED);
					break;
				case '*':
					assign(i-1, j, BLOCKED);
					assign(i, j-1, BLOCKED);
					assign(i, j+1, BLOCKED);
					assign(i+1, j, BLOCKED);
					break;
			}
		}
	}
}

/**
 * @ perf
 * */

/**
 * @ drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	getinp();

	return 0;
}
