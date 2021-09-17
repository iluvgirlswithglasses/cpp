#include <bits/stdc++.h>
using namespace std;
ofstream out("aprobot.out");

//
int n, k;
vector<int*> arr;		// arr[i]: {initial index, weight}

/* 
	if (arr.size() == 0) return res;
	for (int i = 0; i < k; i++) {
		auto cr_max = max_element(arr.begin(), arr.end());
		// if the index of max >= k 
		// => have to move
		int index = distance(arr.begin(), cr_max);
		if (index >= k) res += 1;
		//
		arr.erase(cr_max);
	}
	return calc(res);
*/

void advancearr(int rank) {
	for (int * i: arr) {
		if (i[0] < rank) {
			i[0] += 1;
		}
	}
}

int calc(int & res) {
	int counts = 0;
	sort(arr.begin(), arr.end(), [](int * i, int * j){return i[1] > j[1];});
	for (int i = 0; i < n / k - 1; i++) {	// n % k == 0
		for (int j = 0; j < k; j++) {
			if (arr[i*k + j][0] >= (i + 1) * k) {
				counts += 1;
				advancearr(arr[i*k + j][0]);
			}
		}
	}
	//
	return counts;
}

//
void getinp() {
	ifstream inp("aprobot.inp");
	inp >> n >> k;
	for (int i = 0; i < n; i++) {
		int t; inp >> t;
		arr.push_back(new int[2]{i, t});
	}
}

//
int main() {
	getinp();
	int res = 0;
	cout << calc(res);
	//
	getchar();
	return 0;
}
