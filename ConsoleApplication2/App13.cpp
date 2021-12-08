#include<iostream>

using namespace std;
//strategy pattern

struct IStrategy {
	
	virtual void call() = 0;

};


struct Strategy1 : IStrategy
{
	void call() {
		cout << "++ Strategy 1 algorithms call init!!!" << endl;
	}
};

struct Strategy2 : IStrategy
{
	// настройка...
	// констр
	// доп поля и т.д....
	void call() {
		cout << "++ Strategy 2 algorithms call init!!!" << endl;
	}
};

struct Ctx {
public:
	Ctx() = delete;
	Ctx(IStrategy* s) : strategy(s) {}

	void ctxCall() { strategy->call(); }

private:
	IStrategy* strategy = NULL;
};



int main() {
	IStrategy* s1 = new Strategy1();
	IStrategy* s2 = new Strategy2();

	Ctx ctx(s1);
	ctx.ctxCall();

	Ctx ctx2(s2);
	ctx2.ctxCall();


	delete s1; delete s2;

	return 0;
}