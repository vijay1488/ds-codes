#include<stdio.h>
struct node
{
  int data;
  struct node *next;
  struct node *pre;
};
struct node *enqueue (struct node *);
struct node *dequeue (struct node *);
void display (struct node *);
void main ()
{

  struct node *head = NULL;
  int opt;
  printf ("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
  do{
	printf("enter your choice:");
	scanf("%d",&opt); 

      switch (opt)
	{
	case 1:
	  		head = enqueue (head);
	  		break;
	case 2:
	  		head = dequeue (head);
	 		 break;
	case 3:
	 		 display (head);
	 		 break;
	case 4:
	 		 exit (1);
	  		break;
	default:
			printf("invalid option\n");
			break;
	  
	}
    }
  while (opt != 4);
}

struct node *enqueue (struct node *head)
{
  struct node *temp1,*temp=head;
  temp1 = (struct node *) malloc (sizeof (struct node));
  printf ("enter element\n");
  scanf ("%d", &temp1->data);
  temp1->next = NULL;
  temp1->pre=NULL;
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

struct node *dequeue (struct node *head)
{
  if(head==NULL)
  {
  	printf("queue is empty");
  }
  else if(head!=NULL)
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

void display (struct node *head)
{
  struct node *temp=head;
  if (head == NULL)
    {
      printf ("queue is empty\n");
    }
  else
    {
    while(temp!=NULL)
    {
      printf ("%d \n", temp->data);
      temp = temp->next;
    }
    }
}

