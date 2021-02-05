#include<stdio.h>
struct node
{
  int data;
  struct node *next;
  struct node *pre;
};
struct node *push (struct node *);
struct node *pop (struct node *);
void display (struct node *);
void main ()
{

  struct node *head = NULL;
  int opt;
  printf ("1.push\n2.pop\n3.display\n4.exit\n");
  do{
	printf("enter your choice:");
	scanf("%d",&opt); 

      switch (opt)
	{
	case 1:
	  		head = push (head);
	  		break;
	case 2:
	  		head = pop (head);
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

struct node *push (struct node *head)
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

struct node *pop (struct node *head)
{
  struct node *temp;
  if (head == NULL)
    {
      printf ("stack is empty\n");
    }
  else
    {
      struct node *temp=head;
      while(temp->next!=NULL)
      {
      	temp=temp->next;
	  }
	  temp=temp->pre;
	  temp->next->pre=NULL;
	  temp->next=NULL;
      return head;
    }
}

void display (struct node *head)
{
  struct node *temp=head;
  if (head == NULL)
    {
      printf ("stack is empty\n");
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

