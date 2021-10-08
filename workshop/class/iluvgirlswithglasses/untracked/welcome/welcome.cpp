#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

// some const
const int TIME = 0, FAV = 1, PRICE = 2;

//
vector<int*> arr;

// 
bool comparator(int * res, int cr, int pair) {
	return (
		// if find a greater price
		res[pair] + arr[cr][PRICE] > res[cr] &&
		// only performable if delta time >= delta fav
		// note: cr fav is alway greater than the pair one
		(arr[cr][TIME] - arr[pair][TIME]) >= (arr[cr][FAV] - arr[pair][FAV])
	);
}

void calc() {
	// the simplest form of dynamic 
	int * res = new int[arr.size()];
	for (int i = 0; i < arr.size(); i++) {
		// init
		res[i] = 0;
		//
		for (int j = 0; j < i; j++) {
			// cr & pair comparator
			// always true if compare to the initializer: {0, 0, 0}
			if (
				comparator(res, i, j)
			) {
				res[i] = res[j] + arr[i][PRICE];
			}
		}
	}
	cout << *max_element(res, res + arr.size());
}

// io stream API
class Inp {
	void sorter();
public:
	void get();
	void test();
};

void Inp::get() {
	// just to make the init for res and lst in calc()
	arr.push_back(new int[3]{0, 0, 0});
	//
	ifstream inp; inp.open("inp.txt");
	int n; inp >> n;
	// here the guests
	for (int i = 0; i < n; i++) {
		int t, s, p;
		inp >> t; inp >> s; inp >> p;
		// s <= t; if not, that guest is redundant
		if (s > t) continue;
		arr.push_back(new int[3]{t, s, p});
	}
}

void Inp::test() {
	for (int * i: arr) {
		for (int j = 0; j < 3; j++) {
			cout << i[j] << " ";
		} cout << endl;
	}
}

//
int main() {
	// inp
	Inp inp = Inp(); 
	inp.get(); 
	sort(arr.begin(), arr.end(), [](const int * i, const int * j) {
		return i[0] < j[0];
	});
	// calc
	calc();
	// returns
	getchar();
	return 0;
}
