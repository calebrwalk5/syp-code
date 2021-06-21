#include "iostream"
using namespace std;

/*
 *  * MTU Summer Youth Program practice C++ program
 *  */

int fizzbuzz() {
  for (int i = 1; i < 100; i++) {
    if((i % 15) == 0) {
      std::cout << "fizzbuzz\n";
    } else if ((i % 3) == 0) {
      std::cout << "buzz\n";
    } else if ((i % 5) == 0) {
      std::cout << "fizz\n";
    } else {
      std::cout << i << "\n";
    }
  }
}

int main () {
	fizzbuzz;
	int coolness = 1;
	bool student = true;
	bool epic = true;

	if (student == true) {
		coolness++;
	}
	if (epic == true) {
		for (;;) {
			coolness++;
			std::cout << "coolness: " << coolness << "\n";
		}
	}
        return 0;
}



