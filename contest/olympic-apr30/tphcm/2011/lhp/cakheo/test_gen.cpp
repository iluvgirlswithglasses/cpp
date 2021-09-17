#include <algorithm>
#include <time.h>
#include <random>
#include <fstream>
using namespace std;

// ori test
/*
7 3
0 7 7 -4 5 9 2
1 6 2 -2 -3 2 -1
*/

int main() {
    ofstream out; out.open("cakheo.inp");
    // roll
    srand((unsigned) time(0));
    //
    int n = 7 + (rand() % 120);
    int p = 1 + (rand() % min(50, n));
    //
    out << n << " " << p << "\n";
    //
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            out << (rand() % 32) - 16 << " ";
        } out << endl;
    }
    //
    printf("n = %d\n", n);
    printf("p = %d\n", p);
    return 0;
}
