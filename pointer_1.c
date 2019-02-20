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
	p = &i;
	*p = 25;
	printf("i = %d\n", i);
	return 0;
}