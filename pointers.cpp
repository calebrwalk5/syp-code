#include "iostream"
#include "cmath"

using namespace std;

int main() {
	int x = sqrt(93);
	int *ptr = &x;
	int **ptr2 = &ptr;
	cout << *ptr2 << "\n";
	cout << x << "\n";
	return 0;
}
