#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Observer (Subscriber - Publisher)
// look ActiveMQ as a example

// Observer -> Subscriber
//Subject -> Publisher


struct Publisher;

struct ISubscriber {

	virtual void update_subscribtion(Publisher* p) = 0;

};


struct Subscriber : ISubscriber { 

public:
	Subscriber(int s) : subs_state(s) {}
	int getState() { return subs_state; }

	void update_subscribtion(Publisher* p);

private:
	int subs_state;

};



struct Publisher {
public:

	void addSubscriber(ISubscriber* s)
	{
	   subscribers.push_back(s);
	}

	void removeSubscriber(int i) {
	   subscribers.erase(subscribers.begin() + i);
	}

	void notify() {
		for (ISubscriber* s : subscribers) s->update_subscribtion(this);

	}

	virtual int getState() = 0;
	virtual void setState(int s) = 0;

private:
	vector<ISubscriber*> subscribers;

};

struct BestPublisher : Publisher
{

public:

	int getState() { return state; }
	void setState(int s) { state = s; }

private:
	int state;

};


void Subscriber::update_subscribtion(Publisher* p) {
	subs_state = p->getState();
	cout << "Update subscriber state to: " << p->getState() << endl;
}


int main() {

	Subscriber s1(1);
	Subscriber s2(2);
	Subscriber s3(3);


	Publisher* publisher = new BestPublisher();

	publisher->addSubscriber(&s1);
	publisher->addSubscriber(&s2);
	publisher->addSubscriber(&s3);

	for (int i = 1000; i < 1501; i += 500) {
		publisher->setState(i);
		publisher->notify();

		///

		cout << s1.getState() << " --- " << s2.getState() << " --- " << s3.getState() << endl;
	}



	delete publisher;


}