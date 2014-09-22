
#include "stdafx.h"
#include <queue>
#include <deque>
#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <functional>
#include <string>
#include <memory>
#include <map>
#include <set>

using namespace std;

class SM :std::enable_shared_from_this < SM >
{
public:
	void meg()
	{
		cout << "meg" << endl;
	}
};

class Base
{
public:
	void Work(int a)
	{
		cout<<a<<endl;
	}
};

class CBase
{
public:
	void Work(Base a)
	{
		//
	}
};

int _tmain(int argc, _TCHAR* argv[])
{	 
	int** ptr =new int* [10];
	map<int,int> mp;
	vector<Base> vc;
	//std::for_each(vc.begin(),vc.end(),&CBase::Work);
	return 0;
}

