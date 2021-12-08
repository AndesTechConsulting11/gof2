#include<iostream>
#include<vector>
#include<string>

using namespace std;

// Observer (Subscriber - Publisher)
// look ActiveMQ as a example

// Observer -> Subscriber
//Subject -> Publisher


struct Publisher;

struct IMessage {
	
	virtual string getMessageText() = 0; 

};

struct Message : IMessage
{  
 public:

 Message(string h, string b, int p) : header(h), body(b), priority(p) {}

 virtual string getMessageText()  { return body; }

private:
	string header;
	string body;
	int priority;
};



struct ISubscriber {

	virtual void update_subscribtion(Publisher* p) = 0;
	virtual void update_subscribtion(IMessage* m) = 0;

};


struct Subscriber : ISubscriber { 

public:
	Subscriber(int s) : subs_state(s) {}
	int getState() { return subs_state; }

	Subscriber(IMessage* m) : message(m) {}
	IMessage* getMState() { return message; }

	void update_subscribtion(Publisher* p);
	void update_subscribtion(IMessage* m);

private:
	int subs_state;
	IMessage* message = NULL;

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
		for (ISubscriber* s : subscribers)
		{
			s->update_subscribtion(this);
			s->update_subscribtion(message);
		}

	}

	virtual int getState() = 0;
	virtual void setState(int s) = 0;

	virtual IMessage* getMessage() = 0;
	virtual void setMessage(IMessage* m) = 0;

protected:
	IMessage* message = NULL;

private:
	vector<ISubscriber*> subscribers;
	

};

struct BestPublisher : Publisher
{

public:

	int getState() { return state; }
	void setState(int s) { state = s; }

	IMessage* getMessage() { return message; }
	void setMessage(IMessage* s) { message = s; }


private:
	int state;

};


void Subscriber::update_subscribtion(Publisher* p) {
	subs_state = p->getState();
	cout << "Update subscriber state to: " << p->getState() << endl;
}

void Subscriber::update_subscribtion(IMessage* m) {
	if (m != nullptr) {
		message = m;
		cout << "Update subscriber state to: " << message->getMessageText() << endl;
	}
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

	cout << "-------------------------------------------" << endl;
	IMessage* message = new Message("header", "New journals arrived!! Hurry up!", 0);
	publisher->setMessage(message);
	publisher->notify();



	delete publisher;


}