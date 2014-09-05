//��һ�������װΪһ�����󣬴Ӷ�ʹ����ò�ͬ������Կͻ����в��������������Ŷӻ��¼������־���Լ�֧�ֿɳ����Ĳ�����
//����Ϊ�����ߡ��롰��Ϊʵ���ߡ�ͨ������һ�֡�����ϡ������⡣ 
/*
  (1) ����ϵͳ����϶ȡ������������������֮�䲻����ֱ�����ã�����������������֮��ʵ����ȫ�����ͬ�������߿��Զ�Ӧ��ͬ�Ľ����ߣ�ͬ������ͬ�Ľ�����Ҳ���Թ���ͬ��������ʹ�ã�����֮��������õĶ����ԡ�
  (2) �µ�������Ժ����׵ؼ��뵽ϵͳ�С����������µľ��������಻��Ӱ�쵽�����࣬��������µľ�������������ף������޸�ԭ��ϵͳԴ���룬�����ͻ�����룬���㡰����ԭ�򡱵�Ҫ��
  (3) ���ԱȽ����׵����һ��������л�������������
  (4) Ϊ����ĳ���(Undo)�ͻָ�(Redo)�����ṩ��һ����ƺ�ʵ�ַ�����
  ȱ�㣺ʹ������ģʽ���ܻᵼ��ĳЩϵͳ�й���ľ���������
*/
//һ��������������ĳ�ʼ�����߿����в�ͬ��������

#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class ICommand
{
public:
	virtual void Exec(void*)=0;
	virtual void ReDo()=0;
	virtual void Cancel()=0;
	virtual ~ICommand(){};
};

class ReciveFile
{
   //OpenFileCommand ������ִ����
};
class ReciveImage
{
	//ImageCommand ������ҵ��ִ����
};

class OpenFileCommand:public ICommand
{
public:
	OpenFileCommand(ReciveFile* ptr):recive(ptr)
	{

	}
	virtual void Exec(void* obj)
	{

	}
	virtual void ReDo()
	{

	}
	virtual void Cancel()
	{

	}
private:
	tr1::shared_ptr<ReciveFile> recive;
};
class OpenImageCommand:public ICommand
{
public:
	OpenImageCommand(ReciveImage* ptr):recive(ptr)
	{

	}
	virtual void Exec(void* obj)
	{

	}
	virtual void ReDo()
	{

	}
	virtual void Cancel()
	{

	}
private:
	tr1::shared_ptr<ReciveImage> recive;
};
class CommandManage
{
public:
	void AddCommand(ICommand* cmd)
	{
		this->commandlist.push_back(cmd);
	}
	void ExecCommand()
	{
		//����ִ���������
		//���߸��ݲ���ִ����һ�� ����
		//��¼��־
	}
private:
	vector<ICommand*> commandlist;
};

void TestCommand()
{
	ICommand* filecommand=new OpenFileCommand(new ReciveFile());
	ICommand* imagecommand=new OpenImageCommand(new ReciveImage());

	CommandManage cmage;
	cmage.AddCommand(filecommand);
	cmage.AddCommand(imagecommand);

	delete imagecommand;
	delete filecommand;
}


