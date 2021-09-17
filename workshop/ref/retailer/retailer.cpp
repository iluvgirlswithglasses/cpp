#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

// global const
const int ID = 0;		// id
const int QUANT = 1;	// quantity
const int PRICE	= 2;	// nor price

// global vars
// item: int[3]{ID, QUANT, PRICE};
int ** items; int b;	// items needed
int ** offers; int s;	// offers count

// utils
int * get_item(int id) {
	for (int i = 0; i < s; i++) {
		int * item = items[i];
		if (item[ID] == id) return item;
	} return new int[3]{-1, -1, -1};
}

int get_off_price(int * off) {
	return off[off[0] * 2 + 1];
}

int calc_diff(int * off) {
	// calc the price diff between offer and default
	int def = 0;
	for (int i = 0; i < off[0]; i++) {
		int item_index = i*2 + 1;
		int * item = get_item(off[item_index]);
		// if item not exists
		if (item[0] == -1) continue;
		// item price * quantity
		def += item[PRICE] * off[item_index + 1];
	}
	// always > 0
	return def - get_off_price(off);
}

void sort_offers() {
	// sort by most advantage -> least advantage
	sort(offers, offers + s, [](int * a, int * b){
		return calc_diff(a) > calc_diff(b);
	});
}

bool finished() {
	for (int i = 0; i < b; i++) {
		int * item = items[i];
		if (item[QUANT] > 0) return false;
	} return true;
}

// check if offer is achievable
bool check_offer(int * off) {
	for (int i = 0; i < off[0]; i++) {
		int item_index = i*2 + 1;
		int * item = get_item(off[item_index]);
		// if item not exists in to-buy
		if (item[0] == -1) return false;
		// if needed quantity is lower than offer quantity
		if (item[QUANT] < off[item_index + 1]) return false;
	}
	return true;
}

bool handle_offer(int * off, int & total) {
	// check offer
	if (check_offer(off)) {
		total += get_off_price(off);
		// update item list
		for (int i = 0; i < off[0]; i++) {
			int item_index = i*2 + 1;
			//
			int * item = get_item(off[item_index]);
			item[QUANT] -= off[item_index + 1];
		}
		return true;
	}
	return false;
}

int calc(int & total) {
	int pre_total = total;
	for (int i = 0; i < s; i++) {
		int * off = offers[i];
		if (handle_offer(off, total)) break;
	}
	// if pre_total == total => no offer achieved
	if (pre_total == total) {
		// buy normally
		for (int i = 0; i < b; i++) {
			int * item = items[i];
			total += item[QUANT] * item[PRICE];
		}
	} else {
		// there is still offer to do
		// recursion
		if (finished()) {
			return total;
		} return calc(total);
	}
	// pre_total == total case
	return total;
}

int calc() {
	int total = 0;
	return calc(total);
}

// driver
void get_inp() {
	ifstream inp; inp.open("retailer.inp");
	ifstream off; off.open("offers.inp");
	// inp
	inp >> b; items = new int*[b];
	for (int i = 0; i < b; i++) {
		items[i] = new int[3];
		//
		for (int j = 0; j < 3; j++) {
			inp >> items[i][j];
		}
	}
	// offers
	off >> s; offers = new int*[s];
	for (int i = 0; i < s; i++) {
		// perfectly copy the offer data
		int n; off >> n;
		offers[i] = new int[2 + n*2];
		offers[i][0] = n;
		//
		for (int j = 0; j < n * 2 + 1; j++) {
			off >> offers[i][j + 1];
		}
	}
}

void test_inp() {
	cout << "items:\n";
	for (int i = 0; i < b; i++) {
		printf("%d %d %d\n", items[i][0], items[i][1], items[i][2]);
	} cout << endl;
	//
	cout << "offers:\n";
	for (int i = 0; i < s; i++) {
		for (int j = 1; j < offers[i][0] * 2 + 1; j++) {
			cout << offers[i][j] << " ";
		}
		cout << "/ price: " << get_off_price(offers[i]) << endl;
	} cout << endl;
}

void test_sorter() {
	cout << "sorted offers:\n";
	for (int i = 0; i < s; i++) {
		for (int j = 0; j < offers[i][0] * 2 + 2; j++) {
			cout << offers[i][j] << " ";
		} cout << endl;
	} cout << endl;
}

int main() {
	get_inp();
	sort_offers();
	cout << calc();
	//
	getchar();
	return 0;
}
