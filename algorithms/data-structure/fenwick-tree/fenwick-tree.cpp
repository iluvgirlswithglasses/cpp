#include <iostream>
using namespace std;

//
int n, q;
int * arr;
int * fenwick;

// @fenwick
int getsum(int p) {	// p == position
	int sum = 0;
	p += 1;
	while (p > 0) {
		sum += fenwick[p];
		p -= p & (-p);
	}
	return sum;
}

void update(int p, int inc) {	// inc: increase value
	p += 1;
	while (p <= n) {
		fenwick[p] += inc;
		p += p & (-p);
	}
}

void construct(int n) {
	// reminder: fenwick tree has the size of n+1
	for (int i = 0; i < n; i++) {
		update(i, arr[i]);
	}
}

// @drivers
void getinp() {
	cin >> n >> q;
	arr = new int[n];
	fenwick = new int[n+1];
	//
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		fenwick[i+1] = 0;	// fenwick[0] will never be used
	}
	//
	construct(n);
}

//
int main() {
	getinp();
	// for (int i = 0; i < n; i++) cout << fenwick[i+1] << " "; cout << endl;
	while (q--) {
		// pseudo
		int t; cin >> t;
		if (t) {
			// get
			int p; cin >> p;
			cout << getsum(p) << endl;
		} else {
			// update
			int p, val; cin >> p >> val;
			update(p, val - arr[p]);
		}
	}
	//
	system("pause");
	return 0;
}
