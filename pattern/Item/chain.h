#pragma once
//ְ����ģʽ
//ʹ��������л��ᴦ�����󣬴Ӷ���������ķ����� �ͽ�����֮�����Ϲ�ϵ
//����Щ��������������������������ݸ�����ֱ�������󱻴���Ϊֹ

// ����Ч �޳������е� if elseif  ���

// �������Ա�

#include <iostream>
#include <memory>
#include <functional>
#include <vector>
#include <Windows.h>
#include <string>
//#include <winsock.h>

using namespace std;

class Handler
{
public:
	virtual void Request()=0;
private:
	Handler* nextHander;
};

class AHandler:public Handler
{
public:
	virtual void Request()
	{
		//
	}
};

class BHandler:public Handler
{
public:
	virtual void Request()
	{
		//
	}
};
void TestChain()
{
	//
}


