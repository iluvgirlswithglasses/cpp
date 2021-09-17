#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

// io
ofstream out;
// basic data
int n; int * arr;
// mika level data
// edges count can be always = n - 1
// but I can't prove that
vector<int*> edges;

// this dfs search for the first vertice by going back those vector
int get_first_vertice(int v) {
    for (int * i: edges) {
        if (i[1] == v) {
            return get_first_vertice(i[0]);
        }
    }
    // if there is no edges to go next => this is the first vertice
    return v;
}

void dfs(int v) {
    out << arr[v] << " ";
    for (int * i: edges) {
        if (i[0] == v)
            dfs(i[1]); return;
    }
}

// calc
void calc() {
    // we can start from any random vertice
    dfs(get_first_vertice(0));
}

// graph trans
bool is_connected(int a, int b) {
    if (a * 2 == b) return true;
    if (a % 3 == 0 && a / 3 == b) return true;
    return false;
}

void gen_graph() {
    // get every pair
    // since those are directed vectors
    // (a, b) pair is different from (b, a) pair
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (is_connected(arr[i], arr[j])) {
                edges.push_back(
                    new int[2]{i, j}
                );
            }
        }
    }
}

void print_graph() {
    for (int * i: edges) {
        printf("%d %d %d %d\n", i[0], i[1], arr[i[0]], arr[i[1]]);
    } cout << endl;
}

// drivers
void get_inp() {
    // out
    out.open("out.txt");
    // inp
    ifstream inp; inp.open("inp.txt");
    inp >> n; arr = new int[n];
    for (int i = 0; i < n; i++) {
        inp >> arr[i];
    }
}

int main() {
    //
    get_inp();
    gen_graph();
    // test
    calc();
    //
    return 0;
}
