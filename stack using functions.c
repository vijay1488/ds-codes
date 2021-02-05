#include<stdio.h>
int push(int*,int);
int pop(int*,int);
int peek(int*,int);
int display(int*,int);
int main(){
	int n=5;
int op;
int top=-1;
int a[n];
	do{		
	printf("1.push\n2.pop\n3.peek\n4.display \n");
	printf("enter choice -->");
	scanf("%d",&op);
		switch(op){
			case 1:
				    top=push(&a,top);
				    break;
			case 2:
					top=pop(&a,top);
					break;
			case 3:
				    peek(&a,top);
				    break;
			case 4:
					display(&a,top);
					break;
			default:
				    printf("invalid option\n");
				    break;
				    
		}
	}
	while(op!=0);
}
int push(int *a,int top){
    int n=5;
	if(top==n-1){
		printf("stack is full \n");
	}
	else{
		int ele;
		printf("enter element\n");
		scanf("%d",&ele);
		top++;
		a[top]=ele;
	}
		return top;
}
int pop(int *a,int top){
	if(top==-1){
		printf("stack is eampty");
	}
	else{
	printf("%d\n",a[top]);
		top--;
	}
		return top;
}
int peek(int *a,int top){
	if(top==-1){
		printf("stack is eampty\n");
	}
	else{
		printf("%d\n",a[top]);
	}
}
int display(int *a,int top){
	int i;
	for(i=top;i>=0;i--){
		 printf("%d \n",a[i]);
	}
}

