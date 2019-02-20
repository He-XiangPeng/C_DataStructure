/**
 *	数组的复习
 *
 * 
 */

#include <stdio.h>
void show_Array(int * p, int len);
int main(void)
{
	int a[5] = {1, 2, 3, 4, 5};
	show_Array(a, 5);

	printf("%p\n", a + 1);
	printf("%p\n", a + 2);
	printf("%d\n", *a + 3); // 等价于a[0]+3

	return 0;
}

/**
 * 输出数组元素
 * @param p   数组名
 * @param len 数组长度
 */
void show_Array(int * p, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", p[i]);
	}
	
	printf("\n");
}