#include <string>
#include <algorithm>
#include <list>
#include <fstream>
#include <iostream>
using namespace std;

// oper fields
int * arr; int n = 8;
ofstream out;

void init() {
	arr = new int[n];
	out.open("rubik.out");
}

// swapping stuffs
void method_a(int * arr) {
	// swap 0-3 -> 4-7
	for (int i = 0; i < n/2; i++) {
		arr[i] ^= arr[7 - i];
		arr[7 - i] ^= arr[i];
		arr[i] ^= arr[7 - i];
	}
}

void method_b(int * arr) {
	// row 1
	int temp = arr[3];
	for (int i = 2; i >= 0; i--) {
		arr[i + 1] = arr[i];
	}
	arr[0] = temp;
	// row 2;
	temp = arr[4];
	for (int i = 5; i < 8; i++) {
		arr[i - 1] = arr[i];
	}
	arr[7] = temp;
}

void method_c(int * arr) {
	int a = arr[1], b = arr[2], c = arr[5], d = arr[6];
	arr[2] = a; arr[5] = b; arr[6] = c; arr[1] = d;
}

void call_method(int i, int * arr) {
	switch (i) {
		case 0: method_a(arr); return;
		case 1: method_b(arr); return;
		case 2: method_c(arr); return;
	}
}

// utils
bool check_arr(int * arr) {
	for (int i = 0; i < n; i++) {
		if (arr[i] != i) return false;
	}
	// none mismatch
	return true;
}

int * clone_arr(int * arr) {
	int * res = new int[n];
	for (int i = 0; i < n; i++) res[i] = arr[i];
	return res;
}

// calc
void bfs() {
	list<int*> queue = {arr};
	list<string> steps = {""};
	//
	int loop_count = 0;
	while (true) {
		loop_count += 1;
		cout << loop_count << endl;
		//
		int * parent_arr = queue.front();
		queue.pop_front();
		//
		string parent_step = steps.front();
		steps.pop_front();
		// debug
		cout << "debug:\nstep: " << parent_step << "; state: ";
		for (int i = 0; i < n; i++) cout << parent_arr[i] << " "; cout << endl;
		//
		for (int i = 0; i < 3; i++) {
			//
			int * cr_arr = clone_arr(parent_arr);
			call_method(i, cr_arr);
			//
			string cr_step = parent_step;
			cr_step += 'A' + i;
			// if completed
			if (check_arr(cr_arr)) {
				cout << "done!\n";
				return;
			}
			// recursion
			queue.push_back(cr_arr);
			steps.push_back(cr_step);
		}
	}
}

// io
void get_inp() {
	ifstream inp; inp.open("rubik.inp");
	//
	for (int i = 0; i < n; i++) {
		int temp; inp >> temp; temp -= 1;	//
		arr[i] = temp;
	}
}

// debug
void call_debug(int k) {
	call_method(k, arr);
	// print
	char ch = 'A' + k;
	cout << "method " << ch << ":\n";
	// row 1
	for (int i = 0; i < 4; i++) {
		cout << arr[i] << " ";
	} cout << endl;
	// row 2
	for (int i = 0; i < 4; i++) {
		cout << arr[7 - i] << " ";
	} cout << endl; cout << endl;
}

void call_debug() {
	call_debug(1);
	call_debug(2);
	call_debug(0);
	call_debug(1);
	call_debug(2);
	call_debug(2);
	call_debug(1);
}

// drivers
int main() {
	init();
	get_inp();
	// test
	call_debug();
	// return
	getchar();
	return 0;
}
