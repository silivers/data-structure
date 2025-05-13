//循环队列
#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

typedef struct queue
{
int val[MAXSIZE];
int head;//指向队头
int rear;//指向队尾
int size;//记录当前队列长度
}queue;

void init(queue* p);//初始化
void push(queue* p,int val);//尾部入队
void pop(queue* p);//头部出队
void print(queue* p);//打印队列中的元素

void init(queue* p)
{
for(int i=0;i<MAXSIZE;i++)
  p->val[i]=0;
p->size=0;
p->head=0;
p->rear=MAXSIZE-1;
}

void push(queue* p,int val)
{
if(p->size==MAXSIZE)
  printf("\n队列已满!");
else
{
p->rear=(p->rear+1)%MAXSIZE;//如果队尾指针达到数组最大长度则返回位置0
p->val[p->rear]=val;
p->size++;
print(p);
}
}

void pop(queue* p)
{
if(p->size==0)
  printf("\n队列已空!");
else
{
printf("\n出队元素为:%d",p->val[p->head]);
p->head=(p->head+1)%MAXSIZE;//如果队头指针达到数组最大长度则返回位置0
p->size--;
print(p);
}
}

void print(queue* p)
{
printf("当前队列长度为:%d\n",p->size);
printf("当前队列元素为:\n");
printf("队头->");
int temp=p->head;
for(int i=0;i<p->size;i++)//size比队列实际容量的数组下标大1(size=5时数组为p[4])
{
if(i==0)//美观排版
{printf("%d\n",p->val[temp]);
temp=(temp+1)%MAXSIZE;}
else
{printf("      %d\n",p->val[temp]);
temp=(temp+1)%MAXSIZE;}
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
