#include "iostream"
#include "stdlib.h"
#include "cmath" 
using namespace std;

void fizzbuzz() {
  for (int i = 1; i < 100; i++) {
    if((i % 15) == 0) {
      cout << "fizzbuzz\n";
    } else if ((i % 3) == 0) {
      cout << "buzz\n";
    } else if ((i % 5) == 0) {
      cout << "fizz\n";
    } else {
      cout << i << "\n";
    }
  }
}

int main () {
	int coolness = sqrt(93);
	bool student = true;
	bool epic = true;

	struct Student {
		string name;
		int age;
	};

	struct Student s1;

	cout << "this is coding for the Internet of Things\n";
	cout << "what is your name? ";
	cin >> s1.name;
	system("clear");
	cout << "hello, " << s1.name << "\n";
	cout << "what is your age?\n";
	cin >> s1.age;
	system("clear");
	cout << s1.name << " is " << s1.age << "\n";
	fizzbuzz();

	if (student == true) {
		coolness++;
	}
	if (epic == true) {
		for (int i = 0; i < 50; i++) {
			coolness++;
			cout << "coolness: " << coolness << " ";
		}
	}
        return 0;
}



