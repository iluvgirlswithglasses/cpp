#include <iostream>
#include <fstream>
using namespace std;

//@ vars
const int nlim = 1e5;
const int wlim = 1e5;
// n = items; w = max weight;
int n, w;
// the array that gonna give us result
int dp[wlim];


//@ calc
ifstream inp("inp.txt");

int calc() {
	int weight, val;
	// loop qua từng item
	while (n--) {
		inp >> weight >> val;
		// loop qua từng weight có thể thực hiện được
		// đi ngược để dùng lại kết quả cũ
		for (int j = w; j >= 0; j--) {
			// weight trước đó = weight đang duyệt - weight item
			int pre = j - weight;
			// nếu bây giờ pre < 0 
			// --> loop thêm cũng sẽ < 0 vì j giảm dần
			if (pre < 0) break;
			//
			dp[j] = max(dp[j], dp[pre] + val);
		}
	}
	//
	return dp[w];
}


//@ drivers
int main() {
	inp >> w >> n;
	cout << calc() << endl;
	//
	system("pause");
	return 0;
}

