#include<stdio.h>
#include<stdlib.h>
int enqueue(int*,int,int);
int dequeue(int*,int,int);
int display(int*,int,int);
int main(){
	int a[5],front=-1,rear=-1,op,ele,i;
	do{		
	printf("1.enqueue,2.dequeue,3.display \n");
	printf("enter choice -->");
	scanf("%d",&op);
		switch(op){
			case 1:
					rear=enqueue(&a,rear,front);
					break;
			case 2:
					front=dequeue(&a,rear,front);
					break;
			case 3:
				    display(&a,rear,front);
			default:
				    printf("invalid option\n");
				    
		}
	}while(op!=3);
}
int enqueue(int *a,int rear,int front){
	if(rear==4){
		printf("queue is full \n");
	}
	else{
	    int ele;
			printf("enter element\n");
				scanf("%d",&ele);
				rear++;
				a[rear]=ele;
	}
			return rear;
}
int dequeue(int *a,int rear,int front){
	if(front==rear){
		printf("queue is eampty \n");
	}
	else{
			front++;
			printf("%d\n",a[front]);
	}
	     return front;
}
int display(int*a,int rear,int front){
    int i;
	for(i=front+1;i<=rear;i++){
		printf("%d\n",a[i]);
	}
}
