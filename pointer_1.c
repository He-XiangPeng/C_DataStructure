/**
 *	指针复习程序
 *
 * 
 */
#include <stdio.h>
int main(void)
{
	int * p;
	int i = 10;
	int j;

	p = &i;
	j = *p = 25;
	printf("i = %+d\n", i); // %+d输出int型的符号
	return 0;
}