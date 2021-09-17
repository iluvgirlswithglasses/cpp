#include <iostream>
#include <algorithm>
using namespace std;

/*
dòng đầu tiên cho n đỉnh & m cạnh
m dòng tiếp theo cho ba số nguyên dương: u v w
miêu tả cạnh (u, v) có trọng số w

tìm cây khung nhỏ nhất của đồ thị

bài toán áp dụng:
.vnoi/fwater
*/

struct edge {
    int u, v, w;
};

const int N = 2e4, M = 1e5;
int n, m;
edge edges[M];

/**
 * dsu
 * */
int p[N];

void init_dsu() {
    for (int i = 0; i < n; i++) {
        p[i] = i;
    }
}

int find(int u) {
    if (p[u] == u) return u;
    p[u] = find(p[u]);
    return p[u];
}

bool join(int u, int v) {
    int a = find(u), b = find(v);
    if (a == b) return false;
    p[a] = b;
    return true;
}

/**
 * kruskal
 * */
int kruskal() {
    int res = 0;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v, w = edges[i].w;
        if (join(u, v)) res += w;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) 
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    sort(edges, edges + m, [](edge &i, edge &j){
        return i.w < j.w;
    });
    //
    init_dsu();
    cout << kruskal() << "\n";
    return 0;
}
