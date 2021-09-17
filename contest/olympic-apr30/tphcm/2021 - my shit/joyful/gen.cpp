#include <bits/stdc++.h>
using namespace std;

ofstream out("joyful.inp");

unsigned long long llrand() {
    unsigned long long r = 0;

    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }
    // write as many more F, like 0xFFFFFFFFFFFFFFFFFFULL ...
    // ... to gen greater number
    return r & 0xFFFFFFFULL;
}

int irand() {
    return rand() % 10;
}

int main() {
	srand((unsigned) time(0));
    int n = 50000;
    //
    out << n << "\n";
    for (int i = 0; i < n; i++) {
        int a = llrand(), b = llrand(), c = llrand();
        if (rand() % 10 < 6) {
            out << a << " " << b << " " << a << " " << c << endl;
        } else {
            out << a << " " << b << " " << c << " " << b << endl;
        }
    }
	//
	return 0;
}
