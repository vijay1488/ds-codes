#include<stdio.h>
#include<stdlib.h>
struct queue{
	int a[5];
	int front,rear;
	int n;
};
int main(){
	struct queue q;
	int a[5];
	q.front=-1;
	q.rear=-1;
	q.n=5;
	int ele,i,op;
	do{		
	printf("1.enqueue,2.dequeue,3.display \n");
	printf("enter choice\n");
	scanf("%d",&op);
		switch(op){
			case 1:
						if(q.rear==4){
							printf("queue is full \n");
						}
						else{
							printf("enter element\n");
							scanf("%d",&ele);
							q.rear++;
							a[q.rear]=ele;
							}
					break;
			case 2:
						if(q.front==q.rear){
							printf("queue is eampty \n");
						}
						else{
							q.front++;
							printf("%d\n",a[q.front]);
						}
					break;
			case 3:
				        for(i=q.front+1;i<=q.rear;i++){
						printf("%d\n",a[i]);
						}	
					break;
			default:
				    printf("invalid option\n");		    
					}
			}while(op!=3);
}

