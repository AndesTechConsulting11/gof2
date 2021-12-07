
#include<iostream>
#include<string>
#include<sstream>
using namespace std;


struct IComponent {	virtual string getData() = 0; };

struct Component : IComponent
{
	//...
	void init() { cout << "init method fired..."; };
	string getData() { return "<p> Start paragraph data....</p>"; }
};

struct Decorator : IComponent
{
public:
	Decorator(IComponent* c) : comp(c){}
	string getData() { return comp->getData(); }

private:
	IComponent* comp;
};

struct DivDecorator : Decorator
{
	DivDecorator(IComponent* c) :Decorator(c) {}
	string getData() {
		return "<div>" + Decorator::getData() + "</div>";
	}
};

struct FilterDecorator : Decorator
{
	

	FilterDecorator(IComponent* c, int param) :Decorator(c),p(param) {}
	string getData() {
		stringstream st;
		st << "<filter level=\"" << p << "\">" << Decorator::getData() << "</filter>";
		return st.str();
	}

protected:
	int p;
};


void testDecorator(IComponent* component)
{
	cout << "TestDecor--> " << component->getData() << endl;
}


int main() {

	Component* component = new Component();
	cout << component->getData() << endl;

	DivDecorator* divdec = new DivDecorator(component);
	//DivDecorator* divdec2 = new DivDecorator(divdec);
	FilterDecorator* fdec = new FilterDecorator(divdec, 7);

	testDecorator(divdec);
	testDecorator(fdec);




}


