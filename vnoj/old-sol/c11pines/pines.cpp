
#include <algorithm>
#include <iostream>
using namespace std;

/*
Làm bằng tay:
Chặn phát triển của cây bé thứ nhì cho đến khi chiều cao của nó bằng a cây bé nhất
Lúc đó, số cây bé nhất sẽ là a + 1
Khi a < n: chặn phát triển của cây bé thứ nhì tiếp theo cho đến khi nào mọi cây đều có cùng chiều cao

Tính xem bao nhiêu ngày thì cao đều:
Số ngày cần thiết = (Độ cao lớn nhất cuối cùng - Độ cao bé nhất đầu tiên) / k
*/

#define lli long long

const int N = 1e5+7;
int n, k, arr[N];

void getinp() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr+n, [](int i, int j){
		return i < j;
	});
}

// hàm dưới đây có thể gộp chung với calc()
// nhưng để cho dễ quan sát và giải thích,
// mình viết riêng ra vậy

// kiểm tra xem bài toán có khả thi hay không
// bài toán chỉ khả thi nếu hiệu độ cao giữa hai cây bất kỳ với nhau
// là một số chia hết cho k
bool ok() {
	// 		abs(a - b) % k == 0
	// 		abs(b - c) % k == 0
	// --> 	abs(a - c) % k == 0
	// -->	cứ duyệt từng đôi thế này,
	//		nếu từ đầu đến cuối hiệu mỗi đôi điều chia hết cho k
	//		thì hiệu mỗi đôi bất kỳ trong mảng đều chia hết cho k
	for (int i = 1; i < n; i++) {
		// arr[i] > arr[i-1] đã sorted
		if ((arr[i] - arr[i-1]) % k != 0) return false;
	}
	return true;
}

// trường hợp bài toán khả thi:
// tính xem sau bao nhiêu ngày thì cây cao đều
lli calc() {
	// với max(arr[i]) == 1e9
	// và d = 10
	// thì xài long long là lựa chọn bắc buộc
	lli minhei = arr[0],
		maxhei = arr[n-1];
	//
	lli grow = 0;
	for (int i = 1; i < n; i++) {
		// với mỗi lần chặn phát triển cây thấp thứ nhì
		// những cây cao hơn cây thấp thứ nhì sẽ cao lên arr[i] - arr[i-1] đơn vị chiều cao
		// sau mỗi lần chặn, lần chặn tiếp theo phải chi ra thêm một lượng thời gian
		// bằng với lượng đã chi trước đó
		grow += arr[i] - arr[i-1];
		//
		maxhei += grow;
	}
	// Số ngày cần thiết = (Độ cao lớn nhất cuối cùng - Độ cao bé nhất đầu tiên) / k
	// Độ cao lớn nhất cuối cùng = arr[n-1] - grow
	// Vì trong quá trình làm n-1 cây bằng nhau cao bằng cây cuối cùng
	// cây cuối cùng không phát triển thêm 1 đơn vị nào cả,
	// nhưng grow thì vẫn được cộng thêm trong lần lặp ở trên
	return (maxhei - grow - minhei) / k;
}

int main() {
	//
	getinp();
	//
	if (ok()) {
		cout << calc() << endl;
	} else {
		cout << -1 << endl;
	}
	//
	system("pause");
	return 0;
}
