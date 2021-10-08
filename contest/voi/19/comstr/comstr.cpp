/*
bài này lấy 70% dễ vc

subtask 1: gen s2 từ m1, m2 rồi so s2 với s1 ra đáp án
subtask 2: vét cạn s[0:m2+m1] ra s[i] rồi so với s1 ra đáp án
*/
#include <iostream>
#include <algorithm>
using namespace std;

/**
 * vars & constraints
 * */
const int M = 1e5+7;
// al: a-length, or m1
// bl: b-length, or m2
// k:  al + bl
int m, k, al, bl, r;
string s;

// độ dài fibo tối đa được tạo ra từ A và B
const int N = 3e5+7;
int n;
// giả sử F là string được tạo từ A và B
// loc[i] trả về vị trí gốc trong khoảng [0:A+B) của F[i]
int loc[N];
int dp[N][26];


/**
 * init
 * */
void genloc() {
	n = k;
	for (int i = 0; i < n; i++)
		loc[i] = i;
	int pre = bl;
	while (n < m) {
		for (int i = 0; i < pre; i++) {
			loc[n+i] = loc[i];
		}
		int tmp = pre;
		pre = n;
		n += tmp;
	}
}

void compare() {
	for (int i = k; i < m; i++) {
		dp[loc[i]][s[i] - 'A']++;
	}
}


/**
 * perf
 * */
int geterr() {
	int ** f = new int*[k];
	for (int i = 0; i < k; i++) {
		int cr = dp[i][s[i] - 'A'],
			difbest = *max_element(dp[i], dp[i] + 26) - cr;
		f[i] = new int[2]{
			cr, difbest
		};
	}
	sort(f, f+k, [](int* i, int* j){
		return i[1] > j[1];
	});
	//
	int correct = 0;
	for (int i = 0; i < r; i++) {
		correct += f[i][0] + f[i][1]; delete[] f[i];
	}
	for (int i = r; i < k; i++) {
		correct += f[i][0]; delete[] f[i];
	}
	delete[] f;
	return (m-k) - correct;
}


/**
 * drivers
 * */
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> m >> al >> bl >> r; k = al + bl;
	cin >> s;
	genloc();
	compare();
	cout << geterr() << "\n";
	return 0;
}