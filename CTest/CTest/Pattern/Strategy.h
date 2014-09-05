//���һ���㷨����ÿһ���㷨��װ�����й�ͬ�ӿڵĶ��������У��Ӷ�ʹ�����ǿ����໥�滻��
#include "stddef.h"
#include <iostream>
#include <memory>

using namespace std;

class  Strategy
{
public:
	virtual void Work()=0;
	virtual ~Strategy(){}
};
class SkyStategy:public Strategy
{
public:
	virtual void Work()
	{
		std::cout<<"Strategy Sky"<<endl;
	}
	virtual ~SkyStategy()
	{
		std::cout<<"realse Strategy Sky"<<endl;
	}
};
class SeaStategy:public Strategy
{
public:
	virtual void Work()
	{
		std::cout<<"Strategy Sea"<<endl;
	}
	virtual ~SeaStategy()
	{
		std::cout<<"realse Strategy Sea"<<endl;
	}
};

class ConcreteStrategy
{
public:
	ConcreteStrategy(Strategy* mptr):stratepy(mptr)
	{

	}
	void Work()
	{
		this->stratepy->Work();
	}   
private:
	tr1::shared_ptr<Strategy> stratepy;
};

void TestStrategy()
{
	ConcreteStrategy strategy(new SeaStategy());
	strategy.Work();
}

