#include<iostream>
#include<string>
using namespace std;

/*
Virtual Function: Can be overridden, allows instantiation of the class, provides default behavior.
Pure Virtual Function: Must be overridden, makes the class abstract, no default implementation.
*/

class Base {
    //Pure virtual function, when initialised with value 0 (also known as abstract method)
    //If there is a pure virtual method in the class, then the class is abstract class
    //Derived class should implement the method, otherwise it would also be a abstract class
    //Pure functions are by default private, unless specified otherwise.
    virtual void check() = 0;
    string b;
public:
    Base(){
        //cout<<"Base default class constructor \n";
    }
    Base(string x){
        //cout<<"Base class constructor \n";
        b = x;
    }
    virtual void show() {
        cout << "Base class show function." <<endl;
    }

    void sample(){
        cout << "Base class sample function." <<endl;
    }
};

class Derived : public Base {
public:
    string d;
    Derived():Base(){
        //cout<<"Derived default class constructor \n";
    }

    Derived(string x, string y) : Base(x){
        //cout<<"Derived class constructor \n";
        d = y;
    }
    //If we create a new class inheriting Derived class, it can't override show method
    //as we are writing final below, so it won't let us overwrite its implementation
    void show() final{
        cout << "Derived class show function." <<endl;
    }

    void check(){
        cout << "Derived class pure virtual 'check' function." <<endl;
    }

    void sample(){
        cout << "Derived class sample function." <<endl;
    }
};


int main(){
    /*
    //Derived d1;  //Default constructor calling
    Derived d("bbb","ddd"); //Parameterized constructor calling
    d.show();
    d.sample();
    //You can't call a pure virtual function, and it will give compilation error
    // d.Base::check();
    d.check();
    d.sample();

    Base* bb = &d;
    bb->sample();
    */
    int a = 10, b = 20;
    int c;
    c = (a,b);  //20   : left to right
    cout<<"Before: "<<c<<endl;
    c = a,b;  //10, based on higher precedence of '='
    cout<<"After: "<<c<<endl;
    return 0;
}