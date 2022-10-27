#include<iostream>
#include<math.h>
using namespace std;

typedef char ElemType;

//ջ�Ķ���
typedef struct
{
	ElemType* base;
	ElemType* top;
	//int stackSize;
}sqStack;

//ջ�ĳ�ʼ��
void InitStack(sqStack* s)
{
	s->base = new ElemType();
	if (s->base == NULL) {
		exit(0);
	}
	s->top = s->base;
	//s->stackSize = 0;
}

//ѹջ����
void push(sqStack* s, ElemType r)
{
	*s->top = r;
	s->top++;
}

//��ջ����
void pop(sqStack* s,ElemType*r) {
	if (s->base == s->top) {
		return;
	}
	*r = *--(s->top);
}

//��ջ��ǰ����
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
	cout << "������һ��������������#��β���������";
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
	cout << "ת��Ϊʮ����Ϊ��" << sum << endl;
}