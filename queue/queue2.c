//队列的链表实现
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
int val;
int size;
struct node* next;//指向队尾
}node;

void push(node* queue,int val);//尾部入队
void pop(node* queue);//头部出队
void print(node* queue);//打印队列中的元素
node* head;//指向队列头部
node* rear;//指向队列尾部

void push(node* queue,int val)
{
node* temp=(node*)malloc(sizeof(node));
temp->val=val;
rear->next=temp;//temp插入队尾
temp->next=NULL;
rear=temp;//rear重新指向队尾
head=queue->next;//head指向队头节点
queue->size++;
print(queue);
}

void pop(node* queue)
{
node* p=queue;
if(p->next==NULL)
  printf("队列为空!\n");
else
{
printf("出队元素为:%d\n",head->val);
p->next=head->next;
free(head);
head=p->next;//head重新指向队头
queue->size--;
print(queue);
}
}

void print(node* queue)
{
node* p=queue;
printf("当前队列长度为:%d\n",queue->size);
printf("当前队列元素为:\n");
printf("队头->");
for(int i=0;i<queue->size;i++)
{
if(i==0)
{p=p->next;
printf("%d\n",p->val);}
else
{p=p->next;
printf("      %d\n",p->val);}
}
}

void main()
{
//初始化
node* queue=(node*)malloc(sizeof(node));
queue->next=NULL;
queue->size=0;
rear=queue;//rear指向队尾节点(queue->next才是NULL!)

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
push(queue,a);
}
else if(x=='B'||x=='b')
  pop(queue);
else if(x=='Q'||x=='q')
  break;
else
printf("\n请输入正确的选项:");
}
}
