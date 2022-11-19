
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 19 15:15:33 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <queue>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
#define st first
#define nd second
#define all(c) c.begin(), c.end()

struct node {
	int t, c, v;
};

const int T = 1007, S = 102, C = 102, V = 102, I = 2e9+7;
const int KEEP_SPEED = 0, SPEED_UP = 1, SPEED_DOWN = 2, REST = 3;
int maxT, maxS, maxEnergy;

// cost[i]: năng lượng để thực hiện thao tác `i`

// thao tác 0: duy trì tốc độ
//          1: tăng tốc
//          2: giảm gốc
//          3: nghỉ ngơi
int cost[4];

// dp[t][c][v]: quãng đường tối đa đi được tại thời điểm `t` 
//              với mức năng lượng còn lại là `c`
//              và vận tốc là `v`
int dp[T][C][V];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> maxT >> maxS;
	cin >> maxEnergy >> cost[KEEP_SPEED] >> cost[SPEED_UP] >> cost[SPEED_DOWN];
	//
	cost[3] = cost[2];
	// init
	for (int i = 0; i < T; i++)
		for (int j = 0; j < C; j++)
			for (int k = 0; k < V; k++)
				dp[i][j][k] = -I;
	dp[0][maxEnergy][0] = 0;

	// calc
	for (int t = 1; t <= maxT; t++) {	// O(1e3)

		// nếu chọn nghỉ ngơi
		for (int c = 0; c <= maxEnergy; c++) {	// O(1e2)
			for (int v = 0; v <= maxS; v++) {
				int nxt = min(maxEnergy, c + cost[REST]);

				dp[t][nxt][0] = max(
					dp[t][nxt][0],
					dp[t-1][c][v]
				);
			}
		}

		// nếu chọn giảm tốc
		for (int c = 0; c <= maxEnergy; c++) {
			for (int v = 0; v < maxS; v++) {
				int nxt = min(maxEnergy, c + cost[SPEED_DOWN]);

				dp[t][nxt][v] = max(
					dp[t][nxt][v],
					dp[t-1][c][v+1] + v
				);
			}
		}

		// nếu chọn giữ nguyên tốc độ
		for (int c = 0; c <= maxEnergy - cost[KEEP_SPEED]; c++) {
			for (int v = 0; v <= maxS; v++) {
				dp[t][c][v] = max(
					dp[t][c][v],
					dp[t-1][c + cost[KEEP_SPEED]][v] + v
				);
			}
		}

		// nếu chọn tăng tốc
		for (int c = 0; c <= maxEnergy - cost[SPEED_UP]; c++) {
			for (int v = 0; v < maxS; v++) {
				dp[t][c][v+1] = max(
					dp[t][c][v+1],
					dp[t-1][c + cost[SPEED_UP]][v] + v + 1
				);
			}
		}
	}
	// lấy kết quả
	int res = 0;
	for (int c = 0; c <= maxEnergy; c++) {
		for (int v = 0; v <= maxS; v++) {
			res = max(res, dp[maxT][c][v]);
		}
	}
	cout << res << "\n";
	return 0;
}
