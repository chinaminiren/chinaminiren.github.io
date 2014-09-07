
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


using namespace std;

class SM :std::enable_shared_from_this < SM >
{
public:
	void meg()
	{
		cout << "meg" << endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{	 
	SM* ptr = new SM();
	ptr->meg();
  
	return 0;
}

