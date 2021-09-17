#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;

#define N 100000

int x[N+1], a[N], n, lis[N], lds[N];

void LIS() {
    fill(x+1, x+n+1, INT_MAX);
    x[0] = INT_MIN; int maxlen = 0;
    for(int i = 0; i < n; ++i) {
        int p = lower_bound(x, x+maxlen+1, a[i]) - x;
        lis[i] = p;
        maxlen = max(maxlen, p);
        x[p] = min(x[p], a[i]);
    }
}

void LDS() {
    fill(x+1, x+n+1, INT_MAX);
    x[0] = INT_MIN; int maxlen = 0;
    for(int i = n-1; i >= 0; --i) {
        int p = lower_bound(x, x+maxlen+1, a[i]) - x;
        lds[i] = p;
        maxlen = max(maxlen, p);
        x[p] = min(x[p], a[i]);
    }
}

bool enter() {
    if(scanf("%d", &n) == EOF) return 0;
    for(int i = 0; i < n; ++i) scanf("%d", a+i);
    return 1;
}

void print() {
    int res = 0;
    for(int i = 0; i < n; ++i) 
        res = max(res, 2*min(lis[i], lds[i]) - 1);
    printf("%d\n", res);
}

int main() {
    enter();
    LIS(); LDS();
    print();
    return 0;
}