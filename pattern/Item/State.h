#pragma once
//����һ�����������ڲ�״̬�ı�ʱ �ı�������Ϊ��
// ״̬����
//
#include <iostream>
#include <memory>
#include <functional>
#include <vector>
#include <Windows.h>
#include <string>
#include <winsock.h>

using namespace std;

class TcpSate
{
public:
	virtual void Open() =0;
	virtual void Close()=0;
	virtual void Acknowledge()=0;
};
class TcpEstablished:public TcpSate
{
public:
	void Open()
	{
		cout<<"TcpEstablished Open"<<endl;
	}

	void Close()
	{
		cout<<"TcpEstablished Close"<<endl;
	}

	void Acknowledge()
	{
		cout<<"TcpEstablished Acknowledge"<<endl;
	}
};
class TcpCosed:public TcpSate
{
public:
	void Open()
	{
		cout<<"TcpCosed Open"<<endl;
	}
	void Close()
	{
		cout<<"TcpCosed Close"<<endl;
	}
	void Acknowledge()
	{
		cout<<"TcpCosed Acknowledge"<<endl;
	}
};
class TcpConnection
{
public:
	TcpConnection(TcpSate* mste)
	{
		this->ste=mste;
	}
	void Open()
	{
		ste->Open();
	}
	void Close()
	{
		ste->Close();
	}
	void Acknowledge()
	{
		ste->Acknowledge();
	}
private:
	TcpSate* ste;
};
void TestState()
{
	TcpConnection tc(new TcpEstablished());
	tc.Acknowledge();
	//״̬�ı� ������ State�� ���иı� Ҳ������ TcpConnection �н��иı�

}


