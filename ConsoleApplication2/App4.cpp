
#include<iostream>

using namespace std;

// Prototype!

struct A { int val; int data; };
struct B { int val; };

struct Proto
{
	virtual Proto* clone() = 0;
    //....
};

struct Object1 : Proto
{
	int data;
	Object1();
	Object1(int d) { data = d; }
	//Object1(const Object1& o1);

	Object1* clone() { return  new Object1(*this); }

};

Object1::Object1() { cout << "+++ ctor" << this; }


void ProtoClone(Proto* proto)
{
	Proto* o2 = proto->clone();
	unique_ptr<Proto> o3(proto->clone());
	Proto& o4 = *proto->clone();

	delete o2;

}

int main() {

	A a1{ 2, 128 };
	A a2 = a1;

	a1.data = -22;

	cout << a2.val << " -- "<< a2.data << endl;
	cout << a1.val << " -- " << a1.data << endl;

	//--------------------------

	ProtoClone(new Object1(1));


	//Object1 o1; o1.data = 1;

	//Object1* o2 = o1.clone();




}