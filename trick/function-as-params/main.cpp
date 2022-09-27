#include <iostream>
using namespace std;

void func() {
	cout << "func is called\n";
}

void para_func(int n) {
	cout << "para_func is passed: " << n << endl;
}

void call_func(void (*f)()) {
	(*f)();
}

void call_both_func(void (*f1)(), void (*f2)(int)) {
	(*f1)();
	(*f2)(2);
}

int main() {
	// perform
	call_func(func);
	call_both_func(func, para_func);
	call_func([](){cout << "lambda\n";});
	return 0;
}
