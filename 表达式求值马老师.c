#include <stdio.h>
#include <stdlib.h>

char shi[20];
char a;
float b, d, x;
float num = 0;
//运算符栈
typedef struct OPTR {
	char* base;
	char* top;
	int stacksize;
}OPTR;

OPTR optr, optr2;
//操作数栈
typedef struct OPND {
	float* base;
	float* top;
	int stacksize;
}OPND;

OPND opnd;
//初始化运算符栈
void InitStackTR(OPTR* optr) {
	optr->base = (char*)malloc(12 * sizeof(char));
	optr->top = optr->base;
	optr->stacksize = 12;
}
//初始化操作数栈
void InitStackND(OPND* opnd) {
	opnd->base = (float*)malloc(12 * sizeof(float));
	opnd->top = opnd->base;
	opnd->stacksize = 12;
}
//运算符栈入栈
void PushTR(OPTR* optr, char a) {
	if (optr->top - optr->base >= optr->stacksize) {
		optr->base = (char*)realloc(optr->base, (optr->stacksize + 1) * sizeof(char));
		optr->top = optr->base + optr->stacksize;
		optr->stacksize++;
	}
	*optr->top = a;
	optr->top++;
}
//操作数栈入栈
void PushND(OPND* opnd, float a) {
	if (opnd->top - opnd->base >= opnd->stacksize) {
		opnd->base = (float*)realloc(opnd->base, (opnd->stacksize + 1) * sizeof(float));
		opnd->top = opnd->base + opnd->stacksize;
		opnd->stacksize++;
	}
	*opnd->top = a;
	opnd->top++;
}
//判断运算符栈是否为空
int StackEmptyTR(OPTR* optr) {
	if (optr->base == optr->top)
		return 1;
	else return 0;
}

//判断操作数栈是否为空
int StackEmptyND(OPND* opnd) {
	if (opnd->base == opnd->top)
		return 1;
	else return 0;
}
//运算符栈出栈
int PopTR(OPTR* optr, char* a) {
	if (StackEmptyTR(optr))
		return 0;
	optr->top--;
	*a = *optr->top;
}

//操作数栈出栈
int PopND(OPND* opnd, float* b) {
	if (StackEmptyND(opnd))
		return 0;
	opnd->top--;
	*b = *opnd->top;
}
//获取运算符栈顶元素
char GetTopTR(OPTR* optr) {
	return *(optr->top - 1);
}
//获取操作数栈顶元素
float GetTopND(OPND* opnd) {
	return *(opnd->top - 1);
}

//运算符优先级比较
int compare(char x, char y) {
	if (x == '+' || x == '-') {
		switch (y) {
		case '+': return 1; break;
		case '-':  return 1; break;
		case '*':  return -1; break;
		case '/':  return -1; break;
		case '(':  return -1; break;
		case ')':  return 1; break;
		case '#':  return 1; break;
		}
	}
	if (x == '*' || x == '/') {
		switch (y) {
		case '+': return 1; break;
		case '-':  return 1; break;
		case '*':  return 1; break;
		case '/':  return 1; break;
		case '(':  return -1; break;
		case ')':  return 1; break;
		case '#':  return 1; break;
		}
	}
	if (x == '(') {
		switch (y) {
		case '+': return -1; break;
		case '-':  return -1; break;
		case '*':  return -1; break;
		case '/':  return -1; break;
		case '(':  return -1; break;
		case ')':  return 0; break;
		}
	}
	if (x == ')') {
		switch (y) {
		case '+': return 1; break;
		case '-':  return 1; break;
		case '*':  return 1; break;
		case '/':  return 1; break;
		case ')':  return 1; break;
		case '#':  return 1; break;
		}
	}
	if (x == '#') {
		switch (y) {
		case '+': return -1; break;
		case '-':  return -1; break;
		case '*':  return -1; break;
		case '/':  return -1; break;
		case '(':  return -1; break;
		case '#':  return 0; break;
		}
	}
}
//计算部分
float suan(char a, float b, float c) {
	switch (a) {
	case '+': return b + c;
	case '-': return b - c;
	case '*': return b * c;
	case '/': return b / c;
	}
}

//转后缀表达式
void hou(char shi[]) {
	printf("后缀表达式：");
	for (int i = 0; shi[i] != '\0'; i++) {
		//数字直接输出
		num = 0;
		while (shi[i] != '+' && shi[i] != '-' && shi[i] != '*' && shi[i] != '/' && shi[i] != '(' && shi[i] != ')' && shi[i] != '#') {
			num = num * 10 + shi[i] - '0';
			i++;
		}
		if (num != 0)
			printf("%.0f ", num);
		//左括号直接入栈
		if (shi[i] == '(') {
			PushTR(&optr2, shi[i]);
		}
		//遇到右括号依次出栈并输出，直到左括号
		if (shi[i] == ')') {
			while (GetTopTR(&optr2) != '(') {
				PopTR(&optr2, &a);
				if (a != '(') printf("%c ", a);
			}
			//左括号出栈但不输出
			PopTR(&optr2, &a);
		}
		//遇到运算符，如果栈空直接入栈，如果不空，与栈顶元素比较优先级
		if (shi[i] == '+' || shi[i] == '-' || shi[i] == '*' || shi[i] == '/' || shi[i] == '#') {
			if (StackEmptyTR(&optr2))
				PushTR(&optr2, shi[i]);
			else {
				while (compare(GetTopTR(&optr2), shi[i]) == 1 || compare(GetTopTR(&optr2), shi[i]) == 0) {
					PopTR(&optr2, &a);
					printf("%c ", a);
				}
				PushTR(&optr2, shi[i]);
			}
		}
	}
}
void main() {

	int i = 0;
	InitStackTR(&optr);
	InitStackTR(&optr2);
	PushTR(&optr, '#');
	InitStackND(&opnd);
	printf("请输入表达式以#结束：");
	gets(shi);
	hou(shi);

	while (GetTopTR(&optr) != '#' || shi[i] != '#') {
		num = 0;
		while (shi[i] - '0' >= 0 && shi[i] - '0' <= 9) {
			num = num * 10 + shi[i] - '0';
			i++;
		}
		if (num != 0)
			PushND(&opnd, num);
		if (!(shi[i] - '0' >= 0 && shi[i] - '0' <= 9)) {
			switch (compare(GetTopTR(&optr), shi[i])) {
			case -1: PushTR(&optr, shi[i]); i++; break;
			case 0:  PopTR(&optr, &a); i++; break;
			case 1:  PopTR(&optr, &a); PopND(&opnd, &b); PopND(&opnd, &d); PushND(&opnd, suan(a, d, b)); break;
			}
		}
	}
	printf("\n运算结果：%.2f\n", GetTopND(&opnd));
}




