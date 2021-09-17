// find the longest common subsequence first
// then find the longest increasing array
// how simple it is
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

//@ vars
const int nlim = 1507;
const int alim = -1e9-1;
int alen, blen, a[nlim], b[nlim];
int dp[nlim][nlim];


//@ perf
void lcs() {
	for (int i = 1; i <= alen; i++) {
		for (int j = 1; j <= blen; j++) {
			// initialize
			dp[i][j] = 0;
			// must fix
			if (a[i-1] == b[j-1]) {
				dp[i][j] = dp[i-1][j-1] + 1;
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
}

vector<int> get_lcs() {
	vector<int> seq;
	//
	int i = alen, j = blen;
	while (i > 0 && j > 0) {
		if (a[i-1] == b[j-1]) {
			seq.insert(seq.begin() + 0, a[i-1]);
			i--; j--;
		} else if (dp[i-1][j] > dp[i][j-1]) {
			i--;
		} else {
			j--;
		}
	}
	//
	return seq;
}

int lis() {
	int seq_dp[nlim];
	vector<int> seq = get_lcs();
	int seq_len = seq.size();
	// debug
	// for (int i: seq) cout << i << " "; cout << endl;
	//
	for (int i = 0; i < seq_len; i++) {
		seq_dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (seq[i] >= seq[j] * 2 && seq_dp[i] < seq_dp[j] + 1) {
				seq_dp[i] = seq_dp[j] + 1;
			}
		}
	}
	//
	int res = *max_element(seq_dp, seq_dp + seq_len);
	if (res == 1) res = 0;
	return res;
}

int calc() {
	lcs();
	return lis();
}


//@ drivers
int main() {
	int t; cin >> t;
	while (t--) {
		cin >> alen >> blen;
		for (int i = 0; i < alen; i++) cin >> a[i];
		for (int i = 0; i < blen; i++) cin >> b[i];
		cout << calc() << endl;
	}
	// returns
	return 0;
}
