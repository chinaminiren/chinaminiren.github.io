//ģ�巽�� ���ɳ����ඨ��һ���㷨�ĹǼܣ�����������������ʵ���㷨�е��߼���
//����ģʽ�Ļ����Ƿ�װ�˿����໥�滻�Ķ����Ϊ��Ҳ�����㷨����Ȼ�������ڿͻ��˶�̬����������һ����Ϊ��

#include <iostream>

using namespace std;

class BaseTemplate
{
public:
	void DoWork()
	{
		this->WorkA();
		this->WorkB();
	}
protected:
	virtual void WorkA()=0;
	virtual void WorkB()=0;
};
class Cream:public BaseTemplate
{
protected:
	virtual void WorkA();
	virtual void WorkB();
};
void Cream::WorkA()
{
	std::cout<<"workA Cream"<<endl;
}
void Cream::WorkB()
{
	std::cout<<"workB Cream"<<endl;
}

void TestTemplateMethod()
{
	BaseTemplate* ptr=new Cream();
	ptr->DoWork();
}
