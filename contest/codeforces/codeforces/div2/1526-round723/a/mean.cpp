#include <algorithm>
#include <iostream>
using namespace std;

// O(t * (nlogn + n))

//
const int N = 60;
int n, len;
int arr[N];

//
void calc() {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " " << arr[i+n] << " ";
	}
	//
	cout << endl;
}

void getinp() {
	cin >> n;
	len = n << 1;
	for (int i = 0; i < len; i++) {
		cin >> arr[i];
	}
	//
	sort(arr, arr + len, [](int i, int j){return i < j;});
	// về cái sort này:
	// TH1:
	// (arr[0] < arr[len-1]; arr[len-2] < arr[len-1]) 
	// => 1/2 * (arr[0] + arr[1]) < arr[len-1] 
	// => loại 1 vòng tròn 
	// TH2:
	// (arr[0] < arr[1]; arr[0] < arr[len-1])
	// => 1/2 * (arr[1] + arr[len-1]) > arr[0]
	// => loại nốt cái thứ 2
}

//
int main() {
	int t; cin >> t;
	while (t--) {
		getinp();
		if (len > 3) {
			calc();
		} else {
			for (int i = 0; i < len; i++) {
				cout << arr[i] << " ";
			} cout << endl;
		}
	}
	//
	return 0;
}
