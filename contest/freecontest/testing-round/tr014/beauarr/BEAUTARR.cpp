#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    vector<int> a(n);
    for(int i = 0; i < n; ++i)
        scanf("%d", &a[i]);

    int maxA = *max_element(a.begin(), a.end());

    vector<int> cnt(maxA+1, 0);

    long long ans = 0;
    int l = 0;

    bool isGood = true;
    for(int r = 0; r < n; ++r) {
        ++cnt[a[r]];
        if (cnt[a[r]] > 2)
            isGood = false;

        while (!isGood) {
            if (cnt[a[l]] > 2)
                isGood = true;
            --cnt[a[l]];
            ++l;
        }
        cout << l << " " << r << endl;
        ans += r-l+1;
    }

    printf("%lld", ans);
    //
    cin >> n;
    return 0;
}
