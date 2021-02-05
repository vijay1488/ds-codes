#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
	char a[20];
	int top;
	//int n;
};
char top(struct stack *);
int push(struct stack *,char);
int prior(char);
char pop(struct stack *);
int iseampty(struct stack *);
int main()
{
	char exp[20];
	struct stack *s;
	s=(struct stack *)malloc(sizeof(struct stack));
	s->top=-1;
	printf("Enter expression: ");
	scanf("%s",exp);
	char *e=exp;
	while(*e!='\0')
	{	
		if(*e>='a' && *e<='z' || *e>='A' && *e<='Z')
		{
			printf("%c",*e);
		}
	    else if(*e =='(')
		{
				push(s,*e);
		}
		else if(*e==')')
		{
			while(top(s)!='(')
			{
					printf("%c",pop(s));
			}
				pop(s);
		}
		else
		{
			while(prior(top(s))>=prior(*e))
				printf("%c",pop(s));
			push(s,*e);
		}
		e++;
	}	
		while(!iseampty(s))
		{
			printf("%c",pop(s));
		}
	return 0;
}
char top(struct stack *s)
{
	if(s->top==-1)
	{
		return '$';
	}
	else
		return s->a[s->top];
}
int prior(char c)
{
	//if(c=='(')
	//	return 0;
    if(c=='+' || c=='-')
	{
		return 1;
	}
	else if(c=='*' || c=='/')
	{
		return 2;
	}
	else
		return 0;
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
		return '$';
	}
	else
	{
		return(s->a[s->top--]);
	}	
}
int iseampty(struct stack *s)
{
	if(s->top==-1)
		return 1;
	else
		return 0;
}



