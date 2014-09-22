
#pragma once
//��Ԫģʽ
// ���� ������� ����Ķ��� ���� ���ⴴ�������� �ظ��Ķ���


//���� ����ӵ����ͬ���ݵ�С��Ŀ��� ��ҹ���һ����
// �ҳ���Щ����Ⱥ �Ĺ�ͬ�� ���һ��Ԫ�� ��װ���Թ������ 
//���� ����һЩ������ȡ����Ӧ�� context �ǲ����Թ��� 
//flyWeight 2����Ҫ���� �ڲ�״̬  �ⲿ״̬
#include <vector>
#include <string>
#include <iostream>
#include <map>

using namespace std;

class Flyweight //���ü��� �� ��������
{
public:
	Flyweight(string str)
	{

	}
	virtual void Operator(string str)=0; //str �ⲿ״̬
private:
	string mstr;
};
class CFlyweight:public Flyweight
{
public:
	CFlyweight(string str):Flyweight(str)
	{
	}
	virtual void Operator(string str)
	{
		//
		//���ݴ�����ⲿ״̬ ������ز���
		//���� ��ʾ ��ӡ��� �ȵ�
		cout<<str<<endl;
	}
};
class UFlyweight:public Flyweight
{
public:
	UFlyweight(string str):Flyweight(str)
	{

	}
	virtual void Operator(string)
	{

	}
private:
	//����ȫ��״̬ //û������ //Clent ����ֱ������
};
class FlyweightFactory
{
public:
	static Flyweight* CreateFlyweight(string str)
	{
		Flyweight* ptr=NULL;
		map<string,Flyweight*>::iterator iter =cmap.find(str);
		if(iter==cmap.end())
			cmap[str]=new CFlyweight(str);
		ptr=cmap[str];
		return ptr;
	}

	~FlyweightFactory()
	{
		for(map<string,Flyweight*>::const_iterator iter=cmap.begin();iter!=cmap.end();++iter)
		{
			delete iter->second;
		}
	}
private:
	static map<string,Flyweight*> cmap;
};
map<string,Flyweight*> FlyweightFactory::cmap;

void TestFlyWeight()
{
	Flyweight* ptra=FlyweightFactory::CreateFlyweight("a");
	ptra->Operator("�ⲿ״̬");
	Flyweight* ptrb=FlyweightFactory::CreateFlyweight("a");
}
