#include<stdio.h>
#include<stdlib.h>
char a;
char srl[20];
float b=0;
float d = 0;
int a1;
int p = 0;


typedef struct {              //操作数栈
    int* top;
    int* base;
}QZL;

typedef struct {           //运算符栈
    char* top;
    char* base;
}APF;

QZL czs1;
APF ysf1;

void InitStackQZL(QZL* czs1) {                           //初始化操作数栈
    czs1->base = (int*)malloc(5000 * sizeof(int));
    czs1->top = czs1->base;
}

void InitStackAPF(APF* ysf1) {                           //初始化运算符栈
    ysf1->base = (char*)malloc(5000 * sizeof(char));
    ysf1->top = ysf1->base;
}

void pushQZL(QZL *czs1, int a1) {                                    //操作数入栈
    *czs1->top = a1;
    czs1->top++;
}

void pushAPF(APF *ysf1, char a) {                                     //运算符入栈
    *ysf1->top = a;
    ysf1->top++;
}

int popQZL(QZL *czs1,int *czs) {                                     //操作数出栈
    czs1->top--;
    *czs=*czs1->top;
}

char popAPF(APF *ysf1,char *ysf) {                                //运算符出栈
    ysf1->top--;
    *ysf=*ysf1->top;
}

int gettopQZL(QZL *czs1,int *czs) {                        //获取栈顶操作数
    *czs=*(czs1->top - 1);
}

int gettopAPF(APF *ysf1,char *ysf) {
    *ysf=*(ysf1->top - 1);
}

int pQZL(QZL *czs1) {                                     //判断操作数栈是否为空
    if (czs1->base == czs1->top) {
        return 1;
    }
    else {
        return 0;
    }
}

int pAPF(APF *ysf1) {                                     //判断运算符栈是否为空
    if (ysf1->base == ysf1->top) {
        return 1;
    }
    else {
        return 0;
    }
}

int youxianji(char x1, char x2) {                            //判断优先级函数
    if (x1 == '+' || x1 == '-') {             //x1为先进入运算符，x2为后进入运算符，先入大于后入，则返回1，否则返回-1，表达式错误返回1000，相等抵消则放回0
        switch (x2) {
        case'+':
        case'-':
        case')':
        case'#': return 1; break;
        case'*':
        case'/':
        case'(': return -1; break;
        }
    }
    if (x1 == '*' || x1 == '/') {
        switch (x2) {
        case'+':
        case'-':
        case'*':
        case'/':
        case')':
        case'#':return 1; break;
        case'(':return -1; break;
        }
    }
    if (x1 == '(') {
        switch (x2) {
        case'+':
        case'-':
        case'*':
        case'/':
        case'(':return -1; break;
        case')':return 0; break;
        case'#':return 1000; break;
        default:return 10;
        }
    }
    if (x1 == ')') {
        switch (x2) {
        case'+':
        case'-':
        case'*':
        case'/':
        case')':
        case'#':return 1; break;
        case'(':return 1000; break;
        default:return 10;
        }
    }
    if (x1 == '#') {
        switch (x2) {
        case'+':
        case'-':
        case'*':
        case'/':
        case'(':return -1; break;
        case'#':return 0; break;
        case')':return 1000; break;
        default:return 10;
        }
    }
}

void houzui(char srl[]) {         //输出后缀表达式
    int i = 0;
    int l;
    int shuzi;
    char yunsuanfu='0';
    char kh='0';

    ////////////////////////////////////////////////////////////////////////////////////////
    void tt(char yunsuanfu);
    printf("后缀表达式：");


    while(srl[i] != '\0') {                       //循环检测整个输入式子

        l = 0;                                               //用于在表达式中分离数字的变量

        while (srl[i] - 48 <= 9 && srl[i] - 48 >= 0) {
            l = l * 10 + srl[i] - 48;
            i++;                           //while和i++保证可以大于10以上的数能正常输出
        }
        if (l != 0) {
            printf("%d ",l);
            pushQZL(&czs1, l);                   //栈中压入数字
        }

        if (srl[i] == '(') {       //左括号入栈
            pushAPF(&ysf1, srl[i]);
            i++;
        }
        if (srl[i] == ')') {                            //如右括号入栈，则开始出栈-----------直至遇见左括号
            gettopAPF(&ysf1,&yunsuanfu);
            while (yunsuanfu != '(') {
                popAPF(&ysf1,&yunsuanfu);
                tt(yunsuanfu);
                printf(" %c", yunsuanfu);
          
                gettopAPF(&ysf1, &yunsuanfu);
            }
            popAPF(&ysf1,&kh);                           //左括号出栈
            i++;
        }
       
        if (srl[i] - 48 < 0 && srl[i] != '(' && srl[i] != ')') {                          //在ascrll码中所有的运算符的值都小于最小的数字的值
            gettopAPF(&ysf1, &yunsuanfu);
            if (youxianji(yunsuanfu, srl[i]) == 1) {
                popAPF(&ysf1, &yunsuanfu);
                tt(yunsuanfu);
                printf(" %c ", yunsuanfu);
            }
            else {
                if (youxianji(yunsuanfu, srl[i]) == -1) {
                    pushAPF(&ysf1, srl[i]);
                    i++;
                }
                else {
                    if (youxianji(yunsuanfu, srl[i]) == 0) {
                        printf("\n\n\n");
                        i++;
                    }
                    else {
                        printf("\n输入的表达式错误，请按规范输入");
                        system("pause");
                    }
                }
            }
        }
    }
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------
//用给出的运算符来从操作数栈中弹出两个数进行计算，再压入栈
void tt(char yunsuanfu) {
    int y1 = 0;
    int y2 = 0;

    int jieguo;
    char y3;
    y3 = yunsuanfu;

    popQZL(&czs1, &y1);
    popQZL(&czs1, &y2);

    jieguo = jisuan(y3, y2, y1);
    pushQZL(&czs1,jieguo);
}

int jisuan(char a, int b,int c) {
    switch (a) {
    case '+': return b+c;
    case '-': return b-c;
    case '*': return b*c;
    case '/': return b/c;
    }
}

void main() {
    int num = 0;
    InitStackAPF(&ysf1);
    InitStackQZL(&czs1);
    pushAPF(&ysf1, '#');


    printf("请输入表达式以#结束：");
    gets(srl);
    houzui(srl);
    printf("\n");

    gettopQZL(&czs1,&num);
    printf("\n运算结果：%d\n",num );
}

