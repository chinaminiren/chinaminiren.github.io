#include <string>
#include <iostream>
#include <assert.h>
#include <iterator>

using namespace std;
void parry(int* ptr,int N)
{
	int i = 0;
	while(i< N)
	{
		cout<<ptr[i]<<" ";
		++i;
	}
	cout<<endl;
}
//template<typename T>
//T& MAX(T& a,T&b>
//{
//	return a > b ? a : b;
//}

int atoi(const char* ptr)
{
	assert(ptr != NULL);
	int result = 0;
	int sign = 1;
	while(*ptr ==' ' || *ptr =='\n' ||*ptr == '\t')
		++ptr;
	if(*ptr == '-')
	{
		sign = -1;
		++ptr;
	}
	else if(*ptr == '+')
	{
		++ptr;
	}
	while(*ptr > '0' && *ptr <'9')
	{
		result = result * 10 + *ptr - '0';
		++ptr;
	}
	return result * sign;
}
int reverseInt(int x) //整数 取反
{
	int y = 0;
	while(x != 0)
	{
		y = y * 10 + x % 10;
		x = x/10;
	}
	return y;
}
void exchange(int& a,int& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}
char* strcpys(char* dest, const char* src)
{
	 assert(src != NULL);
	 assert(dest != NULL);
     char* destTemp = dest;
	 while(*destTemp++ = *src++){}
	 return dest;
}
char *strcats(char *strDest, const char *strSrc)
{
    assert(strDest !=NULL);
	assert(strSrc !=NULL);

	char* strDestT = strDest;
	while(*strDestT)
	{
		strDestT++;
		//若使用while(*strDest++)，则会出错，因为循环结束后strDest还会执行一次++,
		//因为他是后++  所以是先进行运算，在运算结束后才进行自加的。
	}
	while(*strDestT++ = *strSrc++)
	{
		//
	}
	return strDest;
}
void* memcpy(void* dest,const void* src,size_t n)
{
	assert(dest != NULL);
	assert(src != NULL);
	char* cdest = (char*)dest;
	const char* csrc = (const char*)src;
	while (n--)
	{
		*cdest++ = *csrc++;
	}
	return dest;
}
void* memmove(void* dest,const void* src,size_t n)
{
	assert(dest !=NULL);
	assert(src != NULL);
	char* cdest = (char*)dest;
	const char* csrc = (const char*)src;
	if(cdest < csrc)
	{
		while(n--)
		{
			*cdest++ = *csrc++;
		}
	}
	else if(csrc < cdest)
	{
		//
		csrc = csrc + n -1;
		cdest = cdest +n -1;
		while(n--)
		{
			*cdest-- = *csrc--;
		}

	}
	return dest;
}
void reverseStr(char* str,int i,int j)
{
	assert(str);
	if(i>=j)
		return;
	std::swap(str[i],str[j]);
	reverseStr(str,++i,--j);
}
void pchararray(const char* ptr)
{
	assert(ptr);
	while(*ptr)
	{
		cout<<*ptr;
		ptr++;
	}
	cout<<endl;
}
bool reversePsr(char* str,int i,int j)
{
	//判断字符串是否为回文
	assert(str);
	if(i>j)
		return true;
	if(str[i] == str[j])
	   return reversePsr(str,++i,--j);
		return false;
}

//***********************************************************
int partion(int* ar,int i,int j)
{
	int key = ar[j];
	int n=i;
	for(int m = i ;m < j; ++m)
	{
		if(ar[m] < key)
		{
			std::swap(ar[m],ar[n]);
			n++;
		}
	}
	std::swap(ar[n],ar[j]);
	return n;
}
void qsort(int* ar,int i,int j)
{
	if(i >= j)
		return;
	int p = partion(ar,i,j);
	qsort(ar,i,p-1);
	qsort(ar,p+1,j);
}
void tqsort()
{
	int dest[5]={1,3,1,0,1};
	qsort(dest,0,4);
	parry(dest,5);
}
void adjustheap(int* ar,int i,int N) //N 最大索引 index
{
    while(i <= N)
	{
		int r = 2*i+2;
		int l =2*i+1;
		int k = i;
		if(r <= N && ar[k]<ar[r])
		{
			k = r;
		}
		if(l <= N && ar[k]<ar[l])
		{
			k = l;
		}
		if(i == k)
			break;
		std::swap(ar[i],ar[k]);
		i = k;
	}
}
void makeheap(int* ar,int N)
{
	for(int i=N/2 - 1;i >= 0;i--)
	{
		adjustheap(ar,i,N);
	}
}
void hsort(int* ar,int N)
{
	makeheap(ar,N);
	for(int i = 0;i <= N;++i)
	{
		std::swap(ar[0],ar[N-i]);
		adjustheap(ar,0,N-i-1);
	}
}
void thsort()
{
	int dest[5]={3,7,2,2,1};
	hsort(dest,4);
	parry(dest,5);
}

void mergesort(int* ar,int* nr,int m,int n,int i,int j) //N
{
    //
	int a [12][12];
	a[2][2] = 0;
}
//
void productNum(int* ar,int i,int j)
{
	parry(ar,j+1);
	int endmax [30]={0};
	int endmin [30]={0};
	int dp[30]={0};
	dp[0]=endmax[0] = endmin[0]=ar[0];

	for(int m=i+1;m<=j;++m)
	{
		endmin[m]=min(min(endmin[m-1]*ar[m],ar[m]),endmax[m-1]*ar[m]);
		endmax[m]=max(max(endmax[m-1]*ar[m],ar[m]),endmin[m-1]*ar[m]);
		dp[m]=max(dp[m-1],endmax[m]);
	}
	cout<<dp[j]<<endl;
}

void stringDistance(int* A,int M,int* B,int N)
{
	//
}
//***********************************************************

/*
各种排序：

//Tok K

//树 查询 遍历

//AVL 红黑树

//Hash

//KMP

字符串应用：
自动机，KMP算法，Extend-KMP，后缀树，后缀数组，trie树，trie图及其应用
*/
/*
用两个栈实现一个队列
检测单向链表上的环

LCA 最长公共祖先
字符串匹配查找 KMP

添加最少字符数构成使字符串构成回文

http://blog.csdn.net/jiyanfeng1/article/details/8045023
http://blog.csdn.net/ggggiqnypgjg/article/details/6645812
*/

void TestTT()
{
	/*
	int a = 10;
	int b = 20;
	exchange(a,b);
	cout<<a<<" "<<b<<endl;
	*/
	/*
	char * ptr="-123dd";
	int a = atoi(ptr);
	cout<<a<<endl;
	*/
	/*
	int a = -123;
	int b = reverseInt(a);
	cout<<b<<endl;
	*/
	/*
	char dest[20]="123";
	char* ptr="456";
	cout<<strcats(dest,ptr)<<endl;
	*/
	/*
	char dest[20]="123456";
	reverseStr(&dest[0],0,5);
	pchararray(dest);
	*/
	/*
	char dest[20]="121121";
	bool flag = reversePsr(&dest[0],0,5);
	cout<<flag<<endl;
	*/

	//

	int arr[]={-2,-8,-12,-7,-3,-33};
	productNum(arr,0,5);
}