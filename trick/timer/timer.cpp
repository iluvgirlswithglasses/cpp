#include <iostream>
#include <chrono>
using namespace std;

int main() {
	using namespace std::chrono;

	// put the timer and wait 'till timer stop command
	system_clock::time_point start = system_clock::now();
	system("pause");

	// print how long time has passed since the timer was set (or since the program started)
	duration<double> diff = system_clock::now() - start;
	cout << "Time passed since the program first started: ";
	cout << diff.count() << "s" << endl;

	// returns
	system("pause");
	return 0;
}
