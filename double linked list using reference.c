#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *pre;
	int e;
	struct node *next;
};
void insertbegin(struct node **head)
{
	int ele;
	struct node *nn=(struct node*)malloc(sizeof(struct node));
	printf("enter element to insert: ");
	scanf("%d",&ele);
	if(nn==NULL)
		printf("memory not allocated");
	else
	{
		if(*head==NULL)
		{
			(*head)=(struct node*)malloc(sizeof(struct node));
			(*head)->e=ele;
			(*head)->pre=NULL;
			(*head)->next=NULL;
		}
		else
		{
			nn->e=ele;
			nn->pre=NULL;
			nn->next=*head;
			(*head)->pre=nn;
			*head=nn;
		}
	}
	return *head;
}
void insertend(struct node **head)
{
	struct node *nn;
	struct node *tmp=*head;
	int ele;
	printf("enter the element:");
	scanf("%d",&ele);
	nn=(struct node*)malloc(sizeof(struct node));
	while(tmp->next!=NULL)
	{
		tmp=tmp->next;
	}
	if(*head==NULL)
		{
			*head=(struct node*)malloc(sizeof(struct node));
		(*head)->e=ele;
			(*head)->pre=NULL;
			(*head)->next=NULL;
		}
	else
	{
		tmp->next=nn;
		nn->pre=tmp;
		nn->e=ele;
		nn->next=NULL;
	}
	return *head;
}
void insertpos(struct node **head)
{
	int c=1,ele,n,count=1;
	struct node *tmp=*head;
	struct node *nn;
	nn=(struct node*)malloc(sizeof(struct node));
	printf("enter the position:");
	scanf("%d",&n);
	printf("enter the element:");
	scanf("%d",&ele);
	nn->e=ele;
	if(head==NULL)
		{
			*head=(struct node*)malloc(sizeof(struct node));
			(*head)->e=ele;
			(*head)->pre=NULL;
			(*head)->next=NULL;
		}
	else
	{
		
		while(tmp->next!=NULL)
		{
			count++;
			tmp=tmp->next;
		}
		tmp=*head;
		if(n<count)
		{

			while(c<n-1)
			{
				tmp=tmp->next;
				c++;
			}
		}
	
		else
			printf("invalid position\n");
		
		nn->next=tmp->next;
		nn->pre=tmp;
		tmp->next=nn;
	}
	return *head;
}

void delbegin(struct node **head)
{
	if(*head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
	(*head)->next->pre=NULL;
	*head=(*head)->next;
}
return *head;
}

void delend(struct node **head)
{
	struct node *tmp=*head;
	if(*head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
	while(tmp->next->next!=NULL)
	{
		tmp=tmp->next;
	}
	tmp->next->pre=NULL;
	tmp->next=NULL;
}
return *head;
}

void delele(struct node **head)
{
	struct node *tmp=*head,*tmp1=*head;
	int ele,f=0;
	printf("enter the element to delete:");
	scanf("%d",&ele);
	if(*head==NULL)
		printf("list is empty\n");
	else
	{	
	while(tmp!=NULL)
	{
		if(tmp->e==ele)
		{
	
			f=1;
			break;
		}
		tmp=tmp->next;
	}
	if(f==1)
	{
		if((*head)->e==ele)
		{
			(*head)->next->pre=NULL;
			*head=(*head)->next;
		}
		else 
		{
			while(tmp1->next!=tmp)
			{
				tmp1=tmp1->next;
			}
			tmp->next->pre=tmp1;
			tmp1->next=tmp->next;
		}
	}
	else
	{
		printf("element not found\n");
	}
}
return *head;		
}
void search(struct node **head)
{
	struct node *tmp=*head;
	int ele,f;
	printf("enter element to search:");
	scanf("%d",&ele);
	f=0;
	if(*head==NULL)
	{
		printf("list is empty\n");
	}
	else
	{
	while(tmp!=NULL)
	{
		if(tmp->e==ele)
		{
			f=1;
			break;
		}
		else
		{
			tmp=tmp->next;
		}
	}
	if(f==1)
	{
		printf("element found\n");
	}
	else
		printf("element not found\n");
	}
return *head;
}
void display(struct node **head)
{
	struct node *tmp=*head;
	if(*head==NULL)
		printf("list is empty\n");
		else
		{
		
	while(tmp!=NULL)
	{
		printf("%d\n",tmp->e);
		tmp=tmp->next;
	}}
	return *head;
}
void main()
{
	struct node **head=NULL;
	int op;
	do
	{
		printf("1.Insert begin\n2.Insert end\n3.Insert at position\n4.del begin\n5.del end\n6.del position\n7.Display\n8.Search\n9.Exit\n");
		printf("Your option:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				{
					insertbegin(&head);
					break;
				}
			case 2:
				{
					insertend(&head);
					break;
				}
			case 3:
				{
					insertpos(&head);
					break;
				}
			case 4:
				{
					delbegin(&head);
					break;
				}
			case 5:
				{
					delend(&head);
					break;
				}
			case 6:
				{
					delele(&head);
					break;
				}
			case 7:
				{
					display(&head);
					break;
				}
			case 8:
				{
					search(&head);
					break;
				}
			case 9:
				{
					exit(0);
				}
		}
	}
	while(op!=9);
}
