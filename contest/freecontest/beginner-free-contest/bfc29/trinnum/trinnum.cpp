#include <bits/stdc++.h>
using namespace std;

#define lli long long int;

// @oper-vars
int n, m;
// use set to eliminate the dups
set<lli> arr;
// perm[i] == permutations count at arr[i]
lli * perm;

// @perfs
lli calc() {
	return -1L;
}

// @drivers
void getinp() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		lli t; cin >> t; 
		// u only need the remains, indeed.
		// even me found this in time
		t %= m; 
		arr.insert(t);
	}
	// override n after finished deleting all the duplications
	n = arr.size();
}

void init() {
	// since we used ll, perm[i] would contains the value 0 instead of garbages
	perm = new lli[n];
	// its multiplication so it must be 1, not 0
	for (lli i: arr) perm[i] = 1;
}

int main() {
	getinp();
	init();
	// debug
	for (int i = 0; i < n; i++) cout << perm[i] << " "; cout << endl;
	//
	return 0;
}
