#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

//
int n, k;
vector<int> arr;

//
void printarr(vector<int> & arr) {
	for (int i = 0; i < arr.size(); i++) cout << arr[i] << " "; cout << endl;
}

//
int main() {
	// io
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int t; cin >> t;
		arr.push_back(t);
	}
	sort(arr.begin(), arr.end(), [](int i, int j){
		return i > j;
	});

	// perf
	int cost = 0;
	while (arr.size() >= k) {
		// the sum
		int cr_sum = arr.back();
		// the cost
		int max_case = arr.back();
		int min_case = arr.back();
		arr.pop_back();
		// now there are k-1 number to go
		for (int i = 0; i < k - 1; i++) {
			max_case = max(max_case, arr.back());
			min_case = min(min_case, arr.back());
			cr_sum += arr.back();
			//
			arr.pop_back();
		}

		// the cost
		int cr_cost = max_case - min_case;
		cost += cr_cost;
		// the sum
		int cr_len = arr.size();
		if (cr_len == 0) {
			arr.push_back(cr_sum);
			break;
		} else {
			int inserted = false;
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
