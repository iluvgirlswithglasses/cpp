#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

#define ll long long

const ll  I = 1e18+7;
int n, m, k; 
vector<ll> a, f;

void 

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string test; cin >> test;
	ifstream inp("test/input." + test); cin.rdbuf(inp.rdbuf());
	//
	cin >> n >> m >> k;
	a.resize(n); f.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	f = a;
	//
	for (int i = 1; i < k; i++) {
		// duyệt ngược
		// --> tối ưu từ 2 sang 1 mảng
		deque<int> q;
		for (int j = n-2; j > n-2-(m-1); j--) {

		}
	}
	cout << *max_element(f.begin()+k, f.end()) << "\n";
	return 0;
}

