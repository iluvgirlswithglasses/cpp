// i haven't write a template generator for arch linux yet
// so... yeah this won't have my usual template

#include <iostream>
using namespace std;

const int N = 1e5+7;
int n, res;

bool get_nxt() {
	int v; cin >> v;
	return --v;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	//
	int pre_cnt[2] = {0, 0};
	int pre_typ = get_nxt();
	pre_cnt[pre_typ]++;
	//
	for (int i = 1; i < n; i++) {
		bool a = get_nxt();
		if (a == pre_typ) {
			pre_cnt[a]++;
		} else {
			res = max(
				res,
				min(pre_cnt[0], pre_cnt[1]) << 1
			);
			pre_cnt[a] = 1;
		}
		pre_typ = a;
	}
	//
	res = max(
		res,
		min(pre_cnt[0], pre_cnt[1]) << 1
	);
	cout << res << "\n";
	return 0;
}
