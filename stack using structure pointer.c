#include<stdio.h>
struct stack{
	int top;
	int n;
	int a[5];
};
void main(){
	struct stack *s;
	s=(struct stack *)malloc(sizeof(struct stack));
	s->top=-1;
	s->n=5;
	int ele,i,op;

	
	do{
			
	printf("1.push,2.pop,3.exit \n");
	printf("enter choice -->");
	scanf("%d",&op);
		switch(op){
			case 1:
				    if(s->top==s->n-1){
				    	printf("stack is full\n");	    	
					}
					else{
							printf("enter element\n");
						scanf("%d",&ele);
						s->top++;
						s->a[s->top]=ele;
					}
					break;
			case 2:
					if(s->top==-1){
						printf("stack is eampty\n");
					}
					else{
						printf("%d\n",s->a[s->top]);
						s->top--;
					}
					break;
			case 3:
				    for(i=s->top;i>=0;i--){
				    	printf("%d\n",s->a[i]);
					}
					break;
			default:
				    printf("\ninvalid option\n");
				    
		}
	}while(op!=3);

}

