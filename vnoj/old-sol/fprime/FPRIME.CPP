#include <iostream>
#include <stdio.h>
using namespace std;

const int N = 1e7+7, K = 1e6+7;
bool er[N]; // er[i] == true --> er[i] is not prime

void eratosthenes() {
    er[0] = true;
    er[1] = true;
    for (int i = 2; i < N; i++) {
        if (!er[i]) {
            for (long long j = (long long) i * i; j < N; j+=i) {
                er[j] = true;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    eratosthenes();
    //
    int k; scanf("%d", &k);
    //
    while (k--) {
        int i; scanf("%d", &i);
        if (!er[i]) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    // 
    return 0;
}
