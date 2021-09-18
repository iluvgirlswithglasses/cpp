// there can't be 2 or more positive numbers in an array
// cuz with (a, b > 0) --> (a - b < a)
// if the max number in array < 0 --> with (difference >= 0), we get the whole array

#include <iostream>
#include <algorithm>
using namespace std;

//@ vars
const int alim = 1e9;
const int lim = 1e5;
int n, arr[lim];

//@ drivers
int main() {
	int t; cin >> t;
	int mingap;
	while (t--) {
		cin >> n;
		if (n < 2) {
			// length < 2 --> nothing to do here
			cout << 1 << endl;
			break;
		}
		// get inp
		for (int i = 0; i < n; i++) cin >> arr[i];
		sort(arr, arr + n, [](int i, int j){
			return i < j;
		});
		//
		mingap = alim;
		for (int i = 0; i < n-1; i++) {
			mingap = min(mingap, arr[i+1] - arr[i]);
			// if the next number is positive
			// it is the only possible positive number can present in the array (as proved above)
			// also, if exists, that's the biggest and the last number of the array --> break right here
			if (arr[i+1] > 0) {
				n = i+1;
				// if that positive number can present --> add length by 1
				if (arr[i] < mingap) n++;
				break;
			}
		}
		//
		cout << n << endl;
	}
	//
	return 0;
}
