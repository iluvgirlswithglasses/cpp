#include <set>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

#define ll long long
const int N = 1e4+7, K = 12, T = 1e9;
int n, k, arr[N], bit[N];

// after compressing,
// arr[i] which is the j-th largest element will have the value of j
void compress() {
	// sorting with red-black tree
    set<int> s(arr, arr + n);
    vector<int> v(s.begin(), s.end());
    // better learn this magic
    for (int i = 0; i < n; i++) {
        arr[i] = v.end() - lower_bound(v.begin(), v.end(), arr[i]);
    }
}

/**
 * fenwich tree
 * */
void update(int v, int inc) {
	while (v <= n) {
		bit[v] += inc; bit[v] %= T;
		v += v & -v;
	}
} 

int get(int v) {
	ll res = 0;
	while (v > 0) {
		res += bit[v];
		v -= v & -v;
	}
	return res % T;
}

/**
 * driver
 * */
int main() {
	// inp
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    compress();
	// calc
    vector<int> f(n, 1);
    while (--k) {
    	//
		for (int i = 1; i <= n; i++) bit[i] = 0;
		//
        for (int i = 0; i < n; i++) {
            int pre = f[i];
            f[i] = get(arr[i]-1);
            update(arr[i], pre);
        }
    }
    // result
    ll res = 0;
    for (int i: f) res += i;
    cout << res % T << endl;
	//
    system("pause");
    return 0;
}
