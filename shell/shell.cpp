#include <iostream>
using namespace std;

int n;

int main() {
    while (true) {
        cin >> n; n ^= 1;
        cout << n << "\n";
    }
    return 0;
}
