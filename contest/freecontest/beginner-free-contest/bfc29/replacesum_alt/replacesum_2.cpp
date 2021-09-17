#include <bits/stdc++.h>
using namespace std;

#define lli long long int

//
int n, k;
vector<lli> arr;
lli cost;

//
void getinp() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		lli t; cin >> t;
		arr.push_back(t);
	}
	//
	sort(arr.begin(), arr.end(), [](lli i, lli j){
		return i > j;
	});
}

int main() {
	getinp();
	while (arr.size() > 1) {
		//
		lli cr_sum = arr.back();
		lli cr_max = arr.back();
		lli cr_min = arr.back();
		arr.pop_back();	// popped 1
		//
		int cr_len = arr.size();
		// k-1 numbers left to be popped
		for (int i = 0; i < min(k - 1, cr_len); i++) {
			cr_sum += arr.back();
			cr_max = max(cr_max, arr.back());
			cr_min = min(cr_min, arr.back());
			//
			arr.pop_back();
		}
		// calc
		int cr_cost = cr_max - cr_min;
		cost += cr_cost;
		//
		cr_len = arr.size();
		if (cr_len == 0) {
			arr.push_back(cr_sum);
			break;	// break while loop
		} else {
			bool inserted = false;
			//
			for (int i = 0; i < cr_len; i++) {
				// go from the biggest to the smallest
				if (cr_sum >= arr[i]) {
					arr.insert(arr.begin() + i, cr_sum);
					inserted = true;
					break;	// no insert, no more
				}
			}
			// if cr_sum is smaller than every thing
			if (!inserted) {
				arr.push_back(cr_sum);
			}
		}
	}
	cout << arr[0] << endl << cost << endl;
	//
	return 0;
}
