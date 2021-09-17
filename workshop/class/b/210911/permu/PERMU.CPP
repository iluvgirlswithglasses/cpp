#include <fstream>
using namespace std;

const int N = 1e6+7;
int n; bool a[N];

int main() {
	ifstream inp("PERMU.INP");
	ofstream out("PERMU.OUT");
	//
	inp >> n;
	for (int i = 0; i < n; i++) {
		int v; inp >> v;
		if (v <= n) a[v] = true;
	}
	int c = 0;
	for (int i = 1; i <= n; i++)
		if (!a[i]) c++;
	out << c << "\n";
	return 0;
}
