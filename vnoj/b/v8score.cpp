
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Sat Nov 13 15:31:56 2021
tab-width:	4 spaces

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
using namespace std;

const int S = 202, N = 22, K = 22;
// a[n][k]:		score of question `k` suggested by judge `n`
int s, n, k, a[N][K];
// pos[s][n]: 	can make the sum of `s` using the first `k` questions
// pre[s][n]:	the score of the last problem from 0 to `n` whose problemset has sum of `s`
bool pos[S][K];
int  pre[S][K];

bool calc() {
	//
	for (int i = 0; i < n; i++) {
		// the score given by judge `i` can be achive after giving the first problem
		pos[ a[i][0] ][0] = true;
		pre[ a[i][0] ][0] = a[i][0];
	}
	//
	for (int i = 1; i < k; i++) 	// for `i` in `k` problem
	for (int j = 0; j < n; j++) {	// for `j` in `n` judge
		// for each possible score from previous problem
		for (int x = 0; x + a[j][i] <= s; x++) if (
			pos[x][i-1] &&
			pre[x][i-1] <= a[j][i]
		) {
			// confirm that making the sum of `nxt` is possible at problem `i`
			int nxt = x + a[j][i];
			if (!pos[nxt][i]) {
				pos[nxt][i] = true;
				pre[nxt][i] = a[j][i];
			} else {
				pre[nxt][i] = min(pre[nxt][i], a[j][i]);
			}
		}
	}
	return pos[s][k-1];
}

int* regen() {
	int* res = new int[k];
	for (int i = k-1, j = s; i >= 0; i--) {
		res[i] = pre[j][i];
		j -= pre[j][i];
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> s >> k >> n;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < k; j++)
		cin >> a[i][j];
	//
	if (calc()) {
		cout << "YES\n";
		//
		int* res = regen();
		for (int i = 0; i < k; i++)
			cout << res[i] << " ";
		cout << "\n";
		delete[] res;
	} else {
		cout << "NO\n";
	}
	return 0;
}

