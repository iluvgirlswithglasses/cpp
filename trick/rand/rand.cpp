#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long

ull llrand_0() {
    ull r = 0;
    for (int i = 0; i < 5; i++) {
        r = (r << 15) | (rand() & 0x7FFF);
    }
    // write as many more F, like 0xFFFFFFFFFFFFFFFFFFULL ...
    // ... to gen greater number
    return r & 0xFFFFFFFFFULL;
}

ull llrand_1() {
    ull r = 0;
    // each bit has 50% chance to be turned on
    for (int i = 0; i < 64; i++)
        if (rand() % 2) r |= 1<<i;
    return r;
}

int main() {
	srand(chrono::system_clock::now().time_since_epoch().count());
    ull n; cin >> n;
	cout << (llrand_1() % n) << "\n";
	return 0;
}
