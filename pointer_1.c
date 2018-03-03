#include <stdio.h>

int main(void)
{
	int * p;
	int i = 10;
	p = &i;
	printf("%d\n", i);
	return 0;
}