/**
 *	创建一个非循环单链表
 *
 *
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
	int data;  // 数据域
	struct Node * pNext; // 指针域
}NODE, * PNODE;

PNODE create_list(void);
void traverse_list(PNODE pHead);
bool is_empty(PNODE pHead);
int length_list(PNODE pHead);
bool insert_list(PNODE,int, int);
bool delete_list(PNODE, int, int *);
void sort_list(PNODE pHead);

int main(void)
{
	int val;
	PNODE pHead = NULL; // struct Node * pHead = NULL;
	pHead = create_list();
	traverse_list(pHead);

	// insert_list(pHead, 4, 33);
	// traverse_list(pHead);

	if (delete_list(pHead, 4, &val))
	{
		printf("删除成功!删除的元素的：%d\n", val);
	}
	else
	{
		printf("删除失败\n");
	}
	traverse_list(pHead);

	// int len = length_list(pHead);
	// printf("链表的长度是%d\n", len);
	
	// sort_list(pHead);
	// traverse_list(pHead);
/*
	if (is_empty(pHead)) 
	{
		printf("链表为空！\n");
	}
	else 
	{
		printf("链表非空！\n");
	}*/
	return 0;
}

/**
 * 创建一个非循环单链表
 * @return  链表的头结点
 */
PNODE create_list(void)
{
	int len; // 用来存放有效节点的个数
	int val; // 用来临时存放用户输入的结点的值

	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (NULL == pHead)
	{
		printf("分配失败，程序终止！\n");
		exit(-1);
	}
	PNODE pTail = pHead;
	pTail->pNext = NULL;

	printf("请输入您需要生成的链表的个数：len = ");
	scanf("%d", &len);

	for (int i = 0; i < len; ++i)
	{
		printf("请输入第%d个节点的值:", i+1);
		scanf("%d", &val);

		PNODE pNew = (PNODE)malloc(sizeof(NODE));
		if (NULL == pNew)
		{
			printf("分配失败，程序终止！\n");
			exit(-1);
		}
		pNew->data = val;
		pTail->pNext = pNew;
		pNew->pNext = NULL;
		pTail = pNew;
	}

	return pHead;
}

/**
 * 遍历链表
 * @param pHead 头结点
 */
void traverse_list(PNODE pHead)
{
	PNODE p = pHead->pNext;// 至少有一个节点，即头结点
	printf("L→ ");
	while (NULL != p) 
	{
	    printf("%d→ ", p->data);
	    p = p->pNext;
	}
	printf("NULL\n");
}

/**
 * 链表是否为空
 * @param  pHead 头结点
 * @return       bool
 */
bool is_empty(PNODE pHead)
{
	if (pHead->pNext == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * 链表的长度
 * @param  pHead 头结点
 * @return       长度
 */
int length_list(PNODE pHead)
{
	PNODE p = pHead->pNext;
	int len = 0;
	while (p != NULL) 
	{
		++len;
		p = p->pNext;
	}

	return len;
}

/**
 * 冒泡排序
 * @param pHead 头结点
 */
void sort_list(PNODE pHead)
{
	int i, j, t;
	int len = length_list(pHead);
	PNODE p, q;
	for (i = 0, p=pHead->pNext; i < len -1; ++i, p=p->pNext)
	{
		for (j = i+1, q=p->pNext; j < len; ++j, q=q->pNext)
		{
			if (p->data > q->data)
			{
				t = p->data;
				p->data = q->data;
				q->data = t;
			}
		}
	}

	return;
}

/**
 * 插入
 * @param  pHead [description]
 * @param  pos   位置从1开始
 * @param  val   [description]
 * @return       [description]
 */
bool insert_list(PNODE pHead, int pos, int val)
{
	int i = 0;
	PNODE p = pHead;

	while (NULL != p->pNext && i<pos-1) 
	{
	    p = p->pNext;
	    ++i;
	}

	if (i>pos-1 || NULL == p)
	{
		return false;
	}

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (NULL == pNew)
	{
		printf("动态分配内存失败！\n");
		exit(-1);
	}
	pNew->data = val;
	PNODE q = p->pNext;
	p->pNext = pNew;
	pNew->pNext = q;

	return true;
}

bool delete_list(PNODE pHead, int pos, int * pVal)
{
	int i = 0;
	PNODE p = pHead;

	while (NULL !=  p->pNext && i<pos-1) 
	{
	    p = p->pNext;
	    ++i;
	}

	if (i>pos-1 || NULL == p)
	{
		return false;
	}

	PNODE q = p->pNext;
	*pVal = q->data;

	// 删除p节点后面的结点
	p->pNext = p->pNext->pNext;
	free(q);
	q = NULL;

	return true;
}


