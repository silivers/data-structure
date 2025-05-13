#include <stdio.h>
#include <stdlib.h>
//顺序表(动态扩展)
typedef struct seqlist
{
int* data;
int maxsize;
int length;
}seqlist;

void insert(seqlist* list,int a,int val);
void delete(seqlist* list,int a);
void printlist(seqlist* list);
void init(seqlist* list);
void expand(seqlist* list);

void init(seqlist* list)//初始化
{
list->maxsize=5;
list->length=0;
list->data=(int*)malloc(list->maxsize*sizeof(int));
}

void insert(seqlist* list,int a,int val)//插入
{
if(list->length>=a&&a>=0&&list->length!=list->maxsize)//判断是否越界以及表是否已满
{
for(int i=list->length-1;i>a;i--)
  list->data[i]=list->data[i-1];
list->data[a]=val;
list->length++;
}
else if(list->length >= list->maxsize)//如果表满则扩充
{
expand(list);
insert(list,a,val);//此时list已经是指向seqlist类型的指针，所以直接输入list
}
else
printf("请输入正确的位数!\n");
}

void delete(seqlist* list,int a)//删除
{
if(list->length>=a&&a>0)
{
for(;list->length>a;a++)
  list->data[a-1]=list->data[a];
list->length--;
}
else
printf("请输入正确的位数");
}

void printlist(seqlist* list)//打印表项
{
for(int i=0;list->length>i;i++)
  printf("%d",list->data[i]);
printf("\n");
}

void expand(seqlist* list)//扩充表
{
list->maxsize*=2;//扩充为初始容量的2倍
int* temp=(int*)malloc(list->maxsize*sizeof(int));//存放扩充后的表
for(int i=0;i<list->length;i++)
  temp[i]=list->data[i];//数据迁移
free(list->data);//释放data指针原来指向的空间(扩充前的空间)
list->data=temp;//data指针指向扩充后的空间
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
printf("插入按A,删除按B,打印按C,扩充按D退出按Q\n");
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
else if(x=='D'||x=='d')
  expand(&list);
else if(x=='Q'||x=='q')
  break;
else
printf("请输入正确的选项\n");
}}
