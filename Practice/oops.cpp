#include<iostream>
#include<vector>

using namespace std;

/*
OOPS concept:
1)Abstration : Hiding the implementation. Only showing what is important to user and hiding unnecessary details from users.
2)Encapsulation : It is a mechanism to hide the data and methods that belong together. Combining variables and methods into one.
3)Inheritance  : Code reusability and class hierarchy. During inheriting a class with variable access modifier.
4)Polymorphism   : Method overriding, method overloading.

Key-points:
-Greedy alignment is a technique used to minimize padding by ordering the data members of a class in decreasing order of size.
-In case of class having no variables, it gets 1 byte of memory allocated.
-If all the variables are private, then the class is called fully  encapsulated.

Access modifiers:
1)Private : by-default
2)Public : Accessible from directly object
3)Protected : Similar to private, but can be accessed in the child class methods as well.

Constructor:
1)Default : constructor created with the same name as of class.
2)Parameterized : we can also create overloaded constructor based on our choice and appropriate variables.
3)Copy : Implicitly created by the compiler (we can overload it if we want).

Desturctor:
To de-allocate memory allocated to the instance of the class
->For static instances, it will be implicitly called at the end of the class.
->For dynamic instances, we need to explicitly call it.

Static field/function:
Accessible at class level, without specifically creating an instance of the class.
Static function can't access class variables or "this" keyword, it can only access static variable.

Inheritance types:
Single-level, Multi-level, Multiple, Hierarchical, Hybrid

Polymorphism :
1)Compile-time polymorphism (static poly)
    ->Function overloading : By changing the parameter list (, type)
    ->Operator overloading : Except these four operators ('.', '::', '.*', '?:'), we can overload any operator based on our choice. 
2)Run-time polymorphism (dynamic poly) 
    ->done through inheritance only, known as function overriding.
    When we just inherit the class A in B, all the functions definition are same. But, if we define a function with same name and parameters in B,
    it gets overriden. It will replace the existing definiton from A.

*/

class Hero{
    
    //private:
    int var1;
    void privatePrint(){
        cout<<"Private method";
    }

    protected:
    int varProtect;
    int getVarProtect(){
        return this->varProtect;
    }
    int setVarProtect(int val){
        this->varProtect = val;
    }

    public:
    int var2;
    static int statVar;

    Hero(){
        //Default
        cout<<"Address of object created:"<<this<<endl;
    }

    //If you are creating a parameterized constructor, then it is mandatory to write default constructor explicitly.
    Hero(int a, int b){
        var1 = a;
        var2 = b;
    }

    //Copy constructor [we need to put & with it, so that both object refers to same variable set], if we remove '&'-> it will give error.
    //Basically it is call by reference, as if we consider call by value, it will get struck in infinite loop.
    //Shallow copy : old and new object will initially have same value, but after upadating any field, 
    //              same value would be present in both objects, referring same memory with two different variable
    //Deep copy : Separate memory, initial same values, but after update, we can see the difference.
    Hero(Hero& old){
        this->var1 = old.getVar1();
        this->var2 = old.var2;
    }

    void setVar1(int var1){
        //this can be used for scoping of the class variable
        this->var1 = var1;
    }
    int getVar1(){
        return var1;
        //return this->var1;
    }

    ~Hero(){
        cout<<"Deconstructor, to delete, is called for:"<<this<<endl;
    }
};

int Hero::statVar = 100;

//Example of child class () 
class SuperHero : public Hero{
    public : 
        int power;

    //As now all the methods and variables are inherited as protected, we need to write below methods
    void setSSVar1(int var1){
        //this can be used for scoping of the class variable
        setVar1(var1);
    }
    int getSSVar1(){
        return getVar1();
    }
};

int main2(){
    
    //Static allocation
    Hero h;
    h.var2=10;
    cout<<"Var2 with static(h):"<<h.var2<<endl;
    h.setVar1(20);
    cout<<"Var1 with static(h):"<<h.getVar1()<<endl;

    //Dynamic allocation
    Hero* h2 = new Hero;
    //Hero* h2 = new Hero();
    (*h2).var2=100;
    cout<<"Var2 with dynamic(h2):"<<(*h2).var2<<endl;
    h2->setVar1(200);
    cout<<"Var1 with dynamic(h2):"<<h2->getVar1()<<endl;

    //Using copy constructor -> this will do shallow copy, so no new instance is being created here
    //Hero h3(*h2);
    //cout<<"Var2 with copy(h3):"<<h3.var2<<endl;
    //h3.setVar1(500);
    //cout<<"Var1 with copy(h3):"<<h3.getVar1()<<endl;

    //Copy assignment
    *h2 = h;
    cout<<"Var2 after copy assignment(h2):"<<(*h2).var2<<endl;
    cout<<"Var1 after copy assignment(h2):"<<h2->getVar1()<<endl;

    // Need to explicitly call for dynamic instance
    delete h2;

    /*cout<<"Before static update:"<<endl;
    cout<<"static variable from class:"<<Hero::statVar<<endl;  //Recommended
    cout<<"static variable from object:"<<h.statVar<<endl; //Not recommended, as static variable is defined at class level
    h.statVar = 1234;
    cout<<"After static update:"<<endl;
    cout<<"static variable from class:"<<Hero::statVar<<endl;  //1234
    cout<<"static variable from object:"<<h.statVar<<endl;  //1234  */

    SuperHero ss;
    ss.setSSVar1(10);
    cout<<"Superhero: "<<ss.getSSVar1()<<endl;

    return 0;
}

//Example of inheritance ambiguity 
class A{
    public:
    void print(){
        cout<<"from A"<<endl;
    }
};

class B{
    public:
    void print(){
        cout<<"from B"<<endl;
    }
};

class C : public A, public B{
    //Here, C contains two definition of 'print' function.
};

int main3(){
    C obj;
    //To resolve ambiguity, using scope resolution('::')
    obj.A::print();
    obj.B::print();
    return 0;
}

//Example of operator overloading
class OP{
    /*Operation : a$b -> this we give us a modulo b.  
    How, it will point : a is our current object, $ is our operator and b is input parameter
    */
    public:
    int a;
    int operator-(int b){
        return this->a % b;
    }
};

int main(){

    OP obj;
    obj.a = 732;
    cout<<"732%27:"<<obj-27;
    return 0;
}