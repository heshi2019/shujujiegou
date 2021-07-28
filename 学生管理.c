#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NULL 0
int n = 1;
int n1, n2;

struct geizi                                                                                           //创建结构体
{
	char name[10];
	int num;
	int age;
	int yuwen;
	int shuxue;
	int waiyu;
	struct geizi* next;
};

struct geizi* tou()                                                                                     //创建头节点
{
	struct geizi* list = (struct geizi*)malloc(sizeof(struct geizi));                                      //给头节点创建空间
	list->next = NULL;                                                                                  //为这个节点指针域赋值
	return list;
}

void charu(struct geizi* list, char* newname, int newnum, int newage, int newyuwen, int newshuxue, int newwaiyu)
{                                                                                                         //插入数据函数     
	struct geizi* day, *p;
	day = (struct geizi*)malloc(sizeof(struct geizi));
	strcpy(day->name, newname);                                                                         //把信息放到结点中
	day->age = newage;
	day->num = newnum;
	day->yuwen = newyuwen;
	day->shuxue = newshuxue;
	day->waiyu = newwaiyu;
	day->next = NULL;
	p = list;                                                                            //赋值用来找尾节点
	while (p->next != NULL)                                                                           //寻找
	{
		p = p->next;
	}
	p->next = day;	                                                                          //找到后连接节点   
}

void shanchu(struct geizi* list, int num)                                                               //删除函数
{
	struct geizi* t = list;                                                                           //头节点
	struct geizi* p = list->next;                                                                        //首节点
	while (p && p->num != num)                                                                               //查找输入学号对应的节点
	{
		t = t->next;
		p = p->next;
	}

	if (p) {
		t->next = p->next;                                                                               //防止断链，上一个节点链接下一个节点
		free(p);
		printf("删除成功！\n");
	}
	else printf("此信息不存在!\n");
}

void shuchu(struct geizi* list)                                                                            //输出函数
{
	int n = 1;
	int avg = 0;
	int he = 0;
	struct geizi* p = list->next;                                                                    //将首节点赋值给p
	if (p != NULL) {	                                                                                  //首次测试链表是否为空
		while (p != NULL) {    	                                                                       //连续输出条件 
			if (n == 1) {
				printf("姓名\t学号\t年龄\t语文\t数学\t外语\t平均分\t总分\n");
				n++;
			}
			else {
				avg = (p->yuwen + p->shuxue + p->waiyu) / 6;
				he = p->yuwen + p->shuxue + p->waiyu;
				printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n", p->name, p->num, p->age, p->yuwen, p->shuxue, p->waiyu, avg,he);
				p = p->next;
			}
		}
	}
	else
		printf("链表为空，请输入数据\n");
}

void select(struct geizi* list, int num, int n1) {
	struct geizi* p = list->next;
	n = 1;
	n2 = 0;
	int avg=0;
	int he = 0;
	if (n1 == 1) {
		while (p != NULL) {
			if (p->num == num) {
				if (n == 1) {
					printf("姓名\t学号\t年龄\t语文\t数学\t外语\t平均分\t总分\n");
					n++;

				}
				else {
					avg = (p->yuwen + p->shuxue + p->waiyu) / 3;
					he = p->yuwen + p->shuxue + p->waiyu;
					printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%d\t\n", p->name, p->num, p->age, p->yuwen, p->shuxue, p->waiyu, avg, he);
					p = p->next;
				}
			}
			else {
				p = p->next;
			}
		}
		if (n == 1)printf("表中没有此学生的信息\n");

	}
	else {
		
		while (p != NULL) {
			  if (p->num == num) {
				n2 = 1;
				p = p->next;
			  }
			  else {
				p = p->next;
			  }
			if (n2 == 0) {
				n2 = 2;
			}
		}
	}
}
	
void gai(struct geizi* list, int num) {
	struct geizi* p = list;
	struct geizi* p2 = p;
	int x3 = 0;
	int x2 = 0;
	int age, yuwen, shuxue, waiyu;
	select(list, num,2);
	if (n2 == 0) {                           //判断链表是否为空
		printf("链表为空，请输入数据\n");
	}
	else {
		select(list, num, 2);
		if (n2 == 1) {
          //调用select函数来判断表中是否有要修改的记录
				printf("请输入要修改的序号\n");
				printf("1,姓名  2,学号  3,年龄  4,语文  5,数学  6,外语\n");
				scanf("%d", &x2);
				while (p != NULL) {
				
					if (p->num == num) {               //在链表中定位需要修改的节点
						switch (x2) {
						case 1: {
							printf("请输入新的姓名：");
							scanf("%s", p->name);
							printf("修改成功！\n");
						}break;

						case 2: {
							printf("请输入新的学号：");
							scanf("%d", &x3);
							while (p2 != NULL) {
								
								if (p2->num == x3) {
									printf("学号已存在，请重新输入\n");
									
									return 0;
								}
								else {
									p2 = p2->next;
								}
							}
							p->num = x3;
							printf("\n");
							printf("修改成功！\n");
							printf("\n");
						}break;

						case 3: {
							printf("请输入新的年龄：");
							scanf("%d",&age);
							p->age = age;
							printf("修改成功！\n");
						}break;

						case 4: {
							printf("请输入新语文成绩：");
							scanf("%d",&yuwen);
							p->yuwen = yuwen;
							printf("修改成功！\n");
						}break;

						case 5: {
							printf("请输入新的数学成绩：");
							scanf("%d",&shuxue);
							p->shuxue = shuxue;
							printf("修改成功！\n");
						}break;

						case 6: {
							printf("请输入新的外语成绩：");
							scanf("%d",&waiyu);
							p->waiyu = waiyu;
							printf("修改成功！\n");
						}break;

						default: {
							printf("输入错误");
							return 0;
						 }
						}
						p = p->next;
					}
					else {
						p = p->next;
					}

				}
			
		}
		else {
			printf("表中没有此学生的信息\n");
		}
	}
}

void menu()                                                                                                //打印菜单
{
	printf("                             ****************************************\n");
	printf("                             *        1、插入学生信息                           *\n");
	printf("                             *        2、打印所有信息                           *\n");
	printf("                             *        3、删除学生信息                           *\n");
	printf("                             *        4、查找学生信息                           *\n");
	printf("                             *        5、修改学生信息                           *\n");
	printf("                             *        6、退出程序                               *\n");
	printf("                             ****************************************\n");
}

void zuhe(struct geizi* tzz)                                                                                //组合函数
{
	int a = 0;
	struct geizi* w = tzz;
	menu();
	printf("请选择菜单                  （请勿在输入姓名之外任何地方输入字母！！！！！）\n");
	scanf("%d", &a);

	while (a < 1 || a > 6)
	{
		printf("输入错误，请重新输入菜单选项\n");
		scanf("%d",&a);
	}

			switch (a) {
			case 1: {                                                                                         //调用插入函数
				char name[10] = "0";
				int num = 0;
				int age = 0;
				int yuwen = 0;
				int shuxue = 0;
				int waiyu = 0;
				printf("输入信息姓名，学号，年龄，语文，数学，外语\n");
				scanf("%s", name);
				scanf("%d", &num);
				scanf("%d", &age);
				scanf("%d", &yuwen);
				scanf("%d", &shuxue);
				scanf("%d", &waiyu);
				select(tzz, num, 2);
				if (n2 == 1) {
					printf("学号重复，请重新输入\n");
				}
				else {
					charu(tzz, name, num, age, yuwen, shuxue, waiyu);
				}
			}break;

			case 2: {                                                                                         //调用打印函数
				shuchu(tzz);
			}break;

			case 3: {                                                                                         //调用删除函数
				int xuehao = 0;
				printf("请输入你要删除的学生的学号\n");
				scanf("%d", &xuehao);
				shanchu(tzz, xuehao);
			}break;

			case 4: {
				int x1 = 0;
				printf("请输入要查询学生的学号\n");
				scanf("%d", &x1);
				select(tzz, x1, 1);
			}break;

			case 5: {
				int p1;
				printf("请输入要修改学生的学号\n");
				scanf("%d", &p1);
				gai(tzz, p1);
			}break;

			case 6: {
				exit(0);
			}break;

			}
	
}

int main()
{
	int p = 0;
	struct geizi* tzz = tou();
	while (1) {
		zuhe(tzz);
		system("pause");
		system("cls");
	}
	system("pause");
	return 0;
}



