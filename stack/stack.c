//数组实现栈
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct stack
{
int val[MAXSIZE];
int top;//top表示当前栈顶元素的数组下标
}stack;

void init(stack* p);//初始化
void push(stack* p,int val);//入栈
void pop(stack* p);//出栈
void printstack(stack* p);//打印栈的长度和值

void init(stack* p)
{
p->top=-1;
for(int i=0;i<MAXSIZE;i++)
  p->val[i]=0;
}

void push(stack* p,int val)
{
if(p->top+1>=MAXSIZE)
  printf("\n入栈失败,栈已满!");
else
{
p->val[p->top+1]=val;
p->top++;
printstack(p);//此时p已经表示栈的地址
}
}

void pop(stack* p)
{
int i;
if(p->top<0)
  printf("\n出栈失败,栈已空!");
else
{
i=p->val[p->top];
p->top--;
printf("\n出栈元素为:%d",i);
printstack(p);
}
}

void printstack(stack* p)
{
printf("\n当前栈的长度为:%d",p->top+1);
printf("\n当前栈中的元素为:");
printf("\n栈顶->");
for(int i=p->top;i>=0;i--)//栈的特性为后进先出，所以下标最大的元素为栈顶
{
if(i==p->top)
printf("%d\n",p->val[i]);
else
printf("      %d\n",p->val[i]);
}
}

void main()
{
stack p;
init(&p);
int a;
char x;
while(x!='q'&&x!='Q')
{
printf("\n入栈按A,出栈按B,退出按Q:");
scanf(" %c",&x);
if(x=='A'||x=='a')
{
printf("\n请输入要入栈的数:");
scanf(" %d",&a);
push(&p,a);
}
else if(x=='B'||x=='b')
  pop(&p);
else if(x=='Q'||x=='q')
  break;
else
printf("\n请输入正确的选项:");
}
}
