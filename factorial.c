#include <stdio.h>
/**
 *	阶乘的循环实现方法
 *
 * 
 */


int main(int argc, char const *argv[])
{
	int val;
	int i, mult=1;

	printf("请输入一个数字：\n");
	printf("val = ");
	scanf("%d", &val);

	for (i = 1; i <= val; ++i)
	{
		mult *= i;
	}

	printf("%d\n", mult);
	return 0;
}