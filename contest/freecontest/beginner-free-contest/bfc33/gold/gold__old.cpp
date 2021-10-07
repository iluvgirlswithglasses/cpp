#include <iostream>
#include <climits>
using namespace std;

#define ll long long

const int N = 1003;
int n, m;

int main() {
	cin >> n >> m;
	ll st = 0, nd = 0;
	//
	for (int i = 0; i < n; i++) {
		ll sm = 0, bg = 0;
		ll cr_sm = 0, cr_bg = 0;
		//
		for (int j = 0; j < m; j++) {
			int v; cin >> v;
			//
			if (v > 0) {
				cr_bg += v;
				bg = max(bg, cr_bg);
				if (cr_bg < 0) cr_bg = 0;
			} else if (v < 0) {
				cr_sm += v;
				sm = min(sm, cr_sm);
				if (cr_sm > 0) cr_sm = 0;
			}
		}
		//
		ll res = max(bg, abs(sm));
		if (res > st) {
			nd = st;
			st = res;
		}
		else if (res > nd) nd = res;
	}
	cout << st + nd << endl;
	// 
	system("pause");
	return 0;
}
