#include <stdio.h>
#include <stdlib.h>
//带头结点的链表

void insert(int a,int val);//按位插入
void delete(int a);//按位删除
void print();//打印链表
void invert();//反转链表
int length();//计算链表长度

typedef struct listnode
{
int val;
struct listnode* next;
}listnode;
listnode* head;

void insert(int a,int val)
{
listnode* temp=(listnode*)malloc(sizeof(listnode));//为要插入的节点分配空间
listnode* p=head;//p为指向要插入位置的指针，并未分配空间
for(int i=0;i<a;i++)
{
p=p->next;
}
temp->val=val;
temp->next=p->next;
p->next=temp;
}

void print()
{
listnode* p=head;
if(p->next==NULL)
{printf("此时链表为空，如需插入请输入第0位\n");
return;}
while(p!=NULL&&p->next!=NULL)//打印链表的值
{
p=p->next;
printf("%d ",p->val);
}
printf("\n");
}

int length()
{
listnode* p=head;
int count=0;
while(p->next!=NULL)
{
p=p->next;
count++;}
return count;}

void delete(int a)
{
listnode* p=head;//p指针指向要删除节点的前一位
listnode* q;//q指针指向要删除的节点
for(int i=1;i<a;i++)
p=p->next;
//删除逻辑
q=p->next;
p->next=q->next;
free(q);
}

void invert()
{
listnode* p;//当前节点
listnode* prev;//p的前一个节点
listnode* next;//p的后一个节点
p=head->next;//初始化
prev=NULL;
printf("\n");
while(p!=NULL)
{
next=p->next;
p->next=prev;
prev=p;
p=next;
}
head->next=prev;//反转完毕，此时prev为新的首元节点
print();
}


int main (void)
{
head = (listnode*)malloc(sizeof(listnode));//头节点初始化
head->next = NULL;
char c;
printf("插入请按A，删除请按B,反转请按C,退出请按Q\n");
while (c!='q'&&c!='Q')
{
int a,val,count;
scanf(" %c",&c);
if(c=='A'||c=='a')//插入
{
printf("当前链表为：");
count=length();//获取链表长度以判断插入是否合法
print();
printf("\n请输入要插入第几位以及要插入的数:");
scanf("%d %d",&a,&val);
if(count>=a)
{
insert(a,val);
printf("插入完成，当前链表为：");
print();
}
else
printf("请输入正确的位数\n");
}
else if(c=='B'||c=='b')//删除
{
int count;
printf("当前链表为：");
count=length();//获取链表长度以判断删除是否合法
print();
printf("\n请输入要删除第几位:");
scanf("%d",&a);
if(count>=a&&a!=0)
{delete(a);
printf("删除完成，当前链表为：");
print();}
else
printf("请输入正确的位数\n");
}
else if(c=='C'||c=='c')//反转
invert();

else if(c=='Q'||c=='q')
return 0;
else
printf("请输入A,B,C或者Q");
}
}
