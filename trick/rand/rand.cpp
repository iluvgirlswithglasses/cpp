#include <bits/stdc++.h>
using namespace std;


unsigned long long llrand() {
    unsigned long long r = 0;

    for (int i = 0; i < 5; ++i) {
        r = (r << 15) | (rand() & 0x7FFF);
    }
    // write as many more F, like 0xFFFFFFFFFFFFFFFFFFULL ...
    // ... to gen greater number
    return r & 0xFFFFFFFFFULL;
}

int main() {
	srand((unsigned) time(0));
	cout << llrand();
	//
	getchar();
	return 0;
}
