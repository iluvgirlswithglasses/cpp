
/*
author: 	iluvgirlswithglasses 
github: 	https://github.com/iluvgirlswithglasses 
created:	Mon Sep 26 19:18:32 2022
tab-width:	4 spaces

 /\_/\
( o.o )
 > ^ <

I sexually identify myself as an Attack Helicopter
BTW I use Arch
*/

#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

const int N = 1007;

struct Student {
	int a, b, id;
} s[N];

int n, a, b, c;
set<int> res;

void insert(int l, int r) {
	for (int i = l; i < r; i++)
		res.insert(s[i].id);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	cin >> n >> a >> b >> c;
	for (int i = 0; i < n; i++) {
		cin >> s[i].a;
		s[i].id = i+1;
	}
	for (int i = 0; i < n; i++)
		cin >> s[i].b;
	// tiêu chí 1
	sort(s, s+n, [](Student &i, Student &j){
		if (i.a == j.a) return i.id < j.id;
		return i.a > j.a;
	});
	insert(0, a);
	// tiêu chí 2
	sort(s+a, s+n, [](Student &i, Student &j){
		if (i.b == j.b) return i.id < j.id;
		return i.b > j.b;
	});
	insert(a, a+b);
	// tiêu chí 3
	sort(s+a+b, s+n, [](Student &i, Student &j){
		if (i.a + i.b == j.a + j.b) return i.id < j.id;
		return i.a + i.b > j.a + j.b;
	});
	insert(a+b, a+b+c);
	//
	for (int i: res) cout << i << " ";
	cout << "\n";
	return 0;
}
