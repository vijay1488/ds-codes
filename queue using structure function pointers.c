#include<stdio.h>
#include<stdlib.h>
struct queue{
	int *a;
	int front,rear;
	int n;
};
struct queue enqueue(struct queue *);
struct queue dequeue(struct queue *);
struct queue display(struct queue *);
void main(){
struct queue *q;
q=( struct queue *)malloc(sizeof(struct queue));
q->a=(struct queue *)malloc((q->n)*sizeof(struct queue));
q->front=-1;
q->rear=-1;
q->n=5;
int ele,i,op;
do{
	printf("1.enqueue , 2.dequeue , 3.display \nchoose option");
	scanf("%d",&op);
	switch(op){
		case 1:
				enqueue(q);
				break;
		case 2:
				dequeue(q);
				break;
		case 3:
				display(q);
				break;
		default:
				printf("invalid input \n");
        }
    }while(op!=3);
}
struct queue enqueue(struct queue *q){
	if(q->rear==(q->n)-1){
		printf("queue is full \n");
		}
	else{
	    int ele;
		printf("enter element \n");
		scanf("%d",&ele);
		q->rear++;
		q->a[q->rear]=ele;	
				}
}
struct queue dequeue(struct queue *q){
	if(q->front==q->rear){
		printf("queue is eampty \n");
	}
	else{
		q->front++;
		printf("%d",q->a[q->front]);
		}
}
struct queue display(struct queue *q){
    int i,rear;
		for(i=q->front+1;i<=rear;i++){
			printf("%d",q->a[i]);
		}
}
