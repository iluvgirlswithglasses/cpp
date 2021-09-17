// dynamic_distribution.can_travel, but 4 moves version
// dfs vers

#include <list>
#include <iostream>
using namespace std;

//
const int WALL = 0;
const int PATH = 1;
const int VIST = 2;	// visited

// 
const int movs = 4;
int y_mov[4] = {0, 0, 1, -1};
int x_mov[4] = {-1, 1, 0, 0};

//
bool is_safe(int i, int j, int n, int m) {
	return i >= 0 && j >= 0 && i < n && j < m;
}

//
int loop_count = 0;
bool calc(int n, int m, int ** arr) {
	//
	list<int*> queue;
	queue.push_back(new int[2]{0, 0});
	//
	while (!queue.empty()) {
		loop_count += 1;
		int * pre = queue.front();
		if (pre[0] == n - 1 && pre[1] == m - 1) return true;	// should have moved this to the inner loop
		//
		queue.pop_front();
		arr[pre[0]][pre[1]] = VIST;
		//
		for (int i = 0; i < movs; i++) {
			//
			int nxt_y = pre[0] + y_mov[i], nxt_x = pre[1] + x_mov[i];
			//
			if (!is_safe(nxt_y, nxt_x, n, m)) continue;
			//
			if (arr[nxt_y][nxt_x] == PATH) {
				queue.push_back(new int[2]{
					nxt_y, nxt_x
				});
			}
		}
		delete[] pre;	// this is new
	}
	//
	return false;
}

// drivers
int main() {
	int n = 5, m = 5;
	int ** arr = new int*[n]{
		new int[m]{1, 0, 1, 1, 1},
		new int[m]{1, 0, 1, 0, 1},
		new int[m]{1, 0, 1, 0, 1},
		new int[m]{1, 0, 1, 0, 1},
		new int[m]{1, 1, 1, 0, 1},
	};
	//
	cout << calc(n, m, arr);
	cout << "\nloop count: " << loop_count << endl;
	//
	system("pause");
	return 0;
}
