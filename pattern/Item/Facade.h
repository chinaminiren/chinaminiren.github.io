#pragma once
#include <string>
#include <iostream>
#include <memory>

//讲解不错 http://www.blogjava.net/dreamstone/archive/2007/01/08/92482.html
//Facade 设计模式
//是为了一个复杂的系统提供一系列统一简单的接口，目的是简化客户端的操作，但没有改变接口
//Facad 模式出现较多的情况是：一个复杂的系统 对应了各种情况，客户了说功能不错，但是使用太玛法，
//需要提供一个 同一个的门面
//提供一个简明一致的界面 隐藏系统的复杂性 使子系统更加容易使用
//客户也可在 直接 访问原始方法
//Decorator修饰模式 为对象扩展功能
/*
1,Facade很多时候是1:m的关系
2,Adapter很多是候是1:1的关系
3,Bridge很多时候是m:n的关系
Facade模式注重简化接口，Adapter模式注重转换接口，Bridge模式注重分离接口（抽象）与其实现，
Decorator模式注重稳定接口的前提下为对象扩展功能。
*/
using namespace std;

class Smclass
{
public:
	void DoWork(){}
};
class SbClass
{
public:
	void Exce(){}
};
//Facade
class Facade
{
public:
	void DoWork()
	{
		auto_ptr<Smclass> ptr(new Smclass);	
		ptr->DoWork();
	}
	void Exec()
	{
		shared_ptr<SbClass> ptr(new SbClass);
		ptr->Exce();
	}
};

void TestFacade()
{

}