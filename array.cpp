#include "iostream"
using namespace std;

int main() {
	char* array[10] = {"sausage", "eggs", "ice cream"};
	for (int i = 0; i < 10; i++) {
		std::cout << array[i] << "\n";
	}
	return 0;
}
