#include<stdio.h>
#include<stdlib.h>
int main(){
	int a[5],front=-1,rear=-1,op,ele,i;
	do{		
	printf("1.enqueue,2.dequeue,3.display \n");
	printf("enter choice -->");
	scanf("%d",&op);
		switch(op){
			case 1:
						if(rear==4){
							printf("queue is full \n");
						}
						else{
							printf("enter element\n");
							scanf("%d",&ele);
							rear++;
							a[rear]=ele;
							}
					break;
			case 2:
						if(front==rear){
							printf("queue is eampty \n");
						}
						else{
							front++;
							printf("%d\n",a[front]);
						}
					break;
			case 3:
				        for(i=front+1;i<=rear;i++)
						{
						printf("%d\n",a[i]);
						}	
			default:
				    printf("invalid option\n");		    
					}
			}while(op!=3);
}

