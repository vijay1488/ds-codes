#include<stdio.h>
#include<stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;

void Enqueue() {
	struct Node* temp ; 
	temp=(struct Node*)malloc(sizeof(struct Node));
	printf("enter node data\n");
	scanf("%d",&temp->data);
	temp->next = NULL;
	if(front == NULL && rear == NULL){
		front = rear = temp;
		return;
	}
	rear->next = temp;
	rear = temp;
}

void Dequeue() {
	struct Node* temp = front;
	if(front == NULL) {
		printf("Queue is Empty\n");
		return;
	}
	if(front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	free(temp);
}

void display() {
		struct Node* temp = front;
		while(temp != NULL) {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main(){
	int opt; 
	printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
	do
	{
		printf("enter ur choice -->");
		scanf("%d",&opt);
		switch(opt)
		{
		case 1:
				Enqueue();
				break; 
		case 2:
				Dequeue();
				break;
		case 3:
				display();
				break;
		case 4:
				exit(0);
				break;
		default:
				printf("invalid option");
}
}while(opt!=4);
}
