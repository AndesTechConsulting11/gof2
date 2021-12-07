#include<iostream>

using namespace std;

struct System1
{
	void meth1() { cout << "sys1 meth1 calls..." << endl; }
	void meth2() { cout << "sys1 meth2 calls..." << endl; }
	void meth3() { cout << "sys1 meth3 calls..." << endl; }
};


struct System2
{
	void meth1() { cout << "sys2 meth1 calls..." << endl; }
	void meth2() { cout << "sys2 meth2 calls..." << endl; }
	void meth6() { cout << "sys2 meth6 calls..." << endl; }
};

//
//

struct Facade
{
public:
	Facade(System1* sys1, System2* sys2) :s1(sys1), s2(sys2) {}
	// routing for calls

	void run1() {s1->meth1(); s2->meth6(); s1->meth3();	}
	void run2() {s2->meth1(); s2->meth2(); s1->meth2(); }

private:
	System1* s1;
	System2* s2;
	//...

};


int main(){

	Facade* f1 = new Facade(new System1(), new System2());

	f1->run1();
	cout << "--------------------------------" << endl;
	f1->run2();

		return 0;
}