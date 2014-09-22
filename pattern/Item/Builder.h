
//������ģʽ����һ�����Ӷ���Ĺ��������ı�ʾ���룬ʹ��ͬ���Ĺ������̿��Դ�����ͬ�ı�ʾ��
//������ģʽ��ע���ǵ�������ͺ�װ�乤�գ�˳��
//������ģʽ
//ģ�巽��ģʽ
#pragma once
//OS SDK .h , C��׼�⡢C++��׼�⡢�������ͷ�ļ������Լ����̵�ͷ�ļ���
#include <iostream>

class Product
{
public:
	void MakeA(){}
	void MakeB(){}
	void MakeC(){}
	void MakeD(){}
};

class IBuilder
{
public:
	virtual void Init(){
		this->product=new Product();
	}
	virtual void MakeA()=0;
	virtual void MakeB()=0;
	virtual void MakeC()=0;
	virtual void MakeD()=0;
	virtual Product* GetProduct()=0;
protected:
	Product* product;
};
class Builder:public IBuilder
{
public:
	virtual void MakeA()
	{
		this->product->MakeA();
	}
	virtual void MakeB()
	{
		this->product->MakeB();
	}
	virtual void MakeC()
	{
		this->product->MakeC();
	}
	virtual void MakeD()
	{
		this->product->MakeD();
	}
	virtual Product* GetProduct()
	{
		return this->product;
	}
};

class  Director
{
public:
	Product* Construct(IBuilder* builer)
	{
		builer->Init();
		builer->MakeA();
		builer->MakeB();
		builer->MakeC();
		builer->MakeD();
		return builer->GetProduct();
	}
};

void TestBuilder()
{
	Director director;
	Builder builder;
	Product* ptr=director.Construct(&builder);
	Product* ptr2=director.Construct(&builder);
}
