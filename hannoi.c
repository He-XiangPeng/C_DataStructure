#include <stdio.h>
/**
 *	汉诺塔
 *
 * 
 */

void hannoi(int, char, char, char);

int main(int argc, char const *argv[])
{
	char ch1 = 'A';
	char ch2 = 'B';
	char ch3 = 'C';
	int n;

	printf("请输入要移动的盘子的个数：");
	scanf("%d", &n);

	hannoi(n, 'A', 'B', 'C');
	return 0;
}

void hannoi(int n, char A, char B, char C)
{
	if (1 == n)
	{
		printf("将编号为%d的盘子直接从%c柱子移到%c柱子\n", n, A, C);
	}
	else
	{
		hannoi(n-1, A, C, B);
		printf("将编号为%d的盘子从%c柱子移到%c柱子\n", n, A, C);
		hannoi(n-1, B, A, C);
	}
}