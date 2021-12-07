
#include<iostream>
using namespace std;


struct Component {};

struct Engine: Component {	int val;};

struct Module: Component {	int val;};

//struct Capsule { int val; };

//.....


struct SoyuzRocket {

	int N;
	Engine* engs[4];
	Module* module;
//  Capsule* capsule;

};

struct Builder {
	virtual Engine* buildEngine() = 0;
	virtual Module* buildModule() = 0;
	//virtual Capsule* buildCapsule() = 0;

};

struct RocketBuilder : public Builder
{
	Engine* buildEngine() {
		Engine* eng = new Engine;
		eng->val = rand() * 100;
		return eng;
	}

	Module* buildModule() {
		Module* m = new Module;
		m->val = rand() * 100000;
		return m;
	}

	//.....
};

struct SuperRocketBuilder : public Builder
{
	Engine* buildEngine() {
		Engine* eng = new Engine;
		eng->val = 100000;
		return eng;
	}

	Module* buildModule() {
		Module* m = new Module;
		m->val = rand() * 100000;
		return m;
	}

	//.....
};



struct Director {
public:
	Director() = delete;
	Director(Builder* b)
	{
		builder = b;
	}

	SoyuzRocket* buildRocket() {

		SoyuzRocket* rock1 = new SoyuzRocket();
		rock1->module = builder->buildModule();
		for (int i = 0; i < 4; i++) rock1->engs[i] = builder->buildEngine();
		//....
		return rock1;
	}
private:
	Builder* builder;
};


struct Director2 {
	public:
		//Director() = delete;
		void createBuilder(Builder* b)
		{
			builder = b;
		}

		SoyuzRocket* buildRocket() {

			SoyuzRocket* rock1 = new SoyuzRocket();
			rock1->module = builder->buildModule();
			for (int i = 0; i < 4; i++) rock1->engs[i] = builder->buildEngine();
			//....
			return rock1;

		}


	
private:
	Builder* builder;
	
};


int main() {

	SoyuzRocket* rocket = NULL;
	RocketBuilder rocketBuilder;
	Director2 director;

	director.createBuilder(&rocketBuilder);
	rocket = director.buildRocket();

	SoyuzRocket* rocket2 = NULL;
	SuperRocketBuilder srocketBuilder;

	director.createBuilder(&srocketBuilder);
	rocket2 = director.buildRocket();


	delete rocket;
	delete rocket2;
	return 0;
}
