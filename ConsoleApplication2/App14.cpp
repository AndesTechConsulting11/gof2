#include<iostream>
#include<vector>

using namespace std;

struct Memento {

public:

	Memento() = delete;
	Memento(int s) :state(s) {}
	int getState() { return state; }
	void setState(int s) { state = s; }

private:
	int state;
};


struct Originator {
public:
	void setMemento(Memento* m){
		state = m->getState();
	}

	Memento* newMemento() {
		return new Memento(state);
	}

	int getState() { return state; }
	void setState(int s) { state = s; }

// q: how to remove double state??
private:
	int state;
};


struct CareTaker {

public:
	CareTaker(Originator* ori) :originator(ori) {}
	~CareTaker() {}

	void backup() {
		hist.push_back(originator->newMemento());
		cout << "++ backup created." << endl;
	}

	void restore() // with delete prev state!!! attention!!
	{
		if (!hist.empty())
		{
			Memento* mem = hist.back();
			originator->setMemento(mem);

			hist.pop_back(); // carefull!!
			delete mem;      //// carefull!!
			cout << "-- restore finished." << endl;

		}
		else { cout << "Nothing to recover, you are the single object.." << endl; }
	
	
	}

private:
	Originator* originator = NULL;
	vector<Memento*> hist;

};




int main() {
	Originator* o1 = new Originator();
	CareTaker* ct = new CareTaker(o1);

	o1->setState(10);
	ct->backup();

	o1->setState(20);
	ct->backup();

	o1->setState(30);
	cout << "state: " << o1->getState() << endl;

	ct->restore();
	cout << "1. state: " << o1->getState() << endl;

	ct->restore();
	cout << "2. state: " << o1->getState() << endl;

	ct->restore();
	cout << "3. state: " << o1->getState() << endl;




	return 0;
}
