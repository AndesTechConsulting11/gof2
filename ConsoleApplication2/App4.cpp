#include<iostream>

using namespace std;

// Prototype!

struct A { int val; int data; };
struct B { int val; };

int main() {

	A a1{ 2, 128 };
	A a2 = a1;

	a1.data = -22;

	cout << a2.val << " -- "<< a2.data << endl;
	cout << a1.val << " -- " << a1.data << endl;

}