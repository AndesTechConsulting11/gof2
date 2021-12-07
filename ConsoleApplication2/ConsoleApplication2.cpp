// ConsoleApplication2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>

class IFigure {
public:
    IFigure() {
        std::cout << "+++ IFigure ctor " << this << std::endl;
        id = 1 + rand() * 100000;
    }
    //virtual void move() = 0;
    virtual void init() = 0;
    //.....

protected:
    static int counter;
    int id;

};

int IFigure::counter = 0;

using namespace std;

class Circle : public IFigure
{
public:
    Circle() { std::cout << "+++ Circle ctor " << this << std::endl; }
    void init() { cout << "Circle " << this << " init flushed!!!"; }

};

class Square : public IFigure
{
public:
    Square() { std::cout << "+++ Square ctor " << this << std::endl; }
    void init() { cout << "Square " << this << " init flushed!!!" << std::endl; }

};

class Line : public IFigure
{
public:
    Line() { std::cout << "+++ Line ctor " << this << std::endl; }
    void init() { cout << "Line " << this << " init flushed!!!" << std::endl; }

};


//// и много других типов

class IFabric {
public:
    virtual IFigure* smartInit() = 0;
    virtual IFigure* simpleInit() = 0;
   //...
};


class Fabric1 : public IFabric
{
public:
    IFigure* smartInit() { f1 = new Circle; return f1; }
    IFigure* simpleInit() { return new Line; }

private:
    IFigure* f1;
};

class Fabric2 : public IFabric
{
public:
    IFigure* smartInit() { return new Square; }
    IFigure* simpleInit() { return new Line; }
};




int main()
{
    cout << "Abstract Fabric test\n";
    IFabric* fab1 = new Fabric1;

    IFigure* figures[2];

    figures[0] = fab1->simpleInit();
    figures[1] = fab1->smartInit();

    for (IFigure* f : figures) f->init();

    delete fab1;
    delete[] figures;
}

