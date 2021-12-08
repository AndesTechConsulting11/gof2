#include<iostream>

using namespace std;
//bridge

struct Implementor
{
	virtual void act() = 0;
	//...
};

struct R1Implementor : Implementor
{
	void act() { cout << "R1 implementor: " << this << endl; }

};

struct Abstraction {

	virtual void op() = 0;
};


struct RefinedAbstraction : Abstraction
{
public:
	RefinedAbstraction(Implementor* impl) :implementor(impl) {}
	void op() { implementor->act(); }
	
private:
	Implementor* implementor;

};



int main() {

	Implementor* i1 = new R1Implementor;
	Abstraction* a1 = new RefinedAbstraction(i1);
	a1->op();

	delete i1;
	delete a1;
}