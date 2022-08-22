#include <iostream>
using namespace std;

#define ll long long

const int N = 2004, I = 1e9+7;
int m, n, q;
ll t[N][N<<1];  // m rows n cols

void update(int row, int p, int x) {
    t[row][n+p] += x;
    for (int i = n + p; i > 1; i >>= 1) {
        t[row][i >> 1] = max(t[row][i], t[row][i^1]);
    }
}

ll query(int row, int l, int r) {
    ll res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if (l & 1) res = max(res, t[row][l++]);
        if (r & 1) res = max(res, t[row][--r]);
    }
    return res;
}

/**
 * debug
 * */
void prf() {
    for (int i = 0; i < m; i++) {
        for (int j = n; j < (n << 1); j++) {
            cout << t[i][j] << " ";
        } cout << "\n";
    }
}

/**
 * drivers
 * */
void q_row() {
    int r, x; cin >> r >> x; r--;
    for (int i = 1; i <= (n<<1); i++) t[r][i] += x;
}

void q_col() {
    int c, x; cin >> c >> x; c--;
    for (int i = 0; i < m; i++) {
        update(i, c, x);
    }
}

void q_get() {
    int x1, y1, x2, y2; 
    cin >> y1 >> x1 >> y2 >> x2;
    x1--; y1--; x2--; y2--;
    //
    ll best = 0;
    for (int i = y1; i <= y2; i++) {
        best = max(best, query(i, x1, x2+1));
    }
    cout << best << '\n';
}

int main() {
    // ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> m >> n >> q;
    while (q--) {
        int t; cin >> t;
        switch (t) {
            case 1: q_row(); break;
            case 2: q_col(); break;
            case 3: q_get(); break;
            case 4: prf(); break;
        }
    }
    return 0;
}
