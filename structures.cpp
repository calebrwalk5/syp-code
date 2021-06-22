#include "iostream"
using namespace std;

int main() {
	struct Foo {
		string var;
		int i;
	};
	struct Foo f1;
	f1.var = "lorem ipsum";
	f1.i = 10;
	cout << f1.var << "\n" << f1.i << "\n";
	f1.var = f1.var + " dolor sit amet";
	cout << f1.var << "\n";
	return 0;
}
