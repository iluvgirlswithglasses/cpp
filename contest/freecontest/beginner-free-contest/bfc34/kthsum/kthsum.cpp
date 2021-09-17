#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define st first
#define nd second
#define pi pair<int, int>

const int N = 1e5+7;
int n, k, a[N], b[N];

// tbh, I read the editorial
// cuz if I didn't, I'd write a whole tree class instead of priority_queue to perform maxheap
// which is... over embellishing, and full of pointers.
// first time using priority_queue tho
priority_queue<pi, vector<pi>, greater<pi>> mh;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	//
	sort(b, b+n, [](int i, int j){return i < j;});
	for (int i = 0; i < n; i++) {
		mh.push({a[i] + b[0], 0});
	}
	//
	while (k--) {
		pi cr = mh.top(); mh.pop();
		cout << cr.st << " ";
		if (cr.nd < n-1)
			mh.push({cr.st - b[cr.nd] + b[cr.nd+1], cr.nd+1});
	} cout << "\n";
	return 0;
}
