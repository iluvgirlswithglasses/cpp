#include <algorithm>
#include <set>
#include <list>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

// io
ofstream out;
// basic data
int n;

// main
vector<int> get_division(int a) {
    vector<int> res;
    for (int i = 1; i <= a; i++) {
        if (a % i == 0) res.push_back(i);
    }
    //
    return res;
}

void calc() {
    list<int> res;
    // dfs
    list<int> q = {n};  // queue
    while (!q.empty()) {
        int cr = q.front();
        q.pop_front();
        // case == 0
        if (cr == 0) continue;
        // cr != 0 => division eh !
        vector<int> d = get_division(cr);
        for (int i = 0; i < (d.size() + 1) / 2; i++) {
            int k = (d[i] - 1) * (d[d.size() - 1 - i] + 1);
            //
            if (find(res.begin(), res.end(), k) == res.end()) {
                res.push_back(k);
                q.push_back(k);
            }
        }
    }
    //
    res.sort([](int i, int j){
         return i < j;}
    );
    for (int i: res) {
        out << i << " ";
        cout << i << " ";
    }
}

// drivers
void init_io() {
    //
    ifstream inp; inp.open("inp.txt");
    inp >> n;
    //
    out.open("out.txt");
}

int main() {
    init_io();
    calc();
    //
    return 0;
}
