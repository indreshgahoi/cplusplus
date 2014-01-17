/*
 * ConstuctotCallingOrder.cpp
 * run command
 * g++ /media/program/cprogram/git_repo/Algorithm/src/c++Excersize/ConstuctotCallingOrder.cpp -o /usr/build/Main.o
 *
 *  Created on: Jan 11, 2014
 *      Author: Indresh Gahoi
 */

#include<iostream>
#include<sstream>
#include<fstream>
#include<cstdio>
#include<climits>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<set>
#include<vector>
#include<map>
#include<stack>
#include<queue>

using namespace std;


class NonCopyable
  {
    private:
      NonCopyable(const NonCopyable&);  // no implementation
      NonCopyable& operator=(const NonCopyable&);  // no implementation
    public:
      NonCopyable() { }
  };


class Base
{

public :
	int m ;

	explicit Base(int m_)
	{
		m = m_ ;
		cout <<" Hi am Base ="<<m<<"\n" ;
	}

	Base(const Base &bas1)
	{
		cout<<"----------------Start Base Copy-----------------\n" ;
		cout<<" Iput Base is Called m = "<<bas1.m<<" \n" ;
		cout<<"for current obj m= "<<m <<"\n" ;
		cout<<">>>>>>>>>>>>>>>>Base Copy End>>>>>>>>>>>>>>>>>>>>>" ;
	}

};

class Children :public Base
{
public :
	int childNo ;
	Children()
	{
		childNo = 2 ;
		cout <<" Hi I am child childNo = "<<childNo<<"\n" ;
	}
	 Children(Children &child)
	{
		 cout<<"-----start copy---------------------------\n" ;
		 cout<<"Input child childNo="<<child.childNo<<"\n" ;
		 childNo = 3 ;
		 cout<<"Children Copy is is Called childNo = "<<childNo<<" \n"  ;
         cout<<">>>>>>>>>>>>>>>>>>>>End Copy>>>>>>>>>>>>>>>>>>>>>\n";
	}

};


class A : public NonCopyable
{

public:
	A()
	{
		cout<<"hi I am Indresh \n" <<;
	}

};


class Main
{

public :
        void solve(istream &fin ,ostream &out)
        {
        	//Base base1 = 5 ;
        	Base base(5) ;
        	//base = 6 ;
        	//Children child ;
        	//Base child1 = child ;

        	//cout <<"From child "<<child.childNo<<"\n" ;
        	//cout <<"From child1 "<<child1.childNo<<"\n" ;

        }
};


int main()
{

	(new Main())->solve(cin,cout) ;

	return 0 ;
}


