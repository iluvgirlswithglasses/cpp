#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int N = 1e5+7;
int n; 
pair<int, bool> event[N<<1];	// true = is open; false = is close;

int calc() {
	int res = 1;
	bool parent_open = false, child_open = false;
	for (int i = 0; i < (n<<1); i++) {
		bool t = event[i].second;
		//
		if (t && !parent_open) {
			res++;
			parent_open = true;
		}
		else if (t && parent_open && !child_open) {
			res++;
			child_open = true;
		}
		else if (!t && parent_open && child_open) {
			child_open = false;
		}
		else if (!t && parent_open) {
			parent_open = false;
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, r; cin >> x >> r;
		event[i<<1]   = {x - r, true};
		event[i<<1|1] = {x + r, false};
	}
	sort(event, event + (n<<1), [](pair<int, int> i, pair<int, int> j){
		if (i.first == j.first) {
			return i.second == false;
		}
		return i.first < j.first;
	});
	//
	cout << calc() << endl;
	return 0;
}
