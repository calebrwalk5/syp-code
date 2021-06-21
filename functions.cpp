#include "iostream"
using namespace std;

void function1(int five) {
	std::cout << "function 1\n";
	std::cout << five;
	cout << "\n";
}

int main() {
	int five = 4;
	function1(five);
	return 0;
}
