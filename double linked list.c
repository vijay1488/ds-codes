#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int data;
	struct node *next;
	struct node *pre;
};
struct node*insert_begin(struct node *);
struct node*insert_end(struct node *);
struct node*insert_pos(struct node *);
struct node *del_head(struct node*);
struct node *del_tail(struct node*);
struct node *del_ele(struct node *);
struct node *del_pos(struct node *);
struct node *length(struct node *);
void display(struct node *);
void main()
{
	struct node *head=NULL;
int ch;
printf("1.insert_begin\n 2.insert_end \n 3.insert_pos\n 4.del_head\n 5.del_tail\n 6.del_ele\n 7.del_pos\n 8.display\n 9.length\n 10.exit\n");
do{
printf("enter a choice ");	
scanf("%d",&ch);
switch(ch)
{
	case 1:
			head=insert_begin(head);
			break;
	case 2:
			head=insert_end(head);
			break;
	case 3:
			head=insert_pos(head);
			break;
	case 4:
			head=del_head(head);
			break;
	case 5:
			head=del_tail(head);
			break;
	case 6:
			head=del_ele(head);
			break;
	case 7:
			head=del_pos(head);
			break;
	case 8:
			display(head);
			break;
	case 9:
			head=length(head);
			break;
	case 10:
			exit(1);
	default:
			printf("enter a valid choice\n");
}
}while(ch!=10);
}
struct node *insert_begin(struct node *head)
{
	struct node *temp;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter node data\n");
	scanf("%d",&temp->data);
	temp->pre=NULL;
	temp->next=NULL;
	if(head==NULL)
	{
		head=temp;
	}
	else
	{
		temp->next=head;
		temp->pre=NULL;
		head->pre=temp;
		head=temp;
	}
	return head;
}
struct node *insert_end(struct node *head)
{
	struct node *temp1,*temp=head;
	temp1=(struct node *)malloc(sizeof(struct node));
	printf("enter node data\n");
	scanf("%d",&temp1->data);
	temp1->next=NULL;
	if(head==NULL)
	{
		head=temp1;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=temp1;
		temp1->pre=temp;
		temp1->next=NULL;
	}
	return head;
}
struct node *insert_pos(struct node *head)
{
	struct node *temp1,*temp=head,*p;
	temp1=(struct node *)malloc(sizeof(struct node));
	printf("enter node data\n");
	scanf("%d",&temp1->data);
	temp1->pre=NULL;
	temp1->next=NULL;
	int pos,i=1;
	printf("enter position to insert node \n");
	scanf("%d",&pos);
	if(pos==1)
	{
		temp1->next=head;
		head=temp1;
	}
	else
	{
	while(i<pos && temp!=NULL)
	{
		p=temp;
		temp=temp->next;
		i++;
	}
	temp1->next=temp;
	temp1->pre=p;
	p->next=temp1;
	temp->pre=temp1;
}
return head;
}
struct node *del_head(struct node *head)
{
	if(head->next==NULL)
	{
		printf("list is empty\n");
	}
	else if(head->next!=NULL)
	{
		head=head->next;
		head->pre=NULL;
	}
	else
	{
		head=NULL;
		struct node *temp=head;
		temp=temp->next;
		temp->next->pre=NULL;
	}
	return head;
}
struct node *del_tail(struct node *head)
{
	struct node*temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	temp=temp->pre;
	temp->next->pre=NULL;
	temp->next=NULL;
	
	return head;
}
struct node *del_ele(struct node *head)
{
	int ele,flag=0;
	struct node*temp=head,*temp1,*temp2;
	printf("enter element to delete\n");
	scanf("%d",&ele);
	if(head->data==ele)
	{
		head=head->next;
		head->pre=NULL;
	}
	else
	{
	while(temp!=NULL)
	{
		if(temp->data==ele)
		{
			flag=1;
			break;
		}
		temp1=temp;
		temp=temp->next;
		temp2=temp->next;
	}
	if(flag==1)
	{
		temp1->next=temp->next;
		temp2->pre=temp->pre;
		temp->pre=NULL;
		temp->next=NULL;
	}
	else
	{
		printf("element not found\n");	
	}
}
	return head;	
}
struct node *del_pos(struct node *head)
{
	struct node *temp1,*temp2,*temp=head;
	int pos,i=1;
	printf("enter position to delete\n");
	scanf("%d",&pos);
	if(pos==1)
	{
		head=head->next;
		head->pre=NULL;
	}
	else
	{
	while(i<pos && temp!=NULL)
	{
		temp1=temp;
		temp=temp->next;
		temp2=temp->next;
		i++;
	}
	temp1->next=temp->next;
	temp2->next->pre=temp->pre;
	temp1->pre=NULL;
	temp->next=NULL;
}
return head;
}
struct node *length(struct node *head)
{
	struct node *temp=head;
	int count=1;
	while(temp->next!=NULL)
	{
		temp=temp->next;
		count++;
	}
	printf("no.of nodes are %d\n",count);
	return head;
}
void display(struct node *head)
{
	struct node *temp=head;
	while(temp!=NULL)
	{
		printf("%d \n",temp->data);
		temp=temp->next;
	}
}
