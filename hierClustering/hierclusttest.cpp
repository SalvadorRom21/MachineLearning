

#include <iostream>
#include <conio>

struct node
{
int dataNode;
node *next;
};

class linklist
{
node *nodeHead;
public:
linklist()
{nodeHead=NULL;}
void createNode(void);
void displayNode(void);
};

void linklist :: createNode(void)
{
node *newl=NULL,*end=newl;
int info;
while(1)
{
cout<<"\n\nenter -999 to terminate\n";
cout<<"enter info:-";
cin>>info;
if(info==-999)
break;
else
{
newl=new node;
newl->dataNode=info;
if(nodeHead==NULL)
nodeHead=newl;
else
end->next=newl;
end=newl;
end->next=NULL;
}
}
}

void linklist :: displayNode(void)
{
cout<<"\n\n\ndisplayNode Function\n";
node *temp=nodeHead;
while(temp!=NULL)
{
cout<<temp->dataNode;
if(temp->next!=NULL)
cout<<"==>";
temp=temp->next;
}
delete(temp);
}

void main()
{
clrscr();
linklist o1;
o1.createNode();
o1.displayNode();
getch();
}
