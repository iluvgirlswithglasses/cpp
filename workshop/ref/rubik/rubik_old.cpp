#include <string>
#include <algorithm>
#include <list>
#include <iostream>
#include <fstream>
using namespace std;

// opers
int * arr; int n = 8;
//
ofstream out;

// swapping stuffs
void method_a(int * arr) {
	// swap 0-3 -> 4-7
	for (int i = 0; i < n/2; i++) {
		arr[i] ^= arr[i+4];
		arr[i+4] ^= arr[i];
		arr[i] ^= arr[i+4];
	}
}

void method_b(int * arr) {
	for (int i = 0; i < 2; i++) {
		int temp = arr[i*4 + 3];	// last number of i row
		for (int j = 2; j >= 0; j--) {
			arr[i*4 + j + 1] = arr[i*4 + j];	// shift
		}
		//
		arr[i*4] = temp;
	}
}

void method_c(int * arr) {
	int a = arr[1], b = arr[2], c = arr[5], d = arr[6];
	arr[2] = a; arr[5] = b; arr[6] = c; arr[1] = d;
}

// utils
void apply_method(int k, int * arr) {
	// 0: A, 1: B, 2: C
	switch (k) {
		case 0: method_a(arr); return;
		case 1: method_b(arr); return;
		case 2: method_c(arr); return;
	}
}

int * clone_arr(int * arr) {
	int * res = new int[n];
	for (int i = 0; i < n; i++) res[i] = arr[i];
	return res;
}

bool compare_arr(int * cr) {
	for (int i = 0; i < n; i++) {
		if (cr[i] != i) return false;
	} 
	return true;
}

// calc
void print_arr(int * a);
void bfs() {
	// success without doing anything
	if (compare_arr(arr)) {
		cout << '0' << endl;
		return;
	}

	// store steps as strings
	list<string> steps; steps.push_back("");
	// basic bfs
	list<int*> queue; queue.push_back(arr);
	//
	list<int> depths; depths.push_back(0);
	int loop_count = 0;
	while (true) {
		loop_count += 1;
		int depth = depths.front();
		depths.pop_front();
		// since the queue don't need to be empty when the program is done
		// calc

		// parent
		string parent_step = steps.front();
		steps.pop_front();
		int * parent_state = queue.front();
		queue.pop_front();

		//
		for (int i = 0; i < 3; i++) {
			// new step
			string cr_step = parent_step;
			cr_step += 'A' + i; // write step

			// new stage
			int * cr_state = clone_arr(parent_state);
			apply_method(i, cr_state);
			// print_arr(cr_state);
			// check
			if (compare_arr(cr_state)) {
				printf("depth = %d, loop count = %d\n", depth, loop_count);
				// success
				// cout << cr_step.length() << endl;
				// for (int i = 0; i < cr_step.length(); i++) cout << cr_step.at(i) << endl;
				return;
			}

			// precedents
			for (int j = 0; j < 3; j++) {
				steps.push_back(cr_step);
				queue.push_back(cr_state);
				depths.push_back(depth + 1);
			}
		}
	}
}

// drivers
void init() {
	arr = new int[n];
}

void get_inp() {
	//
	ifstream inp; inp.open("rubik.inp"); out.open("rubik.out");
	//
	for (int i = 0; i < n; i++) {
		int temp; inp >> temp; temp -= 1;
		arr[i] = temp;
	}
}

void print_arr(int * a) {
	cout << "print_arr: ";
	for (int i = 0; i < n; i++) cout << a[i] << " "; cout << endl;
}

void test_method(void (*f)(int*)) {
	int * test = clone_arr(arr);
	(*f)(test);
	cout << "def:\n"; print_arr(arr);
	cout << "tes:\n"; print_arr(test);
}

int main() {
	init();
	get_inp();
	bfs();
	// test
	// test_method(method_a);
	//
	getchar();
	return 0;
}
