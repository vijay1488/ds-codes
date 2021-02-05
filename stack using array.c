#include<stdio.h>
#define n 5
void main(){
	int a[n],top=-1,op,ele,i;

	
	do{
			
	printf("1.push\n2.pop\n3.display \n");
	printf("enter choice\n");
	scanf("%d",&op);
		switch(op){
			case 1:
				    if(top==n-1){
				    	printf("stack is full\n");	    	
					}
					else{
							printf("enter element\n");
						scanf("%d",&ele);
						top++;
						a[top]=ele;
					}
					break;
			case 2:
					if(top==-1){
						printf("stack is eampty\n");
					}
					else{
						printf("%d\n",a[top]);
						top--;
					}
					break;
			case 3:
				    for(i=top;i>=0;i--){
				    	printf("%d ",a[i]);
					}
					break;
			default:
				    printf("invalid option\n");
				    
		}
	}while(op!=3);

}
