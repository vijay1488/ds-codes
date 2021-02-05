#include<stdio.h>
struct stack{
	int a;
	int top;
	int n;
};
void main(){
	struct stack s;
	int a[5];
	s.top=-1;
	s.n=5;
	int ele,i,op;

	do{
			
	printf("1.push,2.pop,3.exit \n");
	printf("enter choice -->");
	scanf("%d",&op);
		switch(op){
			case 1:
				    if(s.top==s.n-1){
				    	printf("stack is full\n");	    	
					}
					else{
							printf("enter element\n");
						scanf("%d",&ele);
						s.top++;
						a[s.top]=ele;
					}
					break;
			case 2:
					if(s.top==-1){
						printf("stack is eampty\n");
					}
					else{
						printf("%d\n",a[s.top]);
						s.top--;
					}
					break;
			case 3:
				    for(i=s.top;i>=0;i--){
				    	printf("%d\n",a[i]);
					}
					break;
			default:
				    printf("\ninvalid option\n");		    
		}
		
	}while(op!=3);

}

