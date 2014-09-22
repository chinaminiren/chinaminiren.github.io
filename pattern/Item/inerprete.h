#pragma once
//������ģʽ
//����һ�����ԣ����������ķ���һ�ֱ�ʾ��������һ����������
//���������ʹ�ø��ֱ�ʾ�����������еľ���

#include <iostream>
#include <memory>
#include <functional>
#include <vector>
#include <Windows.h>
#include <string>

using namespace std;

class Context; //����������֮���ȫ����Ϣ

class Expression
{
public:
	 virtual void Interprete(Context*)=0;
};

class TerminalExpression:public Expression
{
public:
	virtual void Interprete(Context* ptr)
	{

	}
};

class NonATerminalExpression:public Expression
{
public:
	virtual void Interprete(Context* ptr)
	{
		//
	}
};

class NonBTerminalExpression:public Expression
{
public:
	virtual void Interprete(Context* ptr)
	{
       //
	}
};

void TestInterprete()
{

}
