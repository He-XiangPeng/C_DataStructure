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

void show_Array(int * p, int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", p[i]);
	}
	
	printf("\n");
}