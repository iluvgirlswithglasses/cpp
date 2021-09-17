#include<cstdio>

#define MOD 111539786LL
typedef long long LL;

class FibonacciMatrix {
    public:
        LL a[2][2];

        FibonacciMatrix() {
            a[0][0] = a[0][1] = a[1][0] = 1LL;
            a[1][1] = 0LL;
        }

        FibonacciMatrix(LL p, LL q, LL r, LL s) {
            a[0][0] = p; a[0][1] = q;
            a[1][0] = r; a[1][1] = s;
        }

        inline FibonacciMatrix operator % (const LL & mod) {
            return FibonacciMatrix(a[0][0] % mod, a[0][1] % mod, a[1][0] % mod, a[1][1] % mod);
        }

        inline FibonacciMatrix operator * (const FibonacciMatrix & mat) {
            return FibonacciMatrix(a[0][0] * mat.a[0][0] + a[0][1] * mat.a[1][0],
                    a[0][0] * mat.a[0][1] + a[0][1] * mat.a[1][1],
                    a[1][0] * mat.a[0][0] + a[1][1] * mat.a[1][0], 
                    a[1][0] * mat.a[0][1] + a[1][1] * mat.a[1][1]) % MOD;
        }

        inline FibonacciMatrix operator ^ (const int & n) {
            if(n == 1) return FibonacciMatrix();
            FibonacciMatrix res = *this ^ (n >> 1);
            return n & 1 ? res * res * FibonacciMatrix() : res * res;
        }
};

int main() {
    int tc; scanf("%d", &tc);
    while(tc--) {
        int n; scanf("%d", &n);
        printf("%lld\n", (FibonacciMatrix() ^ n).a[0][0]);
    }
    return 0;
}