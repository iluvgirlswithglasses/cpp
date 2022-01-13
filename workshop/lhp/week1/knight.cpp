
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Thu Jan 13 13:18:52 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int N = 204;
int  m, n, c, p, q;
int  mov_x[4] = {-2, -2, -1, 1}, 
     mov_y[4] = {1, -1, -2, -2};
// b[i][j] == true --> the player who starts at i j wins; otherwise: loose
bool b[N][N];

bool win(int x, int y, int p) {
	x += mov_x[p];
	y += mov_y[p];
	if (x >= 0 && x < n && y >= 0 && y < m) {
		return !b[y][x];
	}
	return false;
}

void generate() {
	// duyệt theo đường chéo trái dưới -> phải trên
	for (int d = 2; d < m+n-1; d++) {
		int row, col = min(d, n);
		do {
			row = d - col;
			for (int p = 0; p < 4; p++) if (win(col, row, p)) {
				b[row][col] = true;
				break;
			}
		} while (col--);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> n >> c;
	generate();
	//
	while (c--) {
		cin >> p >> q;
		if (b[++p][++q])
			cout << "-1\n";
		else
			cout << "1\n";
	}
	return 0;
}
