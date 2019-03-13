/**
 *	排序算法c语言实现
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int * createArr(int len);
void showArr(int * p, int len);
void bubbleSort(int * p, int len);
void quickSort(int * p, int first, int last);
int FindPos(int * p, int first, int last);

int main(void)
{
	int * Array = createArr(8000);
	showArr(Array, 8000);
	// bubbleSort(Array, 8000);
	quickSort(Array, 0, 7999);
	showArr(Array, 8000);
	return 0;
}

int * createArr(int len)
{
	int * dynArr = (int *)malloc(len * sizeof(int));

	srand((unsigned)time(NULL));
	for (int i = 0; i < len; ++i)
	{
		dynArr[i] = (rand() % (32-1)) + 1;
	}
	return dynArr;
}

void showArr(int * p, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", *(p+i));
	}
	printf("\n");
}

/**
 * 冒泡排序
 * @param p   数组
 * @param len 数组长度
 * 另一种写法的实例分析：比如数组为31 9 12 24 len=4
 * i=0，j=1 -> 9 31 12 24
 * i=0，j=2 -> 9 31 12 24
 * i=0，j=3 -> 9 31 12 24
 * i=1，j=2 -> 9 12 31 24
 * i=1，j=3 -> 9 12 31 24
 * i=2，j=3 -> 9 12 24 31
 * 此时已排好序，所以i < len - 1即可
 */
void bubbleSort(int * p, int len)
{
	int t;
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (p[j] > p[j+1])
			{
				t = p[j];
				p[j] = p[j+1];
				p[j+1] = t;
			}
		}
	}
}

/**
 * 快速排序
 * @param p     数组名
 * @param First 第一个元素的下标
 * @param Last  最后一个元素的下标
 */
void quickSort(int * p, int first, int last)
{	
	int pos; // 位置
	if (first < last)
	{
		pos = FindPos(p, first, last);
		quickSort(p, first, pos-1);
		quickSort(p, pos+1, last);
	}
}

int FindPos(int * p, int first, int last)
{
	int val = p[first];
	while (first < last)
	{
		while (first < last && p[last] >= val)
			--last;
		p[first] = p[last];

		while (first < last && p[first] <= val)
			++first;
		p[last] = p[first];
	} // 终止while循环之后first和last一定是相等的
	p[first] = val;
	return last; // return first 也可以
}







