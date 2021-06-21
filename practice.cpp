#include "iostream"
#include "cmath" 
using namespace std;

void fizzbuzz() {
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
	int coolness = sqrt(93);
	bool student = true;
	bool epic = true;
	string name = "";

	std::cout << "this is coding for the Internet of Things\n";
	std::cout << "what is your name? ";
	std::cin >> name;
	std::cout << "hello, " << name << "\n";
	fizzbuzz();

	if (student == true) {
		coolness++;
	}
	if (epic == true) {
		for (int i = 0; i < 50; i++) {
			coolness++;
			std::cout << "coolness: " << coolness << " ";
		}
	}
        return 0;
}



