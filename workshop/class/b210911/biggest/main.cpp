#include <string>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

// store number
int ** n = new int*[2];
// store len
int * s = new int[2];
// store longer number
int bigI = 0, smaI;

class Heir {
	bool * initiated = new bool[10];
public:
	vector<int> * res;
	int * counts;
	Heir(int i);
	bool handle_zero();
	void init(int cr);
	void comparator(int cr, int pair);
}; 

Heir::Heir(int len) {
	res = new vector<int>[len];
	counts = new int[len];
	for (int i = 0; i < 10; i++) initiated[i] = false;
}

bool Heir::handle_zero() {
	// where it found 0
	bool * rec = new bool[2]{false, false};
	// get each number
	for (int i = 0; i < 2; i++) {
		
		// check each digit in number
		for (int j = 0; j < s[i]; j++) {
			// if that digit in i number == 0
			if (n[i][j] == 0) {
				// record that 0 and go to next number
				rec[i] = true;
				break;
			}
		}
	}
	return rec[0] && rec[1];
}

void Heir::init(int cr) {
	counts[cr] = 0;
	int num = n[bigI][cr];
	// 0 is stupid
	if (num == 0) return;
	// there have been collections start with this number already
	if (initiated[num]) return;
	// all condition met 
	initiated[num] = true;
	// find the first num match in smaller number
	for (int i = 0; i < s[smaI]; i++) {
		if (n[smaI][i] == num) {
			// find first match
			counts[cr] = 1;
			res[cr].push_back(i);
			break;
		}
	}
}

void Heir::comparator(int cr, int pair) {
	// if cr <= pair => maybe cr = pair + 1
	if (counts[cr] > counts[pair]) return;
	if (res[pair].size() == 0) return;
	//
	for (int i = res[pair].back() + 1; i < s[smaI]; i++) {
		// if there is a match
		if (n[smaI][i] == n[bigI][cr] && counts[cr] <= counts[pair]) {
			counts[cr] = counts[pair] + 1;
			res[cr] = res[pair]; res[cr].push_back(i);
			break;
		}
	}
}

// printers
void print_res(Heir & res) {
	// mem
	int longest = *max_element(res.counts, res.counts + s[bigI]);
	// zero case
	if (longest == 0) {
		if (res.handle_zero()) {
			cout << 0;
			return;
		}
	}
	// 
	int best = -1;
	//
	for (int i = 0; i < s[bigI]; i++) {
		// if this have size == longest
		if (res.res[i].size() == longest) {
			string str = "";
			for (int j: res.res[i]) {
				str += to_string( n[smaI][j] );
			}
			// record the best
			int val = stoi(str);
			if (val > best) best = val;
		}
	}
	cout << best << endl;
}

void print_debug_res(Heir & res) {
	for (int i = 0; i < s[bigI]; i++) {
		printf("%d (%d): ", i, n[bigI][i]);
		for (int j: res.res[i]) {
			cout << j << " ";
		} cout << endl;
	}
}

// inp
class Inp {
public:
	void get();
	void test();
};

void Inp::get() {
	ifstream inp; inp.open("inp.txt");
	string str;
	for (int i = 0; i < 2; i++) {
		inp >> str;
		//
		s[i] = str.length();
		n[i] = new int[ s[i] ];
		for (int j = 0; j < s[i]; j++) {
			n[i][j] = str.at(j) - '0';
		}
	}
	if (s[1] > s[0]) bigI = 1;
	smaI = (bigI + 1) % 2;
}

// test funcs
void Inp::test() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < s[i]; j++) {
			cout << n[i][j];
		} cout << endl;
	}
	printf("%d %d\n", bigI, smaI);
}

// driver
void calc() {
	Heir res = Heir( s[bigI] );
	// qhd
	for (int i = 0; i < s[bigI]; i++) {
		//
		res.init(i);
		for (int j = 0; j < i; j++) {
			// insert comparator here
			res.comparator(i, j);
		}
	}
	print_res(res);
	print_debug_res(res);
}

int main() {
	Inp inp = Inp();
	inp.get();
	//
	calc();
	// test
	// return
	getchar();
	return 0;
}
