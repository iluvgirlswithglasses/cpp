/*
    author:    Newplayers12
    created:   Tuesday 31-08-2021  09:53:28
*/
#include <bits/stdc++.h>
using namespace std;

#define _Phuong ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
const int MXN = 1e6;
int flag[MXN + 1] = {0};
void sieve(){
    flag[1] = -1;
    flag[0] = -1;
    for(int i = 2; i*i <= MXN; ++i){
        if (flag[i] == 0){
            for(int j = i*i; j <= MXN; j += i){
                flag[j] = i;
            }
        }
    }
}

int cnt[MXN + 1];

int main()
{
    _Phuong;
    int test;
    cin >> test;
    sieve();
    while(test--){
        memset(cnt, 0, sizeof(cnt));
        int n;
        cin >> n;
        
        for(int i = 0; i < n; ++i){
            int a;
            cin >> a;
            if (a == 1) continue;
            while (flag[a] != 0){
                cnt[flag[a]] ++;
                a /= flag[a];
            } 
            if (a > 1){
                cnt[a] ++;
            }
        }
        bool ans = true;
        for(int i = 0; i < n; ++i){
            int a;
            cin >> a;
            if (a == 1) continue;
            while (flag[a] != 0){
                cnt[flag[a]] --;
                if (cnt[flag[a]] < 0 && flag[a] != 2 && flag[a] != 5){
                    ans = false;
                }
                a /= flag[a];
            }
            if (a > 1){
                cnt[a]--;
                if (cnt[a] < 0 && a != 2 && a != 5){
                    ans = false;
                }
            }
        }
        if (ans) cout << "finite"; else cout << "repeating";
        cout << '\n';
        
    }


    cerr << " \nTime: " <<  clock() / CLOCKS_PER_SEC << "ms";
    return 0;
}