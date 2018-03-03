#include <stdio.h>
/**
 *	阶乘的递归实现方法
 *
 * 
 */


long fun(long n)
{
	if (1 == n)
	{
		return 1;
	}
	else
	{
		return fun(n-1) * n;
	}
}

int main(void)
{
	printf("%ld\n", fun(6));	

	return 0;
}