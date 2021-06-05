#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//ʱ�临�Ӷ�
//����:�ڼ������ѧ��,�㷨��ʱ�临�Ӷ���һ������,�����������˸��㷨������ʱ��.
//     һ���㷨�����ѵ�ʱ������������ִ�д�����������,�㷨�еĻ���������ִ�д���,Ϊ�㷨��ʱ�临�Ӷ�

//��O�Ľ�����ʾ��
void Func1(int N)
{
	int count = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j > N; ++j)
		{
			++count;
		}
	}
	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}

	int m = 10;
	while (m--)
	{
		++count;
	}

	printf("%d\n", count);
}

//Func1ִ�еĻ�����������:  F(N) = N^2 + 2*N + 10
//ʵ�������Ǽ���ʱ�临�Ӷ�ʱ,������ʵ����һ��Ҫ���㾫ȷ��ִ�д���,��ֻ��Ҫ���ִ�д���,��ô��������ʹ�ô�O�Ľ�����ʾ��

//��O����:��������������������Ϊ����ѧ����

//�Ƶ���O�׷���:
//1.�ó���1ȡ������ʱ���е����мӷ�����
//2.���޸ĺ�����д���������,ֻ������߽���
//3.�����߽�������Ҳ���1,��ȥ���������Ŀ��˵ĳ���,�õ��Ľ�����Ǵ�O��

//��ʱFunc1��ʱ�临�Ӷ�Ϊ:O(N^2)

//������Щ�㷨��ʱ�临�Ӷȴ������,ƽ����������
//��ʵ����һ�������ע�����㷨����������,������������������ʱ�临�Ӷ�ΪO(N)

//����Func2��ʱ�临�Ӷ�
void Func2(int N)
{
	int count = 0;
	for (int k = 0; k < 2 * N; ++k)
	{
		++count;
	}

	int M = 10;
	while (M--)
	{
		++count;
	}
	printf("%d\n", count);
}
//ʱ�临�Ӷ�Ϊ:O(N)


//����Func3��ʱ�临�Ӷ�
void Func3(int N, int M)
{
	int count = 0;

	for (int k = 0; k < M; ++k)
	{
		++count;
	}
	for (int k = 0; k < N; ++k)
	{
		++count;
	}
	printf("%d\n", count);
}
//ʱ�临�Ӷ�Ϊ:O(M+N)


//����Func4��ʱ�临�Ӷ�
void Func4(int N)
{
	int count = 0;

	for (int k = 0; k < 100; ++k)
	{
		++count;
	}

	printf("%d\n", count);
}
//ʱ�临�Ӷ�Ϊ:O(1)


//����BubbleSort��ʱ�临�Ӷ�
void BubbleSort(int* a, int n)
{
	assert(a);
	for (size_t end = n; end > 0; --end)
	{
		int exchange = 0;
		for (size_t i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}

		if (exchange == 0)
			break;
	}
}
//ʱ�临�Ӷ�ΪO(N^2)


//����BinarySearch��ʱ�临�Ӷ�
int BinarySearch(int* a, int n, int x)
{
	assert(a);

	int begin = 0;
	int end = n;
	while (begin < end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (a[mid] < x)
		{
			begin = mid + 1;
		}
		else if (a[mid] > x)
			end = mid;
		else
			return mid;
	}

	return -1;
}
//ʱ�临��ΪO(logN)


//����׳˽׳˵ݹ�Factorial��ʱ�临�Ӷ�
long long Factorial(size_t N)
{
	return N < 2 ? N : Factorial(N - 1)*N;
}
//ʱ�临�Ӷ�ΪO(N)
//�ݹ��㷨��μ���:�ݹ����*ÿ�εݹ麯���Ĵ���


//����쳲������ݹ�Fibonacci��ʱ�临�Ӷ�
long long Fibonacci(size_t N)
{
	return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
}
//�ܵĵ��ô���1+2+2^2+2^3+2^4 + ... + 2^(n-1) = 2^n - 1
//ʱ�临�Ӷ�Ϊ2^n

//�������쳲���������
long long* Fibonacci(size_t N)
{
	long long* fibArray = malloc(sizeof(long long)*N);
	fibArray[1] = 0;
	if (N == 0)
	{
		return fibArray;
	}

	fibArray[2] = 1;
	//�ռ任ʱ��
	for (int i = 2; i <= N; i++)
	{
		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
	}
	return fibArray;
}


//�ռ临�Ӷ�
//�ռ临�Ӷ��Ƕ�һ���㷨�����й�������ʱռ�ô洢�ռ��С�ı���.�ռ临�ӶȲ��ǳ���ռ���˶���bytes�Ŀռ�,��Ϊ���Ҳû��̫������,���Կռ临�Ӷ�����Ǳ����ĸ���.
//�ռ临�Ӷȼ�����������ʱ�临�Ӷ�����,Ҳʹ�ô�O������ʾ��.


//����BubbleSort�Ŀռ临�Ӷ�
void BubbleSort(int* a, int n)
{
	assert(a);
	for (size_t end = n; end > 0; --end)
	{
		int exchange = 0;
		for (size_t i = 1; i < end; ++i)
		{
			if (a[i - 1] > a[i])
			{
				Swap(&a[i - 1], &a[i]);
				exchange = 1;
			}
		}

		if (exchange == 0)
			break;
	}
}
//������ı�����:a,n,end,exchange,i�������
//�������Ŀռ临�Ӷ�ΪO(1),Ϊ����������


//����BinarySearch�Ŀռ临�Ӷ�
int BinarySearch(int* a, int n, int x)
{
	assert(a);

	int begin = 0;
	int end = n;
	while (begin < end)
	{
		int mid = begin + ((end - begin) >> 1);
		if (a[mid] < x)
		{
			begin = mid + 1;
		}
		else if (a[mid] > x)
			end = mid;
		else
			return mid;
	}

	return -1;
}
//�ռ临�Ӷ�ΪO(N)


//����ռ临�Ӷ�
long long* Fibonacci(size_t N)
{
	long long* fibArray = malloc(sizeof(long long)*N);
	fibArray[1] = 0;
	if (N == 0)
	{
		return fibArray;
	}

	fibArray[2] = 1;
	
	for (int i = 2; i <= N; i++)
	{
		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
	}
	return fibArray;
}
//�ռ临�Ӷ�ΪO(N)