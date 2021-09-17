#include <algorithm>
#include <iostream>
#include <fstream>
using namespace std;

// this problem has been solved easily by backtracking-loop
// see: ./trial_of_the_fool/region_4/2017/atm
// if you are here for some dynamic distribution algorithm, stay
// if you are here for the best solution, leave now

//
int n, s;
int * arr;

void print_res(int * res) {
	for (int i = 0; i <= s; i++) cout << res[i] << " "; cout << endl;
}

int calc() {
	int * res = new int[s + 1]; res[0] = 0;
	// i == 0 case has been calculated
	for (int i = 1; i <= s; i++) {
		for (int j = 0; j < n; j++) {
			// if we can use the coin
			if (i - arr[j] >= 0) {
				res[i] = res[i - arr[j]] + 1;
				// since we sorted the arr
				// the best result always show up first
				break;
			}
		}
	}
	//
	print_res(res);
	return *max_element(res, res + s + 1);
}

//
void get_inp() {
	ifstream inp; inp.open("inp.txt");
	inp >> n; inp >> s; arr = new int[n];
	//
	for (int i = 0; i < n; i++) {
		inp >> arr[i];
	}
	// bigger coins have more priority than the smaller ones
	// see: this.calc();
	sort(arr, arr + n, [](int i, int j){return i > j;});
}

int main() {
	get_inp();
	//
	cout << calc();
	system("pause");
	return 0;
}
