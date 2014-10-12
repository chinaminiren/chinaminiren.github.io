#pragma once
#include <iostream>
using namespace std;

//��֤һ�������һ��ʵ�������ṩһ����������ȫ�ַ��ʵ�
class Single
{
public:
	static Single* GetInstance();
	//�������ҵ��ӿ�
private:
	static Single* obj;
	~Single()
	{
		std::cout<<"Release Single"<<std::endl;
	}
	 Single(const Single&);
	 Single(){}
	 Single& operator=(const Single&);
	 class internalSingle
	 {	
	 public:
		 internalSingle()
		 {
			 std::cout<<"Create Single"<<std::endl;
		 }
		~internalSingle()
		{			
			delete obj;
		}
	 };
	 static internalSingle deleteobj;
};
Single::internalSingle Single::deleteobj;
Single* Single::obj=new Single();
Single* Single::GetInstance()
{
	return obj;
}
void TestSingle()
{
	//
}