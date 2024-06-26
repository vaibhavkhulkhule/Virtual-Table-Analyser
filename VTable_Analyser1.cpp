////////////////////////////////////////////////////////////////////////////
//
// Class Name    :  Base, Derived
// Description   :  Demonstration Of VPTR And VTABLE
// Input         :  None
// Output        :  None
// Author        :  Vaibhav khulkhule
// Date          :  23 July 2021
//
////////////////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

#include<stdio.h>

class Base
{
    public :
	
    int x, y;

	virtual void fun() //1000
	{
		cout << "\nCall to fun() of Base class";
	}

	virtual void gun() //2000
	{
		cout << "\nCall to gun() of Base class";
	}

	virtual void sun() //3000
	{
		cout << "\nCall to sun() of Base class";
	}
};

class Derived : public Base
{
    public:
	
    int a, b;
	
	void fun() //4000
	{
		cout << "\nCall to fun() of Derived class";
	}

	void gun() //5000
	{
		cout << "\nCall to gun() of Derived class";
	}
};

int main()
{
	Base bobj;
	Derived dobj;

	//Store the starting adderss of object in pobj of type int*
	int *pobj = (int *)(&bobj);

	//*pobj gives the address of VTable which is store in first 4 bytes of object
	int *vp = (int *)(*pobj);

	//fp1 is a pointer to function which returns nothing and accept nothing
	void (*fp1)();

	//Address of first function type casted in appropriate function pointer
	fp1 = (void (*)())(*vp);

	fp1();

	//vp+1 gives the address of second virtual function
	fp1 = (void (*)())(*(vp+1));
	fp1();

	//vp+2 gives the address of third virtual function
	fp1 = (void (*)())(*(vp+2));
	fp1();

	//Store the starting adderss of object in pobj of type int*
	pobj = (int *)(&dobj);

	//*pobj gives the address of VTable which is store in first 4 bytes of object
	vp = (int *)(*pobj);

	//Address of first function type casted in appropriate function pointer
	fp1 = (void (*)())(*vp);
	fp1();
	
	//vp+1 gives the address of second virtual function
	fp1 = (void (*)())(*(vp+1));
	fp1();

	//vp+2 gives the address of third virtual function
	fp1 = (void (*)())(*(vp+2));
	fp1();

	return 0;
}
