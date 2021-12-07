
#include <iostream>
using namespace std;

class SingletonV1 {

public:
	static SingletonV1* genObject()
	{
		static SingletonV1 s;
		return &s;
	}
	int getData() { return _data; }

private:
	int _data;
	SingletonV1() {
		cout << "+++ ctor: " << this << endl;
		_data = rand() * 10000;
	}

};



int main() {

	SingletonV1* s = SingletonV1::genObject();
	cout << s->getData() << endl;
	SingletonV1* s2 = SingletonV1::genObject();
	cout << s2->getData() << endl;

	delete s; delete s2;
	return 0;

}