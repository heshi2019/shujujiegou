#include<stdio.h>
#include<string.h>
#include<malloc.h>
int a=3;                                        //循环终止条件变量
int shuzu[3][3];                              //定义存储数组
int i, l,i1,hang,lie;                              //定义循环控制变量，行max与列min
int hangshu, lieshu;                  //存储最大数位置
int x=1;
int a1, a2;

void shuru() {

	/*                      数组必须指定第二维，所以直接指定阶数，不用输入
	printf("输入行列式的阶数");
	scanf("%d", &a);
	*/
	printf("输入一个3阶矩阵\n");
	for (i = 0; i < a; i++) {             //用for循环输入数组
		printf("输入第%d行\n", i + 1);
		for (l = 0; l < a;l++) {
			scanf("%d",&shuzu[i][l]);
		}
	}
}

void shucu() {
	printf("\n矩阵为\n");                             //输出矩阵
	for (i = 0; i < a; i++) {
		for (l = 0; l < a; l++) {
			
			printf("%d\t",shuzu[i][l]);
		}
		printf("\n\n");
	}
}
 //寻找行最大值函数
void hangmax(int a1) {
	hang = shuzu[a1][0];                          
	lieshu = 0;

	for (i = 1; i < a;i++) {
	
			if (shuzu[a1][i] > hang) {                 //对比，如有比第一个大的则赋值并存储下标
				hang = shuzu[a1][i];
				lieshu = i;                           //lieshu为全局变量
			}
		
	}
	/*
	if(hang==shuzu[a1][0]){
		l = 0;
	}
	*/
	printf("第%d行中最大的数为%d\n",a1+1,hang);
}
//列最小值函数
void liemin(int a2) {
	lie = shuzu[0][a2];

	for(i = 1; i < a; i++) {
	
			if (shuzu[i][a2] < lie) {                 //对比赋值
				lie = shuzu[i][a2];
				hangshu = i;
			}
		
	}
	/*
	if(lie==shuzu[0][a2]){
		l = 0;
	}
	*/
	printf("第%d列中最小的数为%d\n\n",a2+1,lie);
}

void andian() {
	for (i1 = 0; i1 < a;i1++) {                           //循环寻找每一行中最大的数
		hangmax(i1);                                      //调用后在用次行最大数的下标去找这个数所在列的最小数
		liemin(lieshu);
		if (hang == lie) {                                //如这两数相等则找到鞍点
			printf("鞍点为%d\n",lie);
			printf("行下标为%d  列下标为%d",hangshu+1,lieshu+1);
			x++;                                                      //表示符表示是否找到
			return 0;
		}
	}
	if (x == 1) {
		printf("矩阵中没有鞍点");
	}
}

void main() {
	shuru();                              //主函数调用
	shucu();
	andian();
}
