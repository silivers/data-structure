//队列的数组实现(单指针)
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct queue
{
int val[MAXSIZE];
int rear;//指向队尾
}queue;

void init(queue* p);//初始化
void push(queue* p,int val);//尾部入队
void pop(queue* p);//头部出队
void print(queue* p);//打印队列中的元素

void init(queue* p)
{
for(int i=0;i<MAXSIZE;i++)
  p->val[i]=0;
p->rear=-1;
}

void push(queue* p,int val)
{
if(p->rear+1>=MAXSIZE)//rear最大值应为MAXSIZE-1
  printf("队列已满!\n");
else
{p->val[p->rear+1]=val;
p->rear++;
print(p);}
}

void pop(queue* p)
{
if(0>p->rear)
  printf("队列已空!\n");
else
{
printf("出队成功，出队元素为%d\n",p->val[0]);//队列永远从头部取出元素
for(int i=0;i<p->rear;i++)
  p->val[i]=p->val[i+1];//元素迁移
p->rear--;
print(p);
}
}

void print(queue* p)
{
printf("当前队列长度为:%d\n",p->rear+1);
printf("当前队列元素为:\n");
printf("队头->");
for(int i=0;i<=p->rear;i++)
{
if(i==0)
printf("%d\n",p->val[i]);
else
printf("      %d\n",p->val[i]);
}
}

void main()
{
queue p;
init(&p);
int a;
char x;
while(x!='q'&&x!='Q')
{
printf("\n入队按A,出队按B,退出按Q:");
scanf(" %c",&x);
if(x=='A'||x=='a')
{
printf("\n请输入要入队的数:");
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
