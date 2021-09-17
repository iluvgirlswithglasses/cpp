#include <iostream>
#include <algorithm>
using namespace std;

//@ lims
const int nlim = 3e3 + 1;
const int vlim = 3e3 + 1;
const int tlim = (3e3 * 2) + 1;


//@ vars
int n, t;
pair<int, int> arr[nlim];	// arr[i] = {time_cost, val}
int dp[tlim];


//@ calc
int calc() {
	// do không thể return dp[tlim - 1], ta dùng cách này để lưu lại kết quả tốt nhất
	int best = 0;
	//
	int cost, val;
	for (int i = 0; i < n; i++) {
		cost = arr[i].first;
		val = arr[i].second;
		// t - 1 + cost[i] == thời điểm muộn nhất để hoàn thành đào xong quặng vàng i
		for (int j = t - 1 + cost; j >= 0; j--) {
			int pre = j - cost;
			// j là thời điểm hoàn thành không khả thi kể cả khi bắt đầu đào tại start=0
			if (pre < 0) break;
			//
			dp[j] = max(dp[j], dp[pre] + val);
			best = max(best, dp[j]);
		}
	}
	//
	return best;
}


//@ drivers
int main() {
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	// có những trường hợp mà làm task này trước rồi tới task kia được
	// nhưng làm task kia trước rồi làm task này thì lại không kịp
	// nếu sort theo thời gian trước thì sẽ không gặp phải vụ đó
	sort(arr, arr+n, [](pair<int, int> i, pair<int, int> j) {
		// fast things first
		return i.first < j.first;
	});
	cout << calc();
	//
	system("pause");
	return 0;
}
