#include <bits/stdc++.h>
using namespace std;
//
ifstream inp("ranking.inp");
ofstream out("ranking.out");

//
int n, m;
int ** arr;

//
void getinp() {
	inp >> n >> m;
	//
	arr = new int*[n];
	for (int i = 0; i < n; i++) {
		int score; inp >> score;
		arr[i] = new int[2]{i, score};	// index, score
	}
	sort(arr, arr + n, [](int * a, int * b){return a[1] > b[1];});
}

int main() {
	getinp();
	//
	for (int i = 0; i < m; i++) {
		int index; inp >> index; index -= 1;
		//
		int rank = 1;
		for (int i = 0; i < n; i++) {
			if (arr[i][0] == index) break;
			if (arr[i][0] < index) rank += 1;
		}
		cout << rank << endl;
	}
	// 
	getchar();
	return 0;
}
