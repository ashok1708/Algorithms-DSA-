#include<stdio.h>
#include<stdlib.h>

typedef struct _Node
{
 int val;
 struct _Node *next;
}Node;

Node *makeNode(int);
void print(Node*);
void reverse(Node*);
int count(Node*);
Node *locate(Node*,int);
int CountOccurance(Node*,int);

void main()
{
 Node *start='\0',*last='\0',*nd;
 int n;

 printf("\n");

 while(1)
 {
  printf("Enter an Item : ");
  scanf("%d",&n);

  if(n==0) break;
  nd=makeNode(n);
  if(start=='\0')
   start=nd;
  else
   last->next=nd;

  last=nd;
 }

 printf("\nItems in the List : ");
 print(start);
 printf("\nCount of Items    : %d\n",count(start));

 nd=locate(start,25);
 if(nd)
  printf("\nItem Found in the List : %d\n",nd->val);
 else
  printf("\nItem Not Found in the List..\n");

 printf("\nNo. of times '25' occurs in the List : %d\n",CountOccurance(start,25));
 

 reverse(start);
 nd=start;
 start=last;
 last=nd;

 printf("\n");
 printf("\nReverse of the List : ");
 print(start);


}

Node *makeNode(int n)
{
 Node *nd;
 nd=(Node*)malloc(sizeof(Node));
 nd->val=n;
 nd->next='\0';
 return nd;
}

void print(Node *ptr)
{
 printf("[ ");
 while(ptr)
 {
  printf("%d ",ptr->val);
  ptr=ptr->next;
 }
 printf("]\n");
}

void reverse(Node *ptr)
{
 if(ptr=='\0'||ptr->next=='\0') return;

 reverse(ptr->next);
 ptr->next->next=ptr;
 ptr->next='\0';
}

int count(Node *ptr)
{
 if(ptr=='\0') return 0;
 return count(ptr->next)+1;
}

Node *locate(Node *ptr,int n)
{
 if(ptr=='\0'||ptr->val==n)
 return ptr;
 return locate(ptr->next,n);
}

int CountOccurance(Node *ptr,int n)
{
 int cnt;
 if(ptr=='\0') return 0;
 cnt=CountOccurance(ptr->next,n);
 if(ptr->val==n) cnt++;
 return cnt;
}

