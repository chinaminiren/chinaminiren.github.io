#pragma once

#include <iostream>
#include <string>

using namespace std;

//�����еĽӿڽ��� ��װ ���� �ﵽ �ͻ���Ҫ��
// ���� �û���Ҫʵ��һ�� ջ...��Ŀǰ�ӿ�ֻ�� ����
//��Ҫ�� ����ģ��һ�� ��ջ
//����������
//��������

class Array
{
public:
	void Add(string str)
	{
		//
	}
	void Get(int key)
	{
		//
	}
};

class StackAdapter  //Ҳ�����ü̳�ʵ��
{
public:
	void Pop(){}
	void Push(){}
private:
	Array array;
};

void TestAdapter()
{
	//
	StackAdapter sa;
}