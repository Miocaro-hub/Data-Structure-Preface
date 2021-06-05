#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//时间复杂度
//定义:在计算机科学中,算法的时间复杂度是一个函数,它定量描述了该算法的运行时间.
//     一个算法所花费的时间与其中语句的执行次数成正比例,算法中的基本操作的执行次数,为算法的时间复杂度

//大O的渐进表示法
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

//Func1执行的基本操作次数:  F(N) = N^2 + 2*N + 10
//实际中我们计算时间复杂度时,我们其实并不一定要计算精确的执行次数,而只需要大概执行次数,那么这里我们使用大O的渐进表示法

//大O符号:是用于描述函数渐进行为的数学符号

//推导大O阶方法:
//1.用常数1取代运行时间中的所有加法常数
//2.在修改后的运行次数函数中,只保留最高阶项
//3.如果最高阶项存在且不是1,则去除与这个项目相乘的常数,得到的结果就是大O阶

//此时Func1的时间复杂度为:O(N^2)

//另外有些算法的时间复杂度存在最好,平均和最坏的情况
//在实际中一般情况关注的是算法的最坏运行情况,所以数组中搜索数据时间复杂度为O(N)

//计算Func2的时间复杂度
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
//时间复杂度为:O(N)


//计算Func3的时间复杂度
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
//时间复杂度为:O(M+N)


//计算Func4的时间复杂度
void Func4(int N)
{
	int count = 0;

	for (int k = 0; k < 100; ++k)
	{
		++count;
	}

	printf("%d\n", count);
}
//时间复杂度为:O(1)


//计算BubbleSort的时间复杂度
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
//时间复杂度为O(N^2)


//计算BinarySearch的时间复杂度
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
//时间复杂为O(logN)


//计算阶乘阶乘递归Factorial的时间复杂度
long long Factorial(size_t N)
{
	return N < 2 ? N : Factorial(N - 1)*N;
}
//时间复杂度为O(N)
//递归算法如何计算:递归次数*每次递归函数的次数


//计算斐波那契递归Fibonacci的时间复杂度
long long Fibonacci(size_t N)
{
	return N < 2 ? N : Fibonacci(N - 1) + Fibonacci(N - 2);
}
//总的调用次数1+2+2^2+2^3+2^4 + ... + 2^(n-1) = 2^n - 1
//时间复杂度为2^n

//求出整个斐波那契数列
long long* Fibonacci(size_t N)
{
	long long* fibArray = malloc(sizeof(long long)*N);
	fibArray[1] = 0;
	if (N == 0)
	{
		return fibArray;
	}

	fibArray[2] = 1;
	//空间换时间
	for (int i = 2; i <= N; i++)
	{
		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
	}
	return fibArray;
}


//空间复杂度
//空间复杂度是对一个算法在运行过程中临时占用存储空间大小的变量.空间复杂度不是程序占用了多少bytes的空间,因为这个也没有太大意义,所以空间复杂度算的是变量的个数.
//空间复杂度计算规则基本跟时间复杂度类似,也使用大O渐进表示法.


//计算BubbleSort的空间复杂度
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
//它定义的变量有:a,n,end,exchange,i五个变量
//所以他的空间复杂度为O(1),为常数个变量


//计算BinarySearch的空间复杂度
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
//空间复杂度为O(N)


//计算空间复杂度
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
//空间复杂度为O(N)