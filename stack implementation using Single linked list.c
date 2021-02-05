#include<stdio.h>
struct node
{
  int data;
  struct node *next;
};
struct node *push (struct node *);
struct node *pop (struct node *);
void display (struct node *top);
void main ()
{

  struct node *top = NULL;
  int opt;
  printf ("1.push\n2.pop\n3.display\n4.exit\n");
  do{
	printf("enter your choice ");
	scanf("%d",&opt); 

      switch (opt)
	{
	case 1:
	  		top = push (top);
	  		break;
	case 2:
	  		top = pop (top);
	 		 break;
	case 3:
	 		 display (top);
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

struct node *push (struct node *top)
{
  struct node *temp;
  temp = (struct node *) malloc (sizeof (struct node));
  printf ("enter element\n");
  scanf ("%d", &temp->data);
  temp->next = top;
  top = temp;
  return top;
}

struct node *pop (struct node *top)
{
  struct node *temp;
  if (top == NULL)
    {
      printf ("stack is empty\n");
    }
  else
    {
      temp = top;
      printf ("element is:%d\n", temp->data);
      top = top->next;
      temp->next = NULL;
      free (temp);
      return top;
    }
}

void display (struct node *top)
{
  struct node *temp;
  temp=top;
  if (top == NULL)
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

