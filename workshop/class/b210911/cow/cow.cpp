#include <bits/stdc++.h>
using namespace std;

//
int n, m;
int ** mat;
int * startPos;
//
char * encodes = new char[4]{'B', '*', '.', 'C'};
const int START = 0;
const int ROCK 	= 1;
const int GRASS = 2;
const int DES   = 3;
const int VIST  = 4;	// mark the visited
int movs = 4;
int * movI = new int[movs]{0, 0, 1, -1};
int * movJ = new int[movs]{-1, 1, 0, 0};

// utils
int getval(int * pos, int ** mat) {
	return mat[ pos[0] ][ pos[1] ];
}

void setval(int * pos, int ** mat, int val) {
	mat[ pos[0] ][ pos[1] ] = val;
}

bool is_safe(int * pos) {
	int a = pos[0], b = pos[1];
	return a >= 0 && b >= 0 && a < n && b < m;
}

//
void printarr(int ** mat) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << mat[i][j] << " ";
		} cout << endl;
	} cout << endl;
}

int bfs() {
	//
	list<int*> q = {startPos};	// q[i] == {i, j};
	list<int> res = {1};		//
	setval(startPos, mat, VIST);
	while (!q.empty()) {
		int * cr = q.front(); q.pop_front();
		int crVal = res.front(); res.pop_front();
		//
		for (int i = 0; i < movs; i++) {
			int * nxt = new int[2]{
				cr[0] + movI[i], cr[1] + movJ[i]
			};
			if (!is_safe(nxt)) {
				delete[] nxt; continue;
			}
			//
			if (getval(nxt, mat) == DES) return crVal;
			if (getval(nxt, mat) == GRASS) {
				//
				setval(nxt, mat, VIST);
				res.push_back(crVal + 1);
				q.push_back(nxt);
			} else {
				delete[] nxt;
			}
		}
		delete[] cr;	// this is new
	}
	//
	return -1;
}

//
void getinp() {
	ifstream inp("cow.inp");
	inp >> n >> m;
	mat = new int*[n];
	//
	for (int i = 0; i < n; i++) {
		mat[i] = new int[m];
		string s; inp >> s;
		//
		for (int j = 0; j < m; j++) {
			mat[i][j] = distance(encodes, find(encodes, encodes + 4, s.at(j)));
			if (mat[i][j] == START) startPos = new int[2]{i, j};
		}
	}
}

//
int main() {
	getinp();
	cout << bfs();
	//
	getchar();
	return 0;
}
