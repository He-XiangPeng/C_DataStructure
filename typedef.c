#include <stdio.h>

typedef int ZHANGSAN;
// 为int再重新夺取一个名字，
// zhangsan等价于int
/*typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}ST;*/

typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}* PST;
// PST等价于struct Student *

/*typedef struct Student
{
	int sid;
	char name[100];
	char sex;
}* PSTU, STU;*/
// 等价于struct Student * PSTU, struct Student STU

int main(void)
{
	int i = 10;
	// 等价于ZHANGSAN i = 10;
	ZHANGSAN j = 20;
	printf("%d\n", j);

	// struct Student st;
	// struct Student * ps = &st; // 等价于ST * ps = &st
	struct Student st;
	PST ps = &st;
	ps->sid = 10;
	printf("%d\n", ps->sid);


	return 0;
}