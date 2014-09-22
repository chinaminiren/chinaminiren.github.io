#pragma once
#include <memory>
#include <vector>
#include <string>
#include <iostream>
/*
 Iterator����������ģʽ�ֳ�Cursor���α꣩ģʽ�������ṩһ�ַ���˳�����һ���ۺ϶����и���Ԫ��, 
 ���ֲ��豩¶�ö�����ڲ���ʾ����������˵���ܸ�������⣺Iteratorģʽ�������ھۺ϶����һ��ģʽ��
 ͨ�����ø�ģʽ��ʹ�����ǿ����ڲ�֪�������ڲ���ʾ������£�����һ��˳����iterator�ṩ�ķ��������ʾۺ϶����еĸ���Ԫ�ء�

 �ṩһ�ַ���˳�����һ���ۺ϶����и���Ԫ�أ����ֲ���¶�ö�����ڲ���ʾ��������Ҫ����һ���ۼ�����
 ���Ҳ�����Щ������ʲô����Ҫ������ʱ�򣬾�Ӧ�ÿ����õ�����ģʽ��ͬʱ��Ҫ�Ծۼ��ж��ַ�ʽ����ʱ��
 ���Կ����õ�����ģʽ��Ϊ������ͬ�ľۼ��ṹ�ṩ�翪ʼ����һ�����Ƿ��������ǰ��һ���ͳһ�ӿڡ�
 ������ģʽ���Ƿ����˼��϶���ı�����Ϊ�������һ���������������������ȿ�����������¶���ϵ��ڲ��ṹ��
 �ֿ����ⲿ����͸���ط��ʼ����ڲ������ݡ�
 */
using namespace std;

class IIterator
{
public:
	virtual ~IIterator(){}
	virtual void First()=0;
	virtual void Next()=0;
	virtual bool IsEOF()=0;
	virtual int CurrentItem()=0;
};
class BookAggregate;

class Iterator:public IIterator
{
public:
	Iterator(BookAggregate* mag)
	{
		this->ag=mag;
	}
	virtual void First()
	{
		this->i=0;
	}
	virtual void Next()
	{
		++i;
	}
	virtual bool IsEOF()
	{
		return false;
	}
	virtual int CurrentItem()
	{
		return 1;
	}
private:
	BookAggregate* ag;
	int i;
};

class Aggregate
{
public:
	virtual IIterator* CreateIterator()=0;
};
class BookAggregate:public Aggregate
{
public:
	virtual IIterator* CreateIterator()
	{
		return new Iterator(this);
	}
private:
	vector<int> vec;
};

class IteratorPtr
{
public:
	IteratorPtr(IIterator* iter)
	{
		this->miter=iter;
	}
	~IteratorPtr()
	{
		delete miter;
	}

	IIterator* operator->()
	{
		return miter;
	}
	IIterator& operator*()
	{
		return *miter;
	}
private:
	IIterator* miter;
	//TODO:STL �еĵ����� ֧�� �������
	//
	IteratorPtr(const IteratorPtr&); 
	IteratorPtr& operator=(const IteratorPtr&);
};



void TestIterator()
{
	Aggregate* ba=new BookAggregate();
	IIterator* iter=ba->CreateIterator();
	IteratorPtr ptr(iter);
}