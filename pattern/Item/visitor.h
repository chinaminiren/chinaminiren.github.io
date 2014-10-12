#pragma once
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
#include <new>

using namespace std;
//������ ģʽ
//���Ǳ�ʾһ��������ĳ����ṹ�еĸ�Ԫ�صĲ�������ʹ������ڲ��ı��Ԫ�ص����ǰ���¶�����������ЩԪ�ص��²�����
class Visitor;

class Item //��Ϊ�ӿ� �� ������ ʵ�ָýӿ�
{
public:
	virtual void Accept(Visitor&)=0;
};

class Visitor
{
public:
	virtual void vis(ItemA&)=0;
	virtual void vis(ItemB&)=0;
};

class ItemA:public Item
{
private:
	virtual void Accept(Visitor& vs)
	{
		vs.vis(*this);
	}
};
class ItemB:Item
{
public:
	virtual void Accept(Visitor& vs)
	{
		vs.vis(*this);
	}
};

class ConVisitor
{
public:
    virtual void vis(ItemA&)
	{
		string str("�Զ��� ����A Ԫ�صĲ���");
		cout<<str<<endl;
	}
	virtual void vis(ItemB&)
	{
		string str("�Զ��� ����B Ԫ�صĲ���");
		cout<<str<<endl;
	}
};

void TestVisitor()
{
   
}