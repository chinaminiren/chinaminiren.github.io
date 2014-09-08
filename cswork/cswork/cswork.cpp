// cswork.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

template<typename T>
void printArray(T* ar, int N)
{
	int i = 0;
	while (i != N)
	{
		std::cout << ar[i++] << " ";
	}
	std::cout << endl;
}
template<typename T>
void printArray(T* ar, int i, int j)
{
	while (i <= j)
	{
		std::cout << ar[i++] << " ";
	}
	std::cout << endl;
}
template<typename T>
T maxN(T a, T b)
{
	return a > b ? a : b;
}

bool isSwap(int* ar, int i, int j)
{
	while (i < j)
	{
		if (ar[j] == ar[i])
			return false;
		i++;
	}
	return true;
}
void allpai2(int* str, int i, int j)
{
	if (i == j)
	{
		printArray(str, j + 1);
	}
	else
	{
		for (int m = i; m <= j; ++m)
		{
			if (!isSwap(str, i, m))
				continue;
			std::swap(str[m], str[i]);
			allpai2(str, i + 1, j);
			std::swap(str[m], str[i]);
		}
	}
}
void allpai(int* str, int i, int j)
{
	//
}
#define MaxA 20
#define MaxB 20
void huiWen(char* str, int i, int j)
{
	int T[MaxA][MaxB] = { { 0 }, { 0 } };
	int k = -1;
	int p = -1;
	for (int m = i; m <= j; m++)
	{
		T[m][m] = 1;
		if (m + 1 <= j&&str[m] == str[m + 1])
		{
			T[m][m + 1] = 2;
			k = m;
			p = m + 1;
		}
	}

	for (int m = 3; m <= j - i + 1; m++)
	{
		for (int n = i; n <= j; n++)
		{
			if (n + m - 1 > j)
				break;
			if (str[n] == str[n + m - 1])
			{
				int key = T[n][n + m - 1] = T[n + 1][n + m - 2] + 2;
				if (key > (p - k + 1))
				{
					k = n;
					p = n + m - 1;
				}
			}
			else
			{
				T[n][n + m - 1] = T[n + 1][m - 2];
			}
		}
	}
	printArray(str, i, j);
	printArray(str, k, p);
}
void chengJi(int* ar, int i, int j)
{
	//
	//
}

/*
��̬�滮�㷨
�����������
*/
void getSum(int* ar, int i, int j)
{
	int maxSum = ar[i];
	int temp = 0;
	int p = 0;
	int q = 0;
	int t = 0;
	for (int m = i; m <= j; m++)
	{
		if (temp < 0)
		{
			temp = ar[m];
			t = m;
		}
		else
		{
			temp = ar[m] + temp;
		}

		if (temp > maxSum)
		{
			maxSum = temp;
			p = t;
			q = m;
		}
	}
	std::cout << p << " " << q << " " << maxSum << endl;
}
void dpGetSum(int* arr, int i, int j)
{
	int End[30] = { 0 };
	int All[30] = { 0 };

	End[i] = All[i] = arr[i];

	for (int m = i+1; m <= j; ++m)
	{
		End[m] = maxN(End[m - 1] + arr[m], arr[m]);
		All[m] = maxN(End[m], All[m - 1]);
	}
	cout << All[j] << endl;
}

#define MAX 100
void lis(int* ar, int i, int j) //� ������ ���������� 
{
	int T[MAX] = { 0 };

	T[0] = 1;
	for (int m = 1; m <= j; ++m)
	{
		T[m] = 1;
		for (int n = i; n < m; ++n)
		{
			if (ar[n] < ar[m])
			{
				T[m] = maxN(T[m], T[n] + 1);
			}
		}
	}
	printArray(T, j + 1);
}

void lcs(int* ar, int i, int* ay, int j)
{
	//
	//

}

// 0 1 ���� ����Ҫ��ȫװ��
void back()
{
	int V[] = { 1, 2, 3, 4, 5 };
	int W[] = { 1, 2, 3, 4, 5 };
	int C = 5;
	const size_t N = sizeof V / sizeof(int);

	int	dp[10][10] = { { 0 }, { 0 } };

	for (int i = 0; i < N; ++i) // ��ʯ ��
	{
		for (int j = 0; j <= C; ++j) // ������С
		{
			if (i == 0)
			{
				dp[i][j] = j >= W[i] ? V[i] : 0;
			}
			else
			{
				if (j < W[i])
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
				}
			}
			cout <<i<<" "<<j<<" "<< dp[i][j] << endl;
		}
	}
}

// ���� װ��
void back2() 
{
	int V[] = { 2, 3, 1, 7, 5 };
	int W[] = { 2, 1, 3, 4, 5 };
	int C = 7;
	const size_t N = sizeof V / sizeof(int);
	int min = -38900000;
	int	dp[10][10] = { { 0 }, { 0 } };

	for (int i = 0; i < N; ++i) // ��ʯ ��
	{
		for (int j = 0; j <= C; ++j) // ������С
		{
			if (i == 0)
			{
				if (j == W[i])
				{
					dp[i][j] = V[i];
				}
				else
				{
					dp[i][j] = min;
				}
			}
			else
			{
				if (j < W[i])
				{
					dp[i][j] = dp[i - 1][j];
				}
				else
				{
					dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - W[i]] + V[i]);
				}
			}
			cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
}

//��ȫ����
void allBack()
{
	int V[] = { 2, 3, 1, 7, 5 };
	int W[] = { 2, 1, 3, 4, 5 };
	int	dp[20][20] = { { 0 }, { 0 } };
	int C = 7;
	for (int i = 0; i <= 4; ++i)
	{
		for (int j = 0; j <= C; ++j)
		{
			int num = j / W[i];
			if (i > 0)
			{
				if (num >= 1)
				{
					int max = 0;
					for (int k = 1; k <= num; ++k)
					{
						max = std::max(dp[i - 1][j - k*W[i]] + k*V[i], max);
					}
					dp[i][j] = std::max(dp[i - 1][j], max);
				}
			}
			else
			{
				if (num >= 1)
				{
					dp[i][j] = j / W[i] * V[i];
				}
			}
			cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
}



//�ַ��� ƥ�����
void KMP(const char* meg, int M, const char* str, int N)
{
	//str = BBCABCDABABCDABCDABDE

	//meg = ABCDABD
	//��Next���飺 http://blog.csdn.net/yaochunnian/article/details/7059486
	//AAC 
	//AAA
	int* Next = new int[M];
	Next[0] = 0;
	int j = 0;
	for (int i = 1; i < M; ++i)
	{
		int m = 0;
		for (int j = 0; j <= i; ++j)
		{	
			
		}
	}
	

	delete[] Next;
}
void BM(char* meg, int M, char* str, int N)
{
	//
	//
}
//�����㷨

//̰���㷨

//��ʹ�õݹ�����������м��ַ�����������������������Morris�㷨��ͨ����ʱת�����������һ����������Ľṹ����

//�����Ż�

//�ַ����༭����

//ϣ������
//��������
//DP  �㷨
//KMP �� BM �㷨  
//����Ĵ� O(n) �㷨?
//ȫ���� �ǵݹ��㷨?
//�����㷨
//������Ӵ���Longest CommonSubstring��������������У�LongestCommon Subsequence��LCS��   �����������(����  or  ������) 
//�����ַ������ƶ�
//C++ ��ά����

//�㷨�� �㷨:������˼��



int memcmp(const void* s1,const void* s2, size_t n)
{
	//
}
int strcmp(const char* s1, const char* s2)
{
	//�����ַ���������������ַ���ȣ���ASCIIֵ��С��Ƚϣ���
	//ֱ�����ֲ�ͬ���ַ�����'\0'Ϊֹ
}

int _tmain(int argc, _TCHAR* argv[])
{
	int ar[] = { -8, 8, -4, -5, -6 };

	string meg("ABCDABD");
	string str("BBCABCDABABCDABCDABDE");
	KMP(meg.data(), meg.length(), str.data(), str.length());
	// 0 1����
	//allBack();



	//int ar[] = { 1, 2, 2};
	//int n = sizeof(ar) / sizeof(int);
	//allpai(ar, 0, n - 1);

	//char * str = "5961564321234"; //432111234
	//size_t n = strlen(str);
	//huiWen(str, 0, n-1);

	//getSum(ar, 0, sizeof(ar) / sizeof(int) - 1);
	//dpGetSum(ar, 0, sizeof(ar) / sizeof(int) - 1);

	//int ar[] = { 3, 5, 1, 8, -6, -6 ,5, 6, 7, 3 };
	//int n = sizeof(ar) / sizeof(int);
	//lis(ar, 0, n - 1);

	int key;
	std::cin >> key;
	return 0;
}

