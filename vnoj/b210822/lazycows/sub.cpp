// vấn đề phụ:
// giả sử chỉ cho một hàng thay vì hai
// vậy thì làm sao :)

/*
cho một bãi cỏ 1*B nó N con bò đang ăn cỏ
không con bò nào đứng cùng ô

cần xây K cái chuồng bao phủ N con bò đó
hỏi diện tích dư thừa tối thiểu là bao nhiêu

1 <= K <= N <= 1000
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 1004, B = 15e6+4;
int b, k, n, arr[N], 
	// acc[i]: diện tích dư thừa giữa bò i và bò i+1
	// acc[i] = arr[i+1] - arr[i] - 1
	acc[N-1];

/**
 * driver
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	// inp
	cin >> n >> k >> b;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	sort(arr, arr+n);
	// greedy
	for (int i = 0; i < n-1; i++) 
		acc[i] = arr[i+1] - arr[i] - 1;
	sort(acc, acc+(n-1));
	// result
	int res = 0;
	for (int i = 0; i < n - k; i++)
		res += acc[i];
	cout << res << "\n";
	//
	return 0;
}

