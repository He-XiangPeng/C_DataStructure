/**
 *	栈操作
 *
 *
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
	int data;
	struct Node * pNext;
}NODE, * PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
}STACK, * PSTACK;

void init(PSTACK);
void push(PSTACK, int);
void traverse(PSTACK);
bool pop(PSTACK, int *);
void clear(PSTACK);

int main(void)
{
	STACK s;
	int val;

	init(&s);
	push(&s, 1);
	push(&s, 2);
	push(&s, 4);
	push(&s, 8);
	push(&s, 10);
	push(&s, 22);
	traverse(&s);

	clear(&s);

	if (pop(&s, &val))
	{
		printf("出栈成功，出栈元素是：%d\n", val);
	}
	else
	{
		printf("出栈失败！\n");
	}
	traverse(&s);



	return 0;
}

/**
 * 初始化栈
 * @param pS 栈
 */
void init(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));
	if (NULL == pS->pTop)
	{
		printf("内存分配失败！\n");
		exit(-1);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL;
	}

}

void push(PSTACK pS, int val)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = val;
	pNew->pNext = pS->pTop;
	pS->pTop = pNew;

	return;
}

/**
 * 遍历栈中的元素
 * @param pS 栈
 */
void traverse(PSTACK pS)
{
	PNODE p = pS->pTop;
	while (p != pS->pBottom) 
	{
	    printf("%d ->\n", p->data);
	    p = p->pNext;
	}

}

/**
 * 判断栈是否为空
 * @param  pS 形参栈名
 * @return    返回值
 */
bool empty(PSTACK pS)
{
	if (pS->pTop == pS->pBottom)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * 删除栈中的元素
 * @param  pS   栈
 * @param  pVal 指向元素的指针
 * @return      返回值
 */
bool pop(PSTACK pS, int * pVal)
{
	if (empty(pS))
	{
		return false;
	}
	else
	{
		PNODE r = pS->pTop;
		*pVal = r->data;
		pS->pTop = r->pNext;

		free(r);
		r = NULL;

		return true;
	}

}

/**
 * 清空栈内的元素
 * @param pS 栈
 */
void clear(PSTACK pS)
{
	if (empty(pS))
	{
		return;
	}
	else
	{
		PNODE p = pS->pTop;
		PNODE q = p->pNext;

		while (p != pS->pBottom) 
		{
		    q = p->pNext;
		    free(p);
		    p = q;
		}
		pS->pTop = pS->pBottom;
	}
}



