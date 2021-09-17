#include <iostream>
#include <climits>
using namespace std;

// @vars
const int N = 1e4, I = INT_MAX;
int n, q;
// index 0 is skipped, start from 1
// segment_tree_size = bottom_layer_size * 2 = array_size * 2
int t[N << 1];	


// @segment_tree
void build() {
	// this reverse-loop is magic
	for (int i = n - 1; i > 0; i--) {
		// explain about i<<1|1
		// "a|1" will return (a + 1) if ((a % 2) == 0)
		// look at the base.png file again.
		// it is clear that the first child of each node is always even
		// and the second child is always odd
		// thus, min(t[i<<1], t[i<<1|1]) means the min val of two children
		t[i] = min(t[i<<1], t[i<<1|1]);
	}
}

void update(int i, int val) {
	t[i+=n] = val;
	// exclude 1 due to the following performance
	for (; i > 1; i >>= 1) {
		// (p^1) ensures that t[p>>1] = min(children);
		t[i >> 1] = min(t[i], t[i^1]);
	}
}

int query(int l, int r) {
	int res = I;
	//
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		// if odd --> next iteration won't travel to its parent
		if (l & 1) res = min(res, t[l++]);

		// this this is [l; r),
		// we'll use (r & 1) and --r
		// if it's [l; r], then we'll use (r ^ 1) and r--
		if (r & 1) res = min(res, t[--r]);	
	}	
	//
	return res;
}


// @drivers
void getinp() {
	cin >> n >> q;
	for (int i = 0; i < n; i++) {
		// look at the base.png file and you see:
		// the given numbers are always stored beginning from node (n) to node (n + n - 1);
		cin >> t[n + i];
	}
	build();
}

int main() {
	getinp();
	while (q--) {
		int p, a, b; cin >> p >> a >> b;
		if (p) {
			cout << query(a, b) << endl;
		} else {
			update(a, b);
		}
	}
	//
	system("pause");
	return 0;
}

