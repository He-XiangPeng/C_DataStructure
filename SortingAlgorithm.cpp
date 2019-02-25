/**
 *	排序算法c语言实现
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int * createArr(int);
void showArr(int *, int len);
void bubbleSort(int *, int);

int main(void)
{
	int * Array = createArr(8);
	showArr(Array, 8);
	bubbleSort(Array, 8);
	showArr(Array, 8);
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
 * 比如数组为31 9 12 24 len=4
 * i=0，j=1 -> 9 31 12 24
 * i=0，j=2 -> 9 31 12 24
 * i=0，j=3 -> 9 31 12 24
 * i=1，j=2 -> 9 12 31 24
 * i=1，j=3 -> 9 12 31 24
 * i=2，j=3 -> 9 12 24 31
 * i=3，j=4=len,内层循环终止
 * i=4=len,外层循环终止
 */
void bubbleSort(int * p, int len)
{
	int t;
	for (int i = 0; i < len; ++i)
	{
		for (int j = i + 1; j < len; ++j)
		{
			if (p[i] > p[j])
			{
				t = p[i];
				p[i] = p[j];
				p[j] = t;
			}
		}
	}
}
