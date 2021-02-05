#include<stdio.h>
#include<stdlib.h>
struct stack{
	int *a;
	int top;
	int n;
};
struct stack push(struct stack *);
struct stack pop(struct stack *);
struct stack peek(struct stack *);
struct stack display(struct stack *);
void main(){
struct stack *s;
s=( struct stack *)malloc(sizeof(struct stack));
s->a=(int *)malloc((s->n)*sizeof(int));
s->top=-1;
s->n=5;
int ele,i,op;
do{
	printf("1.push , 2.pop , 3.peek ,4.display \nchoose option\n");
	scanf("%d",&op);
	switch(op){
		case 1:
				push(s);
				break;
		case 2:
				pop(s);
				break;
		case 3:
				peek(s);
				break;
		case 4:
				display(s);
				break;
		default:
				printf("invalid input \n");
	}
}while(op!=4);
}
struct stack push(struct stack *s){
	if(s->top==(s->n)-1){
		printf("stack is full \n");
		}
	else{
	    int ele;
		printf("enter element \n");
		scanf("%d",&ele);
		s->top++;
		s->a[s->top]=ele;	
				}
}
struct stack pop(struct stack *s){
	if(s->top==-1){
		printf("queue is eampty \n");
	}
	else{
		printf("%d\n",s->a[s->top]);
		s->top--;
		}
}
struct stack peek(struct stack *s){
	if(s->top==-1){
		printf("strack is empty");
	}
	else
		printf("%d\n",s->a[s->top]);
}
struct stack display(struct stack *s){
    int i;
		for(i=s->top;i>=0;i--){
			printf("%d",s->a[i]);
		}
}
