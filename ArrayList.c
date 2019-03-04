/**
 *	ArrayList的创建
 *
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct Arr
{
	int * pBase; // 存储的是数组的第一个元素的地址
	int len; // 数组所能容纳的最大元素的个数
	int cnt; // 当前数组有效元素的个数
};

void init_arr(struct Arr * pArr, int length);
bool append_arr(struct Arr * pArr, int val); // 追加
bool insert_arr(struct Arr * pArr, int pos, int val);
bool delete_arr(struct Arr * pArr, int pos, int * pVal);
int  get(struct Arr * pArr, int pos);
bool is_empty(struct Arr * pArr);
bool is_full(struct Arr * pArr);
void sort_arr(struct Arr * pArr);
void show_arr(struct Arr * pArr);
void inversion_arr(struct Arr * pArr);


int main(void)
{
	struct Arr arr; // 结构体arr
	int val; // 数组元素val
	int pos_Val; // pos位置处的元素

	init_arr(&arr, 6);
	printf("初始后的数组:");
	show_arr(&arr);
	
	append_arr(&arr, 1); // 向数组后面添加
	append_arr(&arr, -4);
	append_arr(&arr, 88);
	append_arr(&arr, 98);
	append_arr(&arr, 4);
	printf("尾部添加后的数组：");
	show_arr(&arr);
	

	insert_arr(&arr, 2, 99);
	printf("插入元素后的数组：");
	show_arr(&arr);

	if (delete_arr(&arr, 1, &val))
	{
		printf("删除成功\n");
		printf("删除的元素是：%d\n", val);
	}
	else
	{
		printf("删除失败\n");
	}
	printf("删除元素后的数组是：");
	show_arr(&arr);

	inversion_arr(&arr);
	printf("转置后的数组是：");
	show_arr(&arr);

	sort_arr(&arr);
	printf("冒泡排序后的数组是：");
	show_arr(&arr);

	pos_Val = get(&arr, 3);
	printf("pos位置处的元素是：%d\n", pos_Val);

	

	return 0;
}

/**
 * 初始化数组
 * @param pArr 结构指针  
 * @param length 数组所能容纳的最大元素的个数
 */
void init_arr(struct Arr * pArr, int length)
{
	pArr->pBase = (int *)malloc(sizeof(int) * length);
	if (NULL == pArr->pBase)
	{
		printf("动态内存分配失败\n");
		exit(-1);
	}
	else
	{
		pArr->len = length;
		pArr->cnt = 0;
	}

	return;
}

/**
 * 往尾部追加
 * @param  pArr 结构指针
 * @param  val  将要插入的元素
 * @return      真或假
 */
bool append_arr(struct Arr * pArr, int val)
{
	// 满时返回false
	if (is_full(pArr)) 
	{
		return false;
	}
	else // 不满时追加
	{
		pArr->pBase[pArr->cnt] = val;
		(pArr->cnt)++;
		return true;
	}
}

/**
 * 向pos位置处插入元素val
 * @param  pArr 结构指针
 * @param  pos  将要插入元素的位置
 * @param  val  将要插入的元素
 * @return      真或假
 */
bool insert_arr(struct Arr * pArr, int pos, int val)
{
	if (is_full(pArr))
	{
		return false;
	}

	if (pos<1 || pos>pArr->cnt+1)
	{
		return false;
	}

	for (int i = pArr->cnt-1; i >= pos-1; --i)
	{
		pArr->pBase[i+1] = pArr->pBase[i];
	}
	pArr->pBase[pos-1] = val;
	pArr->cnt++;

    // 1 , -4, 88 , 98 , 4 >>>> 1, 99, -4, 88, 98, 4
    // cnt=5, pos=2, pBase[1]=99
    // cnt=6
	return true;
}

/**
 * 删除pos位置处的元素val
 * @param  pArr 结构指针
 * @param  pos  将要插入元素的位置
 * @param  pVal 数组元素的指针
 * @return      真或假
 */
bool delete_arr(struct Arr * pArr, int pos, int * pVal)
{
	if (is_empty(pArr))
	{
		return false;
	}

	if (pos<1 || pos>pArr->cnt)
	{
		return false;
	}

	*pVal = pArr->pBase[pos-1]; // val = pArr->pBase[pos-1]
	for (int i = pos; i < pArr->cnt; ++i)
	{
		pArr->pBase[i-1] = pArr->pBase[i];
	}
	pArr->cnt--;
	return true;

	// 1, 99, -4, 88, 98, 4
	// pos=1
	
}


/**
 * 数组是否为空
 * @param  pArr 结构指针
 * @return      真或假
 */
bool is_empty(struct Arr * pArr)
{
	if (pArr->cnt == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * 数组是否已满
 * @param  pArr 结构指针
 * @return      真或假
 */
bool is_full(struct Arr * pArr)
{
	if (pArr->cnt == pArr->len) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

/**
 * 显示数组的元素
 * @param pArr 结构指针
 */
void show_arr(struct Arr * pArr)
{
	if (is_empty(pArr)) 
	{
		printf("数组为空！\n");
	}
	else 
	{
		for (int i = 0; i < pArr->cnt; ++i)
		{
			printf("%d ", pArr->pBase[i]);
		}
		printf("\n");
	}
}

/**
 * 转置数组元素
 * @param pArr 结构指针
 */
void inversion_arr(struct Arr * pArr)
{
	int i = 0;
	int j = pArr->cnt-1;
	int t;

	while(i < j) 
	{
	    t = pArr->pBase[i];
	    pArr->pBase[i] = pArr->pBase[j];
	    pArr->pBase[j] = t;
	    ++i;
	    --j;
	}

}

/**
 * 升序排列数组元素(冒泡排序)
 * @param pArr 结构指针
 */
void sort_arr(struct Arr * pArr)
{
	int t;
	for (int i = 0; i < pArr->cnt; ++i)
	{
		for (int j = i + 1; j < pArr->cnt; ++j)
		{
			if (pArr->pBase[i] > pArr->pBase[j])
			{
			    t = pArr->pBase[i];
	    		pArr->pBase[i] = pArr->pBase[j];
	    		pArr->pBase[j] = t;
			}
		}
	}
}

/**
 * 获取pos位置处的元素
 * @param  pArr 结构体指针
 * @param  pos  数组元素的位置
 * @return      pos位置处的元素
 */
int get(struct Arr * pArr, int pos)
{
	if (pos<1 || pos>pArr->cnt+1)
	{
		return -1;
		printf("该位置不存在\n");
	}
	else
	{
		return pArr->pBase[pos-1];
	}
}





