#include<cstdio>
#include<cstring>
#include<iostream>
#define MAX   1001000
#define FOR(i,a,b) for (int i=(a),_b=(b);i<=_b;i=i+1)
#define REP(i,n) for (int i=0,_n=(n);i<_n;i=i+1)
using namespace std;
const int mod=(int)1e9+7;
char a[MAX];
int n;
int main(void) {
    int res=0;
    scanf("%s",a+1);
    n=strlen(a+1);
    int s=0;
    FOR(i,1,n) {
        s=(10LL*s + 1LL*i*(a[i]-'0'))%mod;
        res=(res+s)%mod;
    }
    printf("%d",res);
    cin >> n;
    return 0;
}
