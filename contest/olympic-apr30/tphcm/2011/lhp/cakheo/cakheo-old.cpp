#include <climits>
#include <math.h>
#include <algorithm>
#include <list>
#include <fstream>
#include <iostream>
using namespace std;

// global vars
int ** tiles; int rows = 2;
int n, p;

// use this instead of cout in real test
ofstream out;

// initializers
void init() {
    tiles = new int*[rows];
    out.open("cakheo.out");
}

// perf
int call_count = 0;
int * recursion(int leg, int col) {
    call_count += 1;
    // returns: int[2]{max_sum, min_sum};
    // leg: which leg will walk in this call {0, 1}
    // col: which column is the leg standing on

    // if completed
    if (col < 0) return new int[2]{0, 0};
    // if not
    int next_leg = (leg + 1) % 2;
    // recursion
    int largest = INT_MIN;
    int smallest = INT_MAX;
    //
    for (int i = col - 1; i >= col - p; i--) {
        int * route = recursion(next_leg, i);
        if (route[0] > largest) largest = route[0];
        if (route[1] < smallest) smallest = route[1];
    }
    // best child res + this val
    return new int[2]{largest + tiles[leg][col], smallest + tiles[leg][col]};
}

int calc() {
    // best res: max(abs(max_sum), abs(min_sum));
    list<int*> raw_res = {recursion(0, n), recursion(1, n)};
    list<int> res;
    //
    for (int * i: raw_res) {
        res.push_back(
            max(abs(i[0]), abs(i[1]))
        );
    }
    //
    return *max_element(res.begin(), res.end());
}

// io
void get_inp() {
    ifstream inp; inp.open("cakheo.inp");
    //
    inp >> n; inp >> p;
    //
    for (int i = 0; i < rows; i++) {
        tiles[i] = new int[n + 1];
        for (int j = 0; j < n; j++) inp >> tiles[i][j];
        tiles[i][n] = 0;
    }
}

// debugs
void print_tiles() {
    cout << "tiles:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < n; j++) {
            cout << tiles[i][j] << " ";
        } cout << endl;
    } cout << endl;
}

// drivers
int main() {
    //
    init();
    get_inp();
    cout << calc() << endl;
    //
    return 0;
}
