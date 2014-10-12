#pragma once
//OS SDK .h , C��׼�⡢C++��׼�⡢�������ͷ�ļ������Լ����̵�ͷ�ļ���
#include <iostream>

using namespace std;

class AutoPrototype
{
public:
	virtual AutoPrototype* Clone() const =0;  // =0 �����麯������ const �������� ��Ǻ���ǩ��
};

class BPrototype:public AutoPrototype
{
public:
	AutoPrototype* Clone() const;
};

AutoPrototype* BPrototype::Clone() const
{
	//������������в�������ָ�����͵�ȫ���޶������Ҳ�����û���޶�������ͬʱ�Լ����޶�����const��
	// 1. ��������������ָ�����޶��������޶������������͵�ָ�롣
    // 2. ���ָ����ָ������ͱ�������ұ�ָ����ָ�����͵�ȫ���޶�����
	//C++��׼�涨��const�ؼ��ַ������ͻ������֮ǰ�ȼ۵ġ�
    const int n=5; //same as below
    int const m=10;
	//const char* p=NULL; // p Ϊָ�� ������ �ǳ���ָ��

	char str[]="abc";
	//******************************
	const char* p=str;//pΪָ�� char ���͵� �ǳ���ָ��
	const char**pp=&p; //pp ָ�� const char* �ķǳ���ָ��  �Ǵ���� ��Ϊָ������������Ѿ���һ���� const ���
	//******************************

	char* ptr=str;
	char** const pp2=&ptr;
	//******************************
	char* const ptr2=str;
	const char* const* pp3=&ptr2;
	char* const* pp4=&ptr2;
	//******************************
	const char* ptr3=str;
	const char** const pp5=&ptr3;
	//******************************
	const char* const ptr4=str;
	const char* const* const pp6=&ptr4;
	//******************************
	char* const ptr5=str;
	char* const* const pp7=&ptr5;
	//*****************************
    const char* ptr6=str;
	const char** pp8=&ptr6;

	BPrototype* pt= new BPrototype(*this); //���ø��ƹ��캯��
	return pt;
}
//ԭ��ģʽ��
