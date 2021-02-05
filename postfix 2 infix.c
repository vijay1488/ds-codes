#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define n 20
struct stack
{
    char a[n];
	int top;
};
int push(struct stack *,char);
char pop(struct stack *);
int isoperand(char);
void main()
{
	struct stack *s;
	s=(struct stack *)malloc(sizeof(struct stack));
	s->top=-1;
	int p,k;
	for(p=0;p<n;p++)
	{
		s->a[p]="\0";
	}
	char exp[n]={"\0"};
	char ele;
	printf("enter expression\n");
	scanf("%s",exp);
	int i=0,j;
	while(i<strlen(exp))
	{
		ele=exp[i];
		if(isoperand(ele))
		{
			push(s,ele);
			push(s,' ');
		}
		else
		{
			k=s->top-1;
			for(j=k;j>=0;j--)
			{
				if(s->a[j]==' ')
				{
				    s->a[j]=ele;
				    break;
				}
			}
		}
		i++;
	}
	printf("infix expression is :%s",s);
}
	int isoperand(char ele)
	{
		if(ele>='A' && ele<='Z' || ele>='a' && ele<='z')
		{
			return 1;
		}
		else
		{
			return 0;
		}	
	}

	int push(struct stack *s,char c)
	{
		s->top++;
		s->a[s->top]=c; 
	}

	char pop(struct stack *s)
	{
	if(s->top==-1)
	{
		printf("stack is eampty\n");
	}
	else
	{
		return(s->a[s->top--]);
	}	
}
	
