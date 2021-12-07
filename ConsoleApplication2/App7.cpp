#include<iostream>


using namespace std;

struct ISubject {
	virtual void request() = 0;
};

struct Subject : ISubject
{
	void request() {
		cout << "Request called! " << endl;
	}
};

struct Proxy : ISubject
{
public:
             Proxy() { subj = new Subject(); }
  virtual	~Proxy() { delete subj; }

  void request() { subj->request(); }


private:
	ISubject* subj;

};


int main(){

	Proxy* p = new Proxy(); p->request();

	unique_ptr<Proxy> p2(new Proxy());
	p2->request();

	delete p;
return 0;
}