#include <stdio.h>
#include <stdlib.h>
/*
	跨函数使用内存
	动态分配内存
	数据结构 = 个体的存储 + 个体的关系存储
	算法 = 对存储数据的操作
 */
struct Student
{
	int sid;
	int age;
};

struct Student * createStudent(void);
void showStudent(struct Student * pst);

int main(int argc, char const *argv[])
{
	struct Student * ps;
	ps = createStudent();
	showStudent(ps);

	ps = NULL;
	free(ps);
	return 0;
}

void showStudent(struct Student * pst)
{
	printf("%d %d\n", pst->sid, pst->age);
}

struct Student * createStudent(void)
{
	struct Student * p = (struct Student *)malloc(sizeof(struct Student));
	p->sid = 99;
	p->age = 88;
	return p;
}