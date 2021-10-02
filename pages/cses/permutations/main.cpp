#include <list>
#include <iostream>
using namespace std;

/* 
the strat for this is pretty dirty

first:
	you can see that there is no solution for the n<4 cases, except for n=1
	but in the n=4 case, the solution is this: 3 1 4 2

second:
	in order to generate n=4+1, we add 5 into the 4-case permutation like this:
	(3 1 4 2) 5
	and if we want to do n=5+1, we add 6 in the opposite to 5, like this:
	6 (3 1 4 2) 5
	and 7? like this:
	6 [(3 1 4 2) 5] 7
	easy right ?
*/


list<int> res = {3, 1, 4, 2};
void recursion(int n, int cr) {
	// break
	if (cr > n) return;
	//
	if (cr & 1) {
		res.push_back(cr);
	} else {
		res.push_front(cr);
	}
	recursion(n, cr + 1);
}

//
int main() {
	int n; cin >> n;
	if (n == 1) {
		cout << 1 << endl;
		return 0;
	}
	if (n < 4) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	//
	recursion(n, 5);
	for (int i: res) cout << i << " ";
	cout << endl;
	//
	return 0;
}
