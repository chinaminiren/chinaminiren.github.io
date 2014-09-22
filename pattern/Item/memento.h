#pragma once
//�ڲ��ƻ���װ��ǰ���� ����һ��������ڲ�״̬�����ڸö���֮�Ᵽ�����״̬��
//�����Ժ�Ϳɽ��ö���ָ���ԭ�ȱ����״̬
//�ڿ������ı�������У�����¼ģʽ�ṩ��һ����ά�ֶ���״̬��ͬʱά�ַ�װ�Եķ�����
//Ӧ��ֻ�з�������������з���Ȩ�޵����ݾ���Ч�ı�������˽���ԡ�
//��ģʽ��ͨ������Ϣ�ı���ͻ�ԭί�и�ĳ������¼���ά���˷����ߵļ��ԡ�
//���Ǳ���¼ģʽ��ʱ��Ҳ������ΪҪ�������Ϣ���ǳ��󣬻�ռ���൱��Ĵ洢�ռ䣬Ӱ��ϵͳ������Ч�ʡ�
#include <iostream>
#include <memory>
#include <functional>
#include <vector>
#include <Windows.h>
#include <string>
#include <winsock.h>

using namespace std;

class Data;

class Memento
{
public:

private:
	Memento(){};
	friend class Object;
	void SetData(Data* mda){da=mda;}
	Data* GetData(){return da;}
private:
	Data* da;
};

class Object
{
public:
	Memento* Create()
	{
		return new Memento(); //����״̬
	}
	void SetMemento(Memento* men)
	{
		da=men->GetData();
	}
private:
	Data* da;
};

class Catetaker
{
public:
	void SaveMemento(Memento* pt)
	{
		//���� 
	}

	Memento* Get()
	{
		return pt;
	}
private:
Memento* pt;//��α��� ������������ Hash
};

void TestMemento()
{
	Catetaker ct;
	Object obj; //
	//----����
	//
	ct.SaveMemento(obj.Create());
	//��������
	//
	//�ָ�...
	obj.SetMemento(ct.Get());
	//
}
