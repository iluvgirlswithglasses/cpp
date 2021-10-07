#include <bits/stdc++.h>
using namespace std;

int MCCreated = 0;
int MCDeleted = 0;
struct MyClass {
	MyClass() {MCCreated += 1;}
	~MyClass() {MCDeleted += 1;}
};

//
void delete_pointer() {
	printf("delete pointer\n");
	int * n = new int(12);
	delete n;
	cout << *n << endl << endl;
}

void delete_pointer_array() {
	printf("delete pointer array\n");
	int len = 4;
	int * arr = new int[len]{10, 20, 60, 70};
	delete[] arr;
	for (int i = 0; i < len; i++) cout << arr[i] << " ";
	cout << endl << endl;
}

void delete_pointer_of_class_array() {
	printf("delete array of class pointers\n");
	int len = 4;
	MyClass * arr = new MyClass[len];
	//
	delete[] arr;
	printf("created:%d\ndeleted:%d\n\n", MCCreated, MCDeleted);
}

void delete_array_of_pointers() {
	printf("delete array of pointers\n");
	int len = 6;
	int a = 10, b = 20, c = 30, d = 40, e = 50, f = 60;
	//
	int ** arr = new int*[len]{&a, &b, &c, &d, &e, &f};
	for (int i = 0; i < len; i++) cout << *arr[i] << " "; cout << endl;
	//
	for (int i = 0; i < len; i++) delete arr[i];
	delete[] arr;
	//
	for (int i = 0; i < len; i++) cout << *arr[i] << " ";
	cout << endl << endl;
}

int main() {
	delete_pointer();
	delete_pointer_array();
	delete_array_of_pointers();
	delete_pointer_of_class_array();
	//
	getchar();
	return 0;
}
