#include <algorithm>
#include <iostream>
using namespace std;

//@ vars
const int nlim = 20;
int n, c, weeks = 0;
pair<int, int> arr[nlim];	
// arr[i]: { mệnh giá, số lượng }
// arr[i][0] % arr[i-1][0] == 0


//@ calc
int calc() {
	//
	
	// returns
	return weeks;
}


//@ drivers
int main() {
	// inp
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int val, quan; cin >> val >> quan;
		if (val >= c) {
			// nếu mỗi tuần đều có thể trả bằng 1 xu mệnh giá val
			// --> add ngay vào weeks & không cần tính lại nữa
			n--;
			i--;
			weeks += quan;
		} else {
			arr[i] = {val, quan};
		}
	}
	sort(arr, arr+n, [](pair<int, int> i, pair<int, int> j) {
		return i.first < j.first;
	});
	// calc
	cout << calc() << endl;
	// returns
	system("pause");
	return 0;
}

