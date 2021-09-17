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

// biggest_res[leg][j] == best result of single leg once reach tile j
int ** biggest_res;
int ** lowest_res;

// use this instead of cout in real test
ofstream out;

// initializers
void init() {
    tiles = new int*[rows];
    biggest_res = new int*[rows];
    lowest_res = new int*[rows];
    out.open("cakheo.out");
}

// utils
void init_phase(int i) {
    for (int leg = 0; leg < 2; leg++) {
        if (i < p) {
            biggest_res[leg][i] = tiles[leg][i];
            lowest_res[leg][i] = tiles[leg][i];
        } else {
            biggest_res[leg][i] = INT_MIN;
            lowest_res[leg][i] = INT_MAX;
        }
    }
}

// perf
void calc() {
    // dynamic
    for (int i = 0; i < n + 1; i++) {
        init_phase(i);
        //
        for (int leg = 0; leg < 2; leg++) {
            for (int j = max(0, i - p); j < i; j++) {
                int other_leg = (leg + 1) % 2;
                // step from the other => this
                if (biggest_res[leg][i] < biggest_res[other_leg][j] + tiles[leg][i]) {
                    biggest_res[leg][i] = biggest_res[other_leg][j] + tiles[leg][i];
                }
                // reverse of biggest case - the negative case
                if (lowest_res[leg][i] > lowest_res[other_leg][j] + tiles[leg][i]) {
                    lowest_res[leg][i] = lowest_res[other_leg][j] + tiles[leg][i];
                }
            }
        }
    }
}

// io
void get_inp() {
    ifstream inp; inp.open("cakheo.inp");
    //
    inp >> n; inp >> p;
    //
    for (int i = 0; i < rows; i++) {
        tiles[i] = new int[n + 1];
        biggest_res[i] = new int[n + 1];
        lowest_res[i] = new int[n + 1];
        //
        for (int j = 0; j < n; j++) {
            inp >> tiles[i][j];
        }
        //
        tiles[i][n] = 0;
    }
}

// debugs
void print_obj(int ** obj) {
    cout << "obj:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < n + 1; j++) {
            cout << obj[i][j] << " ";
        } cout << endl;
    } cout << endl;
}

// drivers
int main() {
    //
    init();
    get_inp();
    //
    calc();
    int * res = new int[4]{
        abs(biggest_res[0][n]), abs(biggest_res[1][n]), abs(lowest_res[0][n]), abs(lowest_res[1][n])
    };
    //
    cout << *max_element(res, res + 4);
    return 0;
}
