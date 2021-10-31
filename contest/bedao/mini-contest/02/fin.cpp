/*
    author:    Newplayers12
    created:   Saturday 04-09-2021  10:34:11
*/
#include <bits/stdc++.h>
using namespace std;
 
#define _Phuong ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0)
set<long long> s;
int main()
{
    _Phuong;
    int test;
    cin >> test;
    set<long long>::iterator it;
 
    while(test--){
        int t;
        cin >> t;
        if (t == 1){
            long long v;
            cin >> v;
            if (v == 0) continue;
            it = s.find(-v);
            if (it == s.end()){
                s.insert(-v);
            } else {
                s.erase(it);
            }
        } else {
            long long x = 0;
            long long v;
            cin >> v;
            bool can = true;
            long long dem = 0;
            while (x < v){
                it = s.lower_bound(- x - 1);
                if (it == s.end()){
                    can = false;
                    break;
                } else {
                    if (it == s.begin()){
                        long long dis = v - x;
                        long long num = -(*it);
                        dem += (dis + num - 1) / num;
                        break;
                    } else {
                        auto prev = --it;
                        ++it;
                        long long dis = min(-(*prev) - x - 1, v - x);
                        long long num = -(*it);
                        dem += (dis + num - 1) / num;
                        x += ((dis + num - 1) / num) * (num);
                    }
                }
            }
            if(!can){
                cout << -1 << '\n';
            } else {
                cout << dem << '\n';
            }
        }
    }
    return 0;
}