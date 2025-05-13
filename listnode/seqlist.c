//顺序表(不带扩容)
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 10

typedef struct seqlist
{
int data[MAXSIZE];
int length;
}seqlist;

void insert(seqlist* list,int a,int val);
void delete(seqlist* list,int a);
void printlist(seqlist* list);
void init(seqlist* list);

void init(seqlist* list)//初始化
{
for(int i=0;i<MAXSIZE;i++)
  list->data[i]=0;
list->length=0;
}


void insert(seqlist* list,int a,int val)//插入
{
if(list->length>=a&&a>=0&&list->length<MAXSIZE)
{
for(int i=list->length-1;i>=a;i--)//循环结束后运行i--
//length长度为数组下标长度加1,例如data[4]对应的length为5.所以i为length-1(从后往前遍历)
  list->data[i+1]=list->data[i];//插入之后数组长度会增加，所以最后一位是i+1(也就是length)

list->data[a]=val;//例如a=2会插入为顺序表的第三个表项(也就是插入到第二个后面)
list->length++;
}
else
printf("请输入正确的位置\n");
}

void delete(seqlist* list,int a)
{

if(a>0&&list->length>=a)
{
for(;list->length-1>=a;a++)//从前往后遍历
  list->data[a-1]=list->data[a];//表的第1项其实是数组的第0项，所以从a-1开始
list->length--;
}
else
printf("请输入正确的位置\n");
}

void printlist(seqlist* list)
{
for(int i=0;i<list->length;i++)
  printf("%d ",list->data[i]);
printf("\n");
}

int main (void)
{
//初始化变量
char x;
int a,val;
seqlist list;
init(&list);

while(x!='q'&&x!='Q')
{
printf("插入按A,删除按B,打印按C,退出按Q\n");
scanf(" %c",&x);
if(x=='A'||x=='a')
{
printf("请输入要插入的位置和值:");
scanf("%d %d",&a,&val);
insert(&list,a,val);
printlist(&list);
}
else if(x=='B'||x=='b')
{
printf("请输入要删除的元素位置:");
scanf(" %d",&a);
delete(&list,a);
printlist(&list);
}
else if(x=='C'||x=='c')
  printlist(&list);
else if(x=='Q'||x=='q')
  break;
else
printf("请输入正确的选项\n");
}
//else if(x=='Q'||x=='q')
}
