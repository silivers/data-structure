//链表的各种反转
#include <stdio.h>
#include <stdlib.h>

typedef struct listnode
{
struct listnode* next;
int val;
int length;
}listnode;
listnode* head;

void insert(int a,int val);//插入
void invert1();//迭代法
listnode* invert2();//递归法
void invert3();//头插法
void invert4();//栈辅助法
void printlist();//获取链表值

void insert(int a,int val)
{
listnode* temp=(listnode*)malloc(sizeof(listnode));
listnode* p=head;
if(a>head->length)//获取链表长度以判断是否越界
  printf("\n请输入正确的位置!");
else
{
temp->val=val;
for(int i=0;a>i;i++)
  p=p->next;
temp->next=p->next;
p->next=temp;
head->length++;
printf("插入成功,当前链表为:");
printlist();
}
}

void printlist()
{
listnode* p=head->next;
while(p!=NULL)
{
printf("%d",p->val);
p=p->next;
}
printf("\n");
}

invert1()
{
listnode* p=head->next;//当前指针
listnode* next;//下一个节点指针
listnode* prev;//前一个节点指针
prev=NULL;
while(p!=NULL)
{
next=p->next;//next指针保存p的下一个节点
p->next=prev;//p所指节点的next指针指向p节点的前一位(prev)
prev=p;//prev指针前进一位(prev始终落后p一位)
p=next;//p指针前进一位
}
head->next=prev;//反转完毕后prev为首元节点
printlist();
}

// 递归辅助函数：反转以 node 为起点的链表，返回反转后的新头节点
listnode* recursive_reverse(listnode* node)
{
    // 递归终止条件：当节点为空或只剩最后一个节点时，直接返回它作为新的头节点
    if (node == NULL || node->next == NULL)
        return node;
    // 递归反转 node 的下一个节点开始的子链表，new_head 是反转后的新头
    listnode* new_head = recursive_reverse(node->next);
    // 将当前节点 node 插到子链表尾部：
    // node->next 当前是子链表反转后的最后一个节点
    // 所以让它的 next 指回 node，实现反转
    node->next->next = node;
    // 断开 node 和后面节点的连接，避免形成环
    node->next = NULL;
    // 返回子链表反转后的头节点 new_head
    return new_head;
}

// 递归反转整个链表的接口函数，从 head->next 开始
listnode* invert2()
{
    // 调用递归函数，反转实际链表部分（不包括带 length 的头结点）
    head->next = recursive_reverse(head->next);
    // 打印反转后的链表
    printlist();
    // 返回整个链表头指针（一般用于链式操作）
    return head;
}


int main(void)
{
head=(listnode*)malloc(sizeof(listnode));
head->next=NULL;//初始化
head->length=0;
int a,val;
char x;
while(x!='y'&&x!='Y')
{
printf("请输入要插入的位置和值(按y退出):");
scanf("%d %d",&a,&val);
insert(a,val);
printf("需要退出吗?");
scanf(" %c",&x);
}
int i;
printf("迭代法反转按1\n");
printf("递归法反转按2\n");
printf("头插法反转按3\n");
printf("栈辅助法反转按4\n");
printf("退出按0\n");
while(i!=0)
{
scanf(" %d",&i);
switch(i)
{
case 1:
invert1();
break;
case 2:
invert2();
break;
case 3:
invert3();
break;
case 4:
invert4();
break;
default:
printf("请输入正确的选项\n");
break;
}}
}
