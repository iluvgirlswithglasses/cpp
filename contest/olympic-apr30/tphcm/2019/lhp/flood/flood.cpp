#include <bits/stdc++.h>
using namespace std;

// cell types
const int PATH = 0;
const int WATE = 1;	// water
const int PREW = 2;	// pre-water, for spreading
const int HOME = 3;
const int SHOP = 4;

// some vars
int n, m, k;
int ** state;	// state[i][j] == cell i j type
int ** arr;		// arr[i][j] == highest boats remain at cell i j
//
int * homePos;
int * shopPos;

//
int movs = 4;
int iMov[4] = {1, -1, 0, 0};
int jMov[4] = {0, 0, 1, -1};

// encoding
// from inp file to codes
char * encode = new char[5]{'.', 'S', ' ', 'H', 'G'};	// PREW not exists in pre-encode

// debug
void printarr(int ** arr) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		} cout << endl;
	} cout << endl;
}

// use this instead of cout in real test
ofstream out("flood.out");

// basic utils
bool is_safe(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < m;
}

bool is_safe(int * i) {
	return is_safe(i[0], i[1]);
}

void setval(int ** arr, int * i, int val) {
	arr[i[0]][i[1]] = val;
}

int getval(int ** arr, int * i) {
	return arr[i[0]][i[1]];
}

// utils
void refill_arr() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = -1;
		}
	}
	setval(arr, homePos, k);
}

void spread(int i, int j) {
	for (int k = 0; k < movs; k++) {
		int nxtI = i + iMov[k],
			nxtJ = j + jMov[k];
		//
		if (is_safe(nxtI, nxtJ)) {
			if (state[nxtI][nxtJ] == PATH) {
				state[nxtI][nxtJ] = PREW;
			}
		}
	}
}

// perf
bool can_travel() {
	// bfs
	refill_arr();
	list<int*> qu = {homePos};
	//
	while (!qu.empty()) {
		int * cr = qu.front(); qu.pop_front();
		for (int i = 0; i < movs; i++) {
			int * nxt = new int[2]{
				cr[0] + iMov[i], cr[1] + jMov[i]
			};
			if (!is_safe(nxt)) continue;
			//
			int nxtVal = getval(arr, cr);
			if (getval(state, nxt) == WATE) nxtVal -= 1;	// lose a boat if that's water
			if (nxtVal <= getval(arr, nxt)) continue;		// if this gives not a better res
			//
			if (nxtVal > -1) {
				// gocha
				if (nxt[0] == shopPos[0] && nxt[1] == shopPos[1]) return true;
				// add to queue
				setval(arr, nxt, nxtVal);
				qu.push_back(nxt);
			}
		}
	}
	//
	return false;
}

void update() {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (state[i][j] == WATE) spread(i, j);
	//
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (state[i][j] == PREW) state[i][j] = WATE;
}

void recursion(int & best) {
	// printarr(state);
	// if can travel
	if (can_travel()) {
		best += 1;
		update();
		// call child
		recursion(best);
	}
}

// io
void getinp() {
	ifstream inp("flood.inp");
	inp >> n >> m >> k;
	//
	state = new int*[n]; arr = new int*[n];
	for (int i = 0; i < n; i++) {
		state[i] = new int[m]; arr[i] = new int[m];
		//
		for (int j = 0; j < m; j++) {
			char c; inp >> c;
			state[i][j] = distance(encode, find(encode, encode + 5, c));
			//
			if (c == 'H') homePos = new int[2]{i, j};
			if (c == 'G') shopPos = new int[2]{i, j};
		}
	}
}

// driver
int main() {
	getinp();
	if (
		abs(homePos[0] - shopPos[0]) + abs(homePos[1] - shopPos[1]) - 1 <= k
	) {
		// if there is enough boats to travel the min distance
		cout << "-1";
	} else {
		// calc
		int best = 0;	// always success @ t = 0
		recursion(best);
		cout << best;
	}
	//
	getchar();
	return 0;
}

