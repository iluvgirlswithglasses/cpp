#include <algorithm>
#include <vector>
#include <fstream>
#include <iostream>
using namespace std;

// init
int n;
int typsS;
vector<int> typs;

void calc() {
	int * res = new int[typsS];
	for (int i = 0; i < typsS; i++) res[i] = 0;
	// calculated sum
	int s = 0;
	// currently using price type
	int cr = 0;
	// the loop
	while (true) {
		int temp = s + typs[cr];
		res[cr] += 1;
		// return condition matched
		if (temp == n) {
			for (int i = 0; i < typsS; i++) {
				printf("%d %d\n", typs[i], res[i]);
			}
			return;
		}
		// can't use current price type anymore
		if (temp > n) {
			// move on next price type
			// continue the loop without change
			res[cr] -= 1;
			cr += 1;
			continue;
		}
		// continue the loop
		s = temp;
	}
}

int main() {
	// io
	ifstream inp; inp.open("inp.txt"); int tracer;
	inp >> n;
	while (inp >> tracer) typs.push_back(tracer);
	typsS = typs.size();
	sort(typs.begin(), typs.end(), greater<>());
	// calc
	calc();
	// test
	// return
	getchar();
	return 0;
}
