
// lcis_0 chỉ thực hiện được nếu yêu cầu đề là tìm strictly increasing sequence
// phiên bản nâng cấp này chấp mọi điều kiện
// như training/vnoj/lcs2x

#include <algorithm>
#include <iostream>
using namespace std;

const int nlim = 2e3+7;
int al, a[nlim],
	bl, b[nlim];
// dp[j] lưu trữ độ dài của lcis kết thúc với b[j]
int dp[nlim];

// f là comparator
int calc(bool (*f)(int i, int j)) {
	for (int i = 0; i < al; i++) {
		// `crlen` là độ dài tốt nhất có thể đạt được
		// nếu không bao gồm `b[j]``
		int crlen = 0;
		for (int j = 0; j < bl; j++) {
			// tạm lưu lại giá trị của `crlen` vì nguyên nhân bên dưới
			int pre = crlen;
			// nếu a[i] có thể sử dụng kết quả của b[j]
			if (f(b[j], a[i])) 
				crlen = max(crlen, dp[j]);
			// nếu thêm được 1 phần tử vào common sequence
			// --> độ dài tối đa có thể đạt được = `pre + 1`
			//	   với pre là độ dài tốt nhất có thể đạt được mà không có `b[j]`
			// lưu ý,
			// phải là `pre+1` mà không phải `crlen+1` vì trong trường hợp `f()` có điều kiện ==...
			// ... `crlen` sẽ bị đúp khi chạy vào đây
			if (a[i] == b[j])
				dp[j] = pre + 1;
		}
	}
	//
	return *max_element(dp, dp+bl);
}

// driver
int main() {
	// inp
	cin >> al >> bl;
	for (int i = 0; i < al; i++) cin >> a[i];
	for (int i = 0; i < bl; i++) cin >> b[i];
	//
	cout << calc([](int i, int j){
		return i <= j;
	}) << endl;
	// returns
	system("pause");
	return 0;
}
