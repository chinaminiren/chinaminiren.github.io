#pragma once
#include <string>
#include <iostream>
#include <memory>

//װ��ģʽ
//�ڲ��ı�����нӿڵ�����¶�̬����չ һ������Ĺ���
//װ�ζ��� ����һ����ʵ���������
//װ�ζ�������������Կͻ��˵����󡣰���Щ����ת������ʵ�Ķ���
//װ�ζ������ת����Щ���� ��ǰ�����Ժ�����һЩ�������ܡ�������ȷ��������ʱ��
//�����޸ĸ�������Ľṹ�Ϳ������ⲿ���Ӹ��ӵĹ��ܡ�
// AOP
//װ�� �̳� �Ƚ�
//
//���ǿ���ͨ���̳еķ�ʽ����ԭ���������¹��ܣ�����װ����ģʽ������ϵķ�ʽ���������������
using namespace std;

class Tank
{
public:
	void Run()
	{
		cout<<"run"<<endl;
	}
};

class Decorator
{
public:
	void Run()
	{
		//add other 
		tank.Run();
		//add other
	}
private:
	void Add()
	{
		cout<<"add other"<<endl;
	}
private:
	Tank tank;
};
void TestDecorator()
{
	Decorator tank;
	tank.Run();
}