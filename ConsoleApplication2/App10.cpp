#include<iostream>
using namespace std;

struct Handler
{

public:

	virtual void setNextHandler(Handler* h)
	{
		next = h;
	}

	virtual void handleRequest(int data) {
	
		if (next != nullptr)	next->handleRequest(data);
		else cout << "No any handlers.. sorry. Request rejected." << endl;

	}

	//virtual void handleRequest(int data) = 0;
	virtual bool checkRequest(int p) = 0;
	virtual bool checkHealth() = 0;

private:
	Handler* next = NULL;
};


struct H1 : Handler
{

	bool checkRequest(int p) { return p < 0; }
	bool checkHealth() { return true; }

	void handleRequest(int data) {
		if (checkHealth() && checkRequest(data))
		{
			cout << "++ H1 process request, data:" << data << endl;
		}
		else {
			cout << "-- H1 failed process request. Forwarding..." << data << endl;
			Handler::handleRequest(data);
		}
	}
};




struct H2 : Handler
{

	bool checkRequest(int p) { return p < -10 ; }
	bool checkHealth() { return true; }

	void handleRequest(int data) {
		if (checkHealth() && checkRequest(data))
		{
			cout << "++ H2 process request, data:" << data << endl;
		}
		else {
			cout << "-- H2 failed process request. Forwarding..." << data << endl;
			Handler::handleRequest(data);
		}
	}
};



struct H3 : Handler
{

	bool checkRequest(int p) { return p < 10; }
	bool checkHealth() { return true; }

	void handleRequest(int data) {
		if (checkHealth() && checkRequest(data))
		{
			cout << "++ H3 process request, data:" << data << endl;
		}
		else {
			cout << "-- H3 failed process request. Forwarding..." << data << endl;
			Handler::handleRequest(data);
		}
	}
};


void check_ptr() {
	unique_ptr<H3> h3(move(new H3));
	unique_ptr<H2> h2(move(new H2));
	unique_ptr<H1> h1(move(new H1));


	h1->setNextHandler(h2.get());
	h2->setNextHandler(h2.get());
	h3->setNextHandler(h3.get());
	
	h1->handleRequest(-2);


}

int main()
{

	H1 h1; H2 h2; H3 h3;

	h1.setNextHandler(&h2);
	h2.setNextHandler(&h3);
	h1.handleRequest(1);

	cout << "----------------------------------------------------\n";

	check_ptr();

	return 0;
}