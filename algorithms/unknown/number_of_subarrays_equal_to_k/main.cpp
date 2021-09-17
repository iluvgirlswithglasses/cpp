#include <unordered_map>
#include <iostream>
using namespace std;

//@ vars
const int nlim = 1e5;
int n, k, arr[nlim];


//@ perf
// O(n)
int calc() {
	int res = 0;	// result - the count of solutions
	int cr_s = 0;	// sum of elements so far
	unordered_map<int, int> prev_s;	// store the number of subarrays that having sum == k

	for (int i = 0; i < n; i++) {
		cr_s += arr[i];
		// found one more subarray that can make this sum
		prev_s[cr_s]++;
		// if cr_sum == k
		// --> found a new subarray
		if (cr_s == k) res++;
		// if (cr_sum - k) exists in prev_s[]
		// --> cr_sum - prev_sum == k
		if (prev_s.find(cr_s - k) != prev_s.end()) res += prev_s[cr_s - k];
	}

	// returns after O(n)
	return res;
}


//@ main
int main() {
	// inp
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	//
	cout << calc() << endl;
	//
	system("pause");
	return 0;
}

