#include <iostream>
#include <algorithm>
using namespace std;

#define val first
#define quan second
#define ll long long

const int N = 1e5+7;
pair<int, int> arr[N];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int q; cin >> q;
	for (int i = 0; i < q; i++) cin >> arr[i].val >> arr[i].quan;
	ll k; cin >> k;
	//
	sort(arr, arr + q, [](pair<int, int> i, pair<int, int> j){
		return i.val < j.val;
	});
	ll rank = 1;
	for (int i = 0; i < q; i++) {
		ll nxt_rank = rank + arr[i].quan;
		if (nxt_rank > k) {
			cout << arr[i].val << endl;
			break;
		}
		rank = nxt_rank;
	}
	return 0;
}
