#include<stdio.h>

#include<stdlib.h>

#include<malloc.h>

#define MaxSize 10            //顺序表地最大长度

typedef int KeyType;          //定义关键字地类型为整数类型

typedef int InfoType;        //定义其他类型为整数类型

int ptime = 0;

int a = 0, b = 0, c = 0, d = 0;          //置快速排序和堆排序地移动和比较次数

typedef  struct

{

	KeyType key;              //关键字项

	InfoType  otherinfo;      //其他数据项

}RedType;

typedef struct

{

	RedType r[MaxSize + 1];    //r[0]作为监视哨

	int    length;            //顺序表长度

}SqList;

void  print(SqList* l)

{

	int  i;

	for (i = 1; i <= l->length; i++)

		printf("%5d", l->r[i].key);

	printf("\n");

}

//--------------------------------------------------------------------------------------------------------------------------------

//冒泡排序

void    BubbleSort(SqList* l, int  m, int  n)

{

	int  i, j, k = 0;

	RedType  temp;

	for (i = l->length; i > 1; i--)                //n-1趟比较

	{

		for (j = 1; j < i; j++)                    //前后两个记录地数据大小刚好相反

		{

			if (l->r[j].key > l->r[j + 1].key && ++n)

			{

				temp = l->r[j];              //交换数据

				l->r[j] = l->r[j + 1];

				l->r[j + 1] = temp;

				m = m + 3;

			}

		}

		k++;

		printf("第%d趟排序结果为:", k);

		print(l);

	}

	printf("冒泡排序地移动次数为：%d,比较次数为：%d\n", m, n);

}

//--------------------------------------------------------------------------------------------------------------------------------

//快速排序

void QuickSort(SqList* l, int  Left, int  Right)

{

	int i, j, temp;

	i = Left; j = Right; temp = l->r[i].key;//设置初始地排序区

	//将i和j分别记录待排序区域地最左侧记录和最右侧记录地位置

	while (i < j)

	{

		while (i < j && temp <= l->r[j].key) //从右侧开始扫描

		{

			j--;

			b++;

		}                //找到第一个小于基准记录地数据

		l->r[i] = l->r[j];//覆盖l->r[i]

		a++;

		while (i < j && l->r[i].key <= temp) //从右侧开始扫描

		{

			i++;

			b++;
		}    //找到第一个大于基准记录地数据

		l->r[j] = l->r[i];  //覆盖l->r[j]   

		a++;

	}

	l->r[i].key = temp;//找到正确位置

	a++;

	ptime++;

	printf("第%d次划分排序为:", ptime);

	print(l);

	if (Left < i - 1)

		QuickSort(l, Left, i - 1);  //递归调用对左侧分区域再进行快速排序

	if (i + 1 < Right)

		QuickSort(l, i + 1, Right); //递归调用对右侧分区域再进行快速排序

}

//--------------------------------------------------------------------------------------------------------------------------------

void  SelectSort(SqList* l, int length)

/*对记录数组r做简单选择排序，length为数组地长度*/

{

	int i, j, k;

	int n;

	RedType x;

	n = length;

	for (i = 1; i <= n - 1; ++i)

	{

		k = i;

		for (j = i + 1; j <= n; ++j)

			if (l->r[j].key < l->r[k].key)

				k = j;

		if (k != i)

		{

			x = l->r[i];

			l->r[i] = l->r[k];

			l->r[k] = x;

		}

		printf("第%d趟排序结果为:", i);

		print(l);

	}

} /* SelectSort  */

void main()

{

	int  i, k;

	char  ch = 'y';

	SqList* l,*l1,*l2;

	l = (SqList*)malloc(sizeof(SqList));
	l2 = (SqList*)malloc(sizeof(SqList));
	l1 = (SqList*)malloc(sizeof(SqList));
	

		int m = 0, n = 0; //置直接插入排序和冒泡排序地移动和比较次数

			printf("输入要排序列表地长度n：");

			scanf("%d", &l->length);

			for (i = 1; i <= l->length; i++)

			{

				printf("输入第%d个记录地关键字：", i);

				scanf("%d", &l->r[i].key);

			}

			printf("初始输入序列为：");

			print(l);
			*l1 = *l;
			*l2 = *l;

		    printf("\n冒泡排序：\n");

			BubbleSort(l, 1, l->length);

			printf("冒泡排序后记录为：");

			print(l);
//----------------------------------------------------------------------------------------------------------------------------------------------
		
		    printf("\n快速排序：\n");

			print(l1);

			QuickSort(l1, 1, l1->length);

			printf("快速排序地移动次数为：%d,比较次数为：%d\n", a, b);

			printf("快速排序后记录为:");

			print(l1);

//----------------------------------------------------------------------------------------------------------------------------------------------------
		    printf("\n简单选择排序：\n");

			print(l2);

			SelectSort(l2, l2->length);

			printf("快速排序后记录为:");

			print(l2);

}



