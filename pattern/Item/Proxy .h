#pragma once
#include <string>
#include <iostream>
#include <memory>

//����ģʽ
//
//��һ��������з��ʿ���
//�����ӳټ���һ������
using namespace std;

class Work
{
public:
	void Do()
	{
		//
	}
};

void TestProxy()
{
	weak_ptr<Work> ptr(make_shared<Work>(new Work()));
}