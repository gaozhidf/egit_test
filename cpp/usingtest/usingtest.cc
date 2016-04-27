//#include "StdAfx.h"
#include <iostream>
using namespace std;

class Base
{
public:    
   void menfcn()
  {
     cout<<"Base function"<<endl; 
  }

    void menfcn(int n)
    {
     cout<< cout<<"Base function with int"<<endl; 
    }

public:
	void printnihao()
	{
		cout << "nihao" << endl;
	}
};

class Derived : public Base
{
public:    
using Base::menfcn;//using声明只能指定一个名字，不能带形参表    
int menfcn(int)
{ cout<<"Derived function with int"<<endl; }
};
int main()
{    Base b; 
     Derived d;
	 d.printnihao();
  b.menfcn();   
  d.menfcn();//如果去掉Derived类中的using声明，会出现错误：error C2660: 'Derived::menfcn' : function does not take 0 arguments    std::cin.ignore(std::cin.gcount()+1);//清空缓冲区    std::cin.get();//暂停程序执行  
}
