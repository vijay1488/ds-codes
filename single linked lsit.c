#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node
{
	int data;
	struct node *next;
};
struct node*insert_begin(struct node *);
struct node*insert_end(struct node *);
struct node*insert_pos(struct node *);
struct node*del_head(struct node *);
struct node*del_tail(struct node *);
struct node*del_ele(struct node *);
struct node*del(struct node *);
struct node*length(struct node *);
void display(struct node *);
void main()
{
	struct node *head=NULL;
int ch;
printf("1.insert_begin\n 2.insert_end \n 3.insert_pos\n 4.del_head\n 5.del_tail\n 6.del_ele\n 7.del\n 8.display\n 9.length\n 10.exit\n");
do{
printf("enter a choice\n");	
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
			head=del(head);
			break;
	case 8:
			display(head);
			break;
	case 9:
			head=length(head);
			break;
	case 10:
			exit(1);
			break;
	default:
			printf("enter a valid choice\n");
}
}while(ch!=10);
}
struct node*insert_begin(struct node *head)
{
	struct node *newnode,*temp=head;
	newnode=(struct node *)malloc(sizeof(struct node));
	printf("enter node data \n");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode=temp;
	}
	else
	{
		temp->next=newnode;
		temp=newnode;
	}
	return head;
}
struct node* insert_end(struct node *head)
{
	struct node *nn;
	struct node *p=head;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter node data\n");
	scanf("%d",&nn->data);
	nn->next=NULL;
	if(head==NULL)
	{
		head=nn;
	}
	else
	{
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=nn;
	}
	return head;
}
struct node*insert_pos(struct node *head)
{
	int i=1,loc;
	struct node *p=head;
	struct node *temp,*temp1;
	temp=(struct node *)malloc(sizeof(struct node));
	printf("enter location to insert\n");
	scanf("%d",&loc);
	if(loc==1)
	{
		printf("Enter element: ");
		scanf("%d",&temp->data);
		temp->next=head;
		head=temp;
	}
	else
	{
		while(p!=NULL && i<loc)
		{
				temp1=p;
				p=p->next;
				i++;
		}
		printf("enter node data\n");
		scanf("%d",&temp->data);
		temp->next=NULL;
		temp1->next=temp;
		temp->next=p;
	}
	return head;
}
struct node*del_head(struct node *head)
{
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
	struct node *temp;
		temp=head;
		head=temp->next;
	}
		return head;
}
struct node*del_tail(struct node *head)
{
	struct node *p=head,*q;
	if(head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		while(p->next!=NULL)
		{
			q=p;
			p=p->next;
		}
		q->next=p->next;	
	}
	return head;
}
struct node*del_ele(struct node *head)
{
	int ele,flag=0;
	printf("enter element to delete\n");
	scanf("%d",&ele);
	struct node *q,*p=head;
	if(head->data==ele)
	{
		head=head->next;
	}
	else
	{
		while(p!=NULL)
		{
			if(p->data==ele)
			{
				flag=1;
				break;
			}
			q=p;
			p=p->next;
		}			
		if(flag==1)
		{
			q->next=p->next;
		}
		else
		{
			printf("no element to match \n");
		}
	}
	return head;
}
struct node*del(struct node *head)
{
	int loc,i=1;
	struct node *p=head,*q;
	printf("enter location to delete the element\n");
	scanf("%d",&loc);
	if(loc==1)
	{
		head=head->next;
	}
	else
	{
		while(p!=NULL && i<loc)
		{
			q=p;
			p=p->next;
			i++;
		}
		q->next=p->next;
	}
	return head;
}
struct node*length(struct node *head)
{
	struct node *p=head;
	int count=1;
	while(p->next!=NULL)
	{
		p=p->next;
		count++;
	}
	printf("no.of nodes are %d\n",count);
	return head;
}
void display(struct node *head)
{
	struct node *temp;
	temp=head;
	if(temp==NULL)
	{
		printf("list is eampty\n");
	}
	else
	{
		while(temp!=NULL)
		{
			printf("%d-->",temp->data);
			temp=temp->next;
		}
		printf("\n\n");
	}
}



