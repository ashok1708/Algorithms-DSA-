#include<stdio.h>
#include<stdlib.h>

typedef struct _Node
{
 int val;
 struct _Node *next;
}Node;

Node *makeNode(int);
void print(Node*);
int  countItems(Node*);
Node *locate(Node*,int);
int  countOccurrence(Node*,int);
void printSmallerItems(Node*);
void printReverse(Node*);
Node *insAfter(Node*,Node*,int,int);
Node *insBefore(Node*,int,int);
Node *rmvNode(Node*,Node**,int);

void main()
{
 Node *start='\0',*last='\0',*nd;
 int n,pos;

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
 
 printf("\nCount of Items    : %d\n",countItems(start));

 nd=locate(start,25);
 if(nd)
  printf("\nItem Found in the List : %d\n",nd->val);
 else
  printf("\nItem Not Found in the List..\n");
 
 printf("\nNo. of times '25' occurs in the List : %d\n",countOccurrence(start,25));

 printSmallerItems(start);
 
 printf("\nItems in Reverse Order : ");
 printReverse(start);

 printf("\n");

 printf("\nEnter the position and item to insert(Insert after ) : ");
 scanf("%d%d",&pos,&n);
 last=insAfter(start,last,pos,n);

 print(start);

 printf("\nEnter the position and item to insert(INsert before) : ");
 scanf("%d%d",&pos,&n);
 start=insBefore(start,pos,n);

 print(start);

 printf("\nEnter the Position to delete    : ");
 scanf("%d",&pos);
 start=rmvNode(start,&last,pos);

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

int countItems(Node *ptr)
{
 int n=0;
 while(ptr)
 {
  n++;
  ptr=ptr->next;
 }
 return n;
}

Node *locate(Node *ptr,int n)
{
 while(ptr&&ptr->val!=n) ptr=ptr->next;

 return ptr;
}

int countOccurrence(Node *ptr,int n)
{
 int cnt=0;
 while(ptr)
 {
  if(ptr->val==n) cnt++;
  ptr=ptr->next;
 }
 return cnt;
}

void printSmallerItems(Node *start)
{
 int avg,cnt;
 Node *ptr;
 
 for(avg=cnt=0,ptr=start;ptr;ptr=ptr->next)
 {
  avg+=ptr->val;
  cnt++;
 }

 avg/=cnt;
 printf("\nItems Smaller than the Average(%d) : [ ",avg);
 for(ptr=start;ptr;ptr=ptr->next)
 {
  if(ptr->val<avg) printf("%d ",ptr->val);
 }

 printf("]\n");
}

void printReverse(Node *ptr)
{
 if(ptr=='\0')
 {
  printf("[  "); 
  return;
 }

 printReverse(ptr->next);

 printf("\b%d ]",ptr->val);
}

Node *insAfter(Node *ptr,Node *last,int pos,int n)
{
 Node *nd=makeNode(n);
 while(ptr&&pos>1)
 {
  ptr=ptr->next;
  pos--;
 }
 if(ptr)
 {
  nd->next=ptr->next;
  ptr->next=nd;
 if(ptr==last) last=nd;
 }
 return last;
}

Node *insBefore(Node *start,int pos,int n)
{
 Node *ptr,*prv,*nd;
 ptr=start;
 while(ptr&&pos>1)
 {
  prv=ptr;
  ptr=ptr->next;
  pos--;
 }
 if(ptr)
 {
  nd=makeNode(n);
  nd->next=ptr;
  if(ptr==start) start=nd;
  else prv->next=nd;
 }
 return start;
}

Node *rmvNode(Node *start,Node **p2last,int pos)
{
 Node *ptr,*prv;
 ptr=start;
 while(ptr&&pos>1)
 {
   prv=ptr;
  ptr=ptr->next;
  pos--;
 }
 if(ptr)
 {
  if(ptr==start)
  {
  start==start->next;
  }
  else
  {
   prv->next=ptr->next;
   if(ptr==*p2last) *p2last=prv;
  }
 free(ptr);
 }
 return start;
}
 

