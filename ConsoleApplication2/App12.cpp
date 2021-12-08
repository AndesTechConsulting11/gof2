#include<iostream>

using namespace std;


struct IState {
	virtual void doSmth() = 0;
	virtual ~IState() {}
};

struct State1 : IState {

	void doSmth() { cout << "State1 do smth.." << endl; }
};

struct State2 : IState {

	void doSmth() { cout << "State2 do smth.." << endl; }
};

struct Ctx
{
public:
   
	virtual  ~Ctx() {
	//	delete state;
	}

	void setState(IState* s)
	{   state = s;
	if (s == nullptr) { cout << "state reset to NULL.." << endl; }
	}

	void method()
	{
		if (state != nullptr) state-> doSmth();
	}


private:
	IState* state = NULL;

};


int main() { 
	Ctx* ctx = new Ctx;
	IState* s1 = new State1; // s1 to do ...
	IState* s2 = new State2; // s2 to do ...

	ctx->setState(s1);
	ctx->method();

	cout << "-----------------------------" << endl;

	ctx->setState(s2);
	ctx->method();

	delete s2;
	delete s1;
	delete ctx;
	
	return 0; }

