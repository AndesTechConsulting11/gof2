#include<iostream>
#include<string>

using namespace std;

//

struct INewInterface {

	virtual int processRequest(int p) = 0;
	//....

};

//Legacy class

struct IAdaptee {
	virtual	string processRequest(int p) = 0;

};

struct Adaptee : IAdaptee {

	string processRequest(int p)
	{
		return "data old format: " + to_string(p * 10);
	}

};

struct Adaptee2 : IAdaptee {

	string processRequest(int p)
	{
		return "My data old format: " + to_string(p * 10);
	}

};


struct Adapter : INewInterface {
public:
	Adapter(IAdaptee* adap) : ad(adap) {}
	int processRequest(int p) {
		string res = ad->processRequest(p);
		string res2 = res.substr(res.find_last_of(" "));
		return stoi(res2);
	}


private:
	IAdaptee* ad;

};


void clientAccess(INewInterface* o)
{
	cout << o->processRequest(100) << endl;

}


int main()
{

	//cout << (new Adapter(new Adaptee())) -> processRequest(10);
	Adaptee* old = new Adaptee();
	Adapter* adapter = new Adapter(old);
     
	clientAccess(adapter);


	delete old;
	delete adapter;
	return 0;
}

