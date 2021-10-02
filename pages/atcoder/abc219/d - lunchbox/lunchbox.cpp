#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

#define pi pair<int, int>
#define st first
#define nd second

const int N = 302, I = 302;
int n, x, y, dp[I][I];
pi a[N];

int calc() {
    // duyệt theo item trước để đảm bảo k bị trùng
    for (int _k = 0; _k < n; _k++) {
        pi &k = a[_k];
        // đi ngược để không bị dùng kết quả của chính nó
        // chọn pre rồi tính gốc, nếu k dp sẽ có kích thước 600x600
        for (int pre_i = x; pre_i >= 0; pre_i--) 
        for (int pre_j = y; pre_j >= 0; pre_j--) {
            int i = min(x, pre_i + k.st),
                j = min(y, pre_j + k.nd);
            dp[i][j] = min(dp[i][j], dp[pre_i][pre_j] + 1);
        }
    }
    if (dp[x][y] > n) return -1;
    return dp[x][y];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // init
    for (int i = 0; i < I; i++) 
    for (int j = 0; j < I; j++) 
        dp[i][j] = I<<2;
    dp[0][0] = 0;
    // io
    cin >> n >> x >> y;
    for (int i = 0; i < n; i++)
        cin >> a[i].st >> a[i].nd;
    // calc
    cout << calc() << "\n";
    // debug
    /*
    for (int i = 0; i <= 8; i++) {
        for (int j = 0; j <= 8; j++) {
            cout << dp[i][j] << "\t";
        } cout << "\n";
    }
    */
    return 0;
}
