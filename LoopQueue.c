#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
 /**
  *	循环队列
  * 数组实现方式
  *
  * 
  */

typedef struct Queue
{
	int * pBase;
	int front;
	int rear;	
}QUEUE;

void init(QUEUE *);
bool en_queue(QUEUE *, int val);
void traverse_queue(QUEUE *);
bool full_queue(QUEUE *);
bool out_queue(QUEUE*, int *);
bool empty_queue(QUEUE *);

int main(int argc, char const *argv[])
{
	QUEUE Q;
	int val;

	init(&Q);
	en_queue(&Q, 1);
	en_queue(&Q, 2);
	en_queue(&Q, 3);
	en_queue(&Q, 4);
	en_queue(&Q, 5);
	en_queue(&Q, 6);
	en_queue(&Q, 7);
	en_queue(&Q, 8);
	traverse_queue(&Q);

	if (out_queue(&Q, &val))
	{
		printf("出队成功，队列出队的元素是：%d\n", val);
	}
    else
    {
    	printf("出队失败\n");
    }
    traverse_queue(&Q);

    if (out_queue(&Q, &val))
	{
		printf("出队成功，队列出队的元素是：%d\n", val);
	}
    else
    {
    	printf("出队失败\n");
    }
    traverse_queue(&Q);

	return 0;
}

/**
 * 初始化队列
 * @param pQ 队列指针
 */
void init(QUEUE * pQ)
{
	pQ->pBase = (int *)malloc(sizeof(int) * 6);
	pQ->front = 0;
	pQ->rear = 0;
}

/**
 * 判断队列是否已满
 * @param  pQ 队列指针
 * @return    真或假
 */
bool full_queue(QUEUE * pQ)
{
	if ((pQ->rear + 1) % 6 == pQ->front) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * 入队操作
 * @param  pQ  队列指针
 * @param  val 队列元素的值
 * @return     真或假
 */
bool en_queue(QUEUE * pQ, int val)
{
	if (full_queue(pQ))
	{
		return false;
	}
	else
	{
		pQ->pBase[pQ->rear] = val;
		pQ->rear = (pQ->rear+1) % 6;
		return true;
	}
}

/**
 * 遍历数组元素
 * @param pQ 队列指针
 */
void traverse_queue(QUEUE * pQ)
{
	int i = pQ->front;

	while (i != pQ->rear) 
	{
	    printf("%d ", pQ->pBase[i]);
	    i = (i+1) % 6;
	}

	printf("\n");

	return;
}

/**
 * 判断队列是否为空
 * @param  pQ 队列指针
 * @return    真或假
 */
bool empty_queue(QUEUE * pQ)
{
	if (pQ->front == pQ->rear)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * 出队操作
 * @param  pQ   队列指针
 * @param  pVal 元素的指针
 * @return      真或假
 */
bool out_queue(QUEUE * pQ, int * pVal)
{
	if (empty_queue(pQ))
	{
		return false;
	}
	else
	{
		*pVal = pQ->pBase[pQ->front];
		pQ->front = (pQ->front + 1) % 6;
		return true;
	}
}
