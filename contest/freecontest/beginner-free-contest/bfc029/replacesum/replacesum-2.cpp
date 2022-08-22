#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

#define lli long long int

//
int n, k;
vector<lli> arr;

//
int main() {
	// io
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		lli t; cin >> t;
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end(), [](lli i, lli j){
		return i > j;
	});

	// perf
	lli cost = 0;
	while (arr.size() > 1) {
		int cr_len = arr.size();
		// the sum
		lli cr_sum = arr.back();
		lli max_case = arr.back();
		lli min_case = arr.back();
		arr.pop_back();
		// now there are k-1 number to go
		for (int i = 0; i < min(k - 1, cr_len); i++) {
			max_case = max(max_case, arr.back());
			min_case = min(min_case, arr.back());
			cr_sum += arr.back();
			//
			arr.pop_back();
		}

		// the cost
		lli cr_cost = abs(max_case - min_case);
		cost += cr_cost;
		// the sum
		if (cr_len == 0) {
			arr.push_back(cr_sum);
			break;
		} else {
			bool inserted = false;
			//
			for (int i = cr_len - 1; i >= 0; i--) {
				if (arr[i] >= cr_sum) {
					arr.insert(arr.begin() + i + 1, cr_sum);
					inserted = true;
					break;
				}
			}
			//
			if (!inserted) arr.insert(arr.begin() + 0, cr_sum);
		}
	}
	cout << arr.back() << endl << cost << endl;
	//
	return 0;
}
