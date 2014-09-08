#include<iostream>
using namespace std ;

class Base
{
 int id ;

public :
    Base()
    {
        id = 0 ;
        cout<<"Base class Constructor is called id = "<<id<<std::endl ;
    }

    ~Base()
    {
        cout<<"Base Class Destructor is called "<<std::endl ;

    }

};


class Drived : public Base
{
    int  id ;
public :
     Drived(){
         id = 1 ;
         cout<<"Drived Class Constructor is called id = "<< id <<std::endl  ;
     }

    ~Drived(){
        cout<<"Drived Class Destructor is called"<<std::endl ;
    }
};


int main()
{
    Drived drived ;

    return 0 ;
}
