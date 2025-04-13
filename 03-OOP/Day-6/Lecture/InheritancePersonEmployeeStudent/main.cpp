#include <iostream>

using namespace std;
#include <string.h>

class Person
{
protected:
    int ID;
    int Age ;
    char name[30];

public:
    Person()
    {
        strcpy(name , "no name") ;
        Age = 30 ;
        ID = 0;
    }

    Person(int _ID)
    {
        strcpy(name , "no name") ;
        Age = 30 ;
        ID = _ID;
    }

    Person(int _ID , char *_name ,int _Age )
    {
        strcpy(name , _name) ;
        Age = _Age ;
        ID = _ID;
    }

    void setID(int _ID){ ID = _ID; }
    void setAge(int _Age) { Age = _Age ;}
    void setName(char *_name) { strcpy(name , _name ) ; }
    int getID() { return ID ;}
    int getAge() { return Age;}
    char *getName() {return name ;}

    void print()
    {
        cout << "person data ID : " << ID << " , Age  :" << Age << " , name : " << name << endl;
    }
};

class emp : public Person
{
    int salary ;

public:

/*
// the problem here is that the parent should be created before the child so when I call this constructor
// it calls the parent constructor(parameterless at first then call this constructor)
// so it is reassigning the values for the same object twice
//  and if the parent do not have a parameterless constructor it will give compilation error
    emp(int _ID , int _Age , char *_name ) // this will call the default parameterless constructor of not found -> compilation error
    {
        setID( _ID ) ;
        setAge( _Age ) ;
        setName( _name ) ;
        salary = 3000;
    }

*/
    //parent will be called and created first before child
    //emp(int _ID , int _Age , char *_name , int _salary) : Person(_ID )
    //{} // will add name as no name and the age as 0

    emp(int _ID , int _Age , char *_name , int _salary) : Person(_ID , _name , _Age) // chaining calling parent ctor
    {
        salary = _salary ;
    }



    void setSalary (int _salary) { salary = _salary ;}
    int getSalary(){return salary ;}
    void print(){
        /*
        cout << getID() << endl; // since it is public
        cout << ID << endl; // if ID is protected
        cout << this->ID << endl;
        */
        Person::print();
        cout << "emp salary is " << salary << endl;
        }
};


int main()
{
    //emp e1 (2, 3, "israa");
    emp e1 (2, 3, "israa" , 342);

    //e1.setSalary(200);
    //e1.setID(324);
    //e1.setName("fwrg");

    /*

    e1.ID = 30 ; //compilation error

    */

    //e1.Person::print();
    e1.print(); // now containing full data of person and employee
    //e1.Person::print(); // will call print of the parent class (Person)

    return 0;
}
