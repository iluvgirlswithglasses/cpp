
// đây là người ân nhân đã khai sáng cho chúng ta system("pause")
// đội ơn khuc_tuan
// stackoverflow cũng không bằng anh

#include <bits/stdc++.h>
using namespace std;

int n;
int a[8][10010];
long long _F[1<<8], _G[1<<8];
int inf = 1e9;
int ds[8][100], nd[8];
int coduong = false;
int zz = -1000000000;

int main() {
    scanf("%d", &n);
    for(int i=0;i<8;++i)
        for(int j=1;j<=n;++j) {
            scanf("%d", a[i]+j);
            if(a[i][j]>=0) coduong = true;
            if(a[i][j]<0) zz = max( zz, a[i][j]);
        }

    if(!coduong) {
        cout << zz << endl;
        return 0;
    }

    for(int base=0;base<8;++base) {
        nd[base] = 0;
        for(int bit=0;bit<(1<<8);++bit) {
            bool ok = true;
            for(int i=0;i+1<8;++i) if( i!=base && (bit&(1<<i))!=0 && (bit&(1<<(i+1)))!=0 ) ok = false;
            if(ok) ds[base][nd[base]++] = bit;
        }
        //cout << nd[base] << endl;
    }
    long long *G = _G, *F = _F;
    for(int j=1;j<=n;++j) for(int i=0;i<8;++i) {
        memset( G, 0, sizeof(_G));
        for(int t=0;t<nd[i];++t) {
            int bit = ds[i][t];
            long long &r = G[bit];
            int zz = bit & (1<<i);
            int nb = bit ^ zz;
            int tmp = (zz!=0) ? a[i][j] : 0;
            r >?= F[nb] + tmp;
            nb |= 1<<i;
            if((bit&(1<<i))==0) r >?= F[nb] + tmp;
        }
        long long * tmp = G; G = F; F = tmp;
    }
    cout << *max_element(F, F+(1<<8)) << endl;
    //system("pause");
    return 0;
}
