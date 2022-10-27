#include<iostream>
#include<math.h>
using namespace std;

typedef char ElemType;

//如果是2进制转8进制的话，就二进制栈top每三个数提取一次，赋值给一个新栈的base

//栈的定义
typedef struct
{
	ElemType* base;
	ElemType* top;
	//int stackSize;
}sqStack;

//栈的初始化
void InitStack(sqStack* s)
{
	s->base = new ElemType();
	if (s->base == NULL) {
		exit(0);
	}
	s->top = s->base;
	//s->stackSize = 0;
}

//压栈操作
void push(sqStack* s, ElemType r)
{
	*s->top = r;
	s->top++;
}

//弹栈操作
void pop(sqStack* s,ElemType*r) {
	if (s->base == s->top) {
		return;
	}
	*r = *--(s->top);
}

//求栈当前容量
int StackLen(sqStack s)
{
	return (s.top - s.base);
}

int main()
{
	ElemType c;
	sqStack s;
	InitStack(&s);
	int len, i, sum = 0;
	cout << "请输入一个二进制数，以#结尾代表结束：";
	scanf_s("%c", &c);
	while (c != '#') {
		push(&s, c);
		scanf_s("%c", &c);
	}
	getchar();
	len = StackLen(s);
	for (i = 0; i < len; i++) {
		pop(&s, &c);
		sum += (c-48) * pow(2, i);
	}
	cout << "转化为十进制为：" << sum << endl;
}
