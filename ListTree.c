/**
 * 链式二叉树
 */

#include <stdio.h>
#include <stdlib.h>

struct BTNode
{
	char data;
	struct BTNode * pLchild; // p是指针，L是左, child是孩子
	struct BTNode * pRchild;
};

struct BTNode * createBTree(void);
void preTraverseBTree(struct BTNode * pT);
void inTraverseBTree(struct BTNode * pT);
void poTraverseBTree(struct BTNode * pT);

int main(int argc, char const *argv[])
{
	struct BTNode * pT = createBTree();

	printf("%s", "先序遍历结果：");
	preTraverseBTree(pT);
	printf("\n");

	printf("%s", "中序遍历结果：");
	inTraverseBTree(pT);
	printf("\n");

	printf("%s", "后序遍历结果：");
	poTraverseBTree(pT);
	printf("\n");

	return 0;
}

struct BTNode * createBTree(void)
{
	struct BTNode * pA = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pB = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pC = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pD = (struct BTNode *)malloc(sizeof(struct BTNode));
	struct BTNode * pE = (struct BTNode *)malloc(sizeof(struct BTNode));

	pA->data = 'A';
	pB->data = 'B';
	pC->data = 'C';
	pD->data = 'D';
	pE->data = 'E';

	pA->pLchild = pB;
	pA->pRchild = pC;
	pB->pLchild = pB->pRchild = NULL;
	pC->pLchild = pD;
	pC->pRchild = NULL;
	pD->pLchild = NULL;
	pD->pRchild = pE;
	pE->pLchild = pE->pRchild = NULL;

	return pA;
}

/**
 * 先序遍历二叉树
 * @param pT [description]
 */
void preTraverseBTree(struct BTNode * pT)
{	
	if (NULL != pT)
	{
		printf("%c ", pT->data); // 先访问根节点
		if (NULL != pT->pLchild)
		{
			preTraverseBTree(pT->pLchild);
		}
		
		if (NULL != pT->pRchild)
		{
			preTraverseBTree(pT->pRchild);
		}

	// pT->pLchild; // 可以代表整个左子树
	}
	
}

void inTraverseBTree(struct BTNode * pT)
{	
	if (NULL != pT)
	{

		if (NULL != pT->pLchild)
		{
			inTraverseBTree(pT->pLchild);
		}
		
		printf("%c ", pT->data); // 中间访问根节点

		if (NULL != pT->pRchild)
		{
			inTraverseBTree(pT->pRchild);
		}

	// pT->pLchild; // 可以代表整个左子树
	}
	
}

/**
 * 后序遍历二叉树
 * @param pT [description]
 */
void poTraverseBTree(struct BTNode * pT)
{	
	if (NULL != pT)
	{
		
		if (NULL != pT->pLchild)
		{
			poTraverseBTree(pT->pLchild);
		}
		
		if (NULL != pT->pRchild)
		{
			poTraverseBTree(pT->pRchild);
		}

		printf("%c ", pT->data); // 最后访问根节点

	// pT->pLchild; // 可以代表整个左子树
	}
	
}






