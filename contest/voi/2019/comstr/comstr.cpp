/*
bài này lấy 70% dễ vc

subtask 1: gen s2 từ m1, m2 rồi so s2 với s1 ra đáp án
subtask 2: vét cạn s[0:m2+m1] ra s[i] rồi so với s1 ra đáp án
*/
#include <iostream>
using namespace std;

const int M = 1e5+7;
int m, al, bl, r;
string s;

// độ dài fibo tối đa được tạo ra từ A và B
const int N = 3e5+7;
int n;
// giả sử F là string được tạo từ A và B
// loc[i] trả về vị trí gốc trong khoảng [0:A+B) của F[i]
short loc[N];

void genloc() {
	for (int i = 0; i < bl+al; i++) 
		loc[i] = s[i];
	n = bl + al;
	//
	int pre = bl;
	while (n < m) {
		
	}
}

int calc() {
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> al >> bl >> r;
	cin >> s;
	genloc();
	cout << calc() << "\n";
	return 0;
}
