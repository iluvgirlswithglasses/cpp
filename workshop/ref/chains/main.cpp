#include <algorithm>
#include <list>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

//
int n;
int * arr;

// funcs
// FIXME
// we can completely melt 2 or more chains
// not just one
int calc() {
	int t = n - 1;
	// the connection we have left
	int conn = n - 1;
	for (int i = 0; i < n; i++) {
		// if there is enough space after we destroy the chain
		if (arr[i] <= conn - 1) {
			conn -= 1 + arr[i];
			t -= 1;
		}
	}
	return t;
}

// inp
class Inp {
public:
	void get(); 
	void test();
};
void Inp::get() {
	ifstream inp; inp.open("inp.txt");
	inp >> n; arr = new int[n];
	for (int i = 0; i < n; i++) inp >> arr[i];
}
void Inp::test() {
	for (int i = 0; i < n; i++) 
		cout << arr[i] << " "; cout << endl;
}

// drivers
int main() {
	Inp inp = Inp(); inp.get();
	cout << calc();
	//
	getchar();
	return 0;
}
