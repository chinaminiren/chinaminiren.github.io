#pragma once
//���󹤳� ���󹤳����ṩһ������һϵ����ػ��໥��������Ľӿڣ�������ָ�����Ǿ�����ࡣ
//���㷢�֣���һ���ӿڿ����ж���ʵ�ֵ�ʱ�򣬿��Կ���ʹ�ù�������������ʵ����
//���㷵�֣���һ��ӿڿ����ж���ʵ�ַ�����ʱ�򣬿��Կ���ʹ�ó��󹤳�����ʵ���顣
#pragma once
#include <memory>
#include <iostream>

using namespace std;

class  Food
{
public:
	virtual void DoWork()=0;
};
class FuitFood:public Food
{
public:
	virtual void DoWork()
	{

	}
};
class GreensFood:public Food
{
public:
	virtual void DoWork()
	{

	}
};

class Car
{
public:
	virtual void Run()=0;
};
class Ford:public Car
{
public:
	virtual void Run()
	{
		
	}

};
class GMC:public Car
{
public:
	virtual void Run()
	{

	}
};

class IFactory
{
public:
	virtual Food* CreateFood()=0; 
	virtual Car* CreateCar()=0;
};
class FactoryA:public IFactory
{
public:
	virtual Food* CreateFood()
	{
	  Food* ptr=new FuitFood();
	  return ptr;
    }
	virtual Car* CreateCar()
	{
		return new Ford();
	}
};
class  FactoryB:public IFactory
{
public:
	virtual Food* CreateFood()
	{
	  Food* ptr=new FuitFood();
	  return ptr;
    }
		virtual Car* CreateCar()
	{
		return new Ford();
	}
};

void TestAbstactFactory()
{
	//���󹤳���
	//
}