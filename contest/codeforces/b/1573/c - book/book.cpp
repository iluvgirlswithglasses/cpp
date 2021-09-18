
// change the bracket style...

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int N = 2e5+7;
int n, k[N];
vector<int> dep[N];	// dependencies :)

int calc()
// calc <= n all cases
// -1 happens if deadlock presents
{
	if (check_deadlock())
		return -1;
	return _calc();
}

int main() 
{
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--) 
	{
		cin >> n;
		memset(k, 0, n*sizeof(k[0]));
		//
		for (int i = 0; i < n; i++) 
		{
			cin >> k[i];
			dep[i].resize(k[i]);
			for (int j = 0; j < k[i]; j++) 
				cin >> dep[i][j];
		}
		//
		cout << calc() << "\n";
	}
	return 0;
}
