#include<stdio.h>
#include<stdlib.h>
struct tnode
{
	struct tnode *left;
	int data;
	struct tnode *right;
};
struct queue
{
	int f,r;
	struct tnode *a[20];
};
struct queue *q;
struct queue* enqueue(struct queue *q,struct tnode *ele)
{
	q->r++;
	q->a[q->r]=ele;
	return q;
}
struct tnode* dequeue(struct queue *q)
{
	q->f++;
	return q->a[q->f];
}
int isempty(struct queue *q)
{
	if(q->f==q->r)
		return 1;
	else
		return 0;
}
struct tnode* insert(struct tnode *root,int ele)
{
	if(root==NULL)
	{
		root=(struct tnode*)malloc(sizeof(struct tnode));
		root->data=ele;
		root->left=NULL;
		root->right=NULL;
	}
	else
	{

		struct tnode *temp,*temp1;
		temp=(struct tnode*)malloc(sizeof(struct tnode));
		temp->data=ele;
		temp->right=NULL;
		temp->left=NULL;

		q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		while(!isempty(q))
		{

			temp1=dequeue(q);
			if(temp1->left!=NULL)
			{
				q=enqueue(q,temp1->left);
			}
			else
				break;
			if(temp1->right!=NULL)
			{
				q=enqueue(q,temp1->right);
			}
			else
				break;

		}
		if(temp1->left==NULL){

			temp1->left=temp;
			}
		else{

			temp1->right=temp;
			}

	}
	return root;
}
void print(struct tnode *root)
{
	if(root==NULL)
	{
		printf("Tree is empty");
	}
	else
	{
		struct tnode *temp1;

		q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		while(!isempty(q))
		{
			temp1=dequeue(q);
			if(temp1->left!=NULL)
			{
				q=enqueue(q,temp1->left);
			}

			if(temp1->right!=NULL)
			{
				q=enqueue(q,temp1->right);
			}
			printf("%d\t",temp1->data);
	}
	printf("\n");
}
}
struct tnode* find_ele(struct tnode *root,int ele)
{
	struct tnode *temp1;
	q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		while(!isempty(q))
		{
			temp1=dequeue(q);
			if(temp1->left!=NULL)
			{
				q=enqueue(q,temp1->left);
			}
			if(temp1->right!=NULL)
			{
				q=enqueue(q,temp1->left);
			}
			if(temp1->data==ele)
			{
				return temp1;
			}
		}
}
struct tnode* findLast(struct tnode *root)
{
	struct tnode *temp2;
	q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
			q=enqueue(q,root);
		while(!isempty(q))
		{
			temp2=dequeue(q);
			if(temp2->left!=NULL)
			{
				q=enqueue(q,temp2->left);
			}

			if(temp2->right!=NULL)
			{
				q=enqueue(q,temp2->right);
			}
	}
	return temp2;
}
struct tnode* findparent(struct tnode *root,struct tnode *temp)
{
	struct tnode *p;
	q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		while(!isempty(q))
		{
			p=dequeue(q);

			if(p->left==temp)
			{
				return p;
			}
			else
			{
				if(p->left!=NULL)
				{
					q=enqueue(q,p->left);
				}

			}
			if(p->right==temp)
			{
				return p;
			}
			else
			{
				if(p->right!=NULL)
				{
					q=enqueue(q,p->right);
				}
			}
	}
}
int del(struct tnode *root)
{
    struct tnode *temp1,*temp2;
	if(root==NULL)
	{
		printf("element cannot be removed");
	}
	else
	{
		int ele;
		struct tnode *temp;
		printf("what element you want to delete:");
		scanf("%d",&ele);
		q=(struct queue*)malloc(sizeof(struct queue));
		q->r=-1;
		q->f=-1;
		q=enqueue(q,root);
		temp1=find_ele(root,ele);
		temp2=findLast(root);
		temp=findparent(root,temp2);
		temp1->data=temp2->data;
		if(temp->left==temp2)
			temp->left=NULL;
		else
			temp->right=NULL;
	}
}

int main()
{
	struct tnode *root=NULL;
	int op,ele;
	do
	{
		printf("1.Insert\n2.Print\n3.Exit\n");
        printf("enter your choice:");
        scanf("%d",&op);
        switch(op)
        {
        case 1:
            {
                printf("enter the element to be added:");
                scanf("%d",&ele);
                root=insert(root,ele);
                break;
            }
        case 2:
            {
                print(root);
                break;
            }
        case 3:
            {
            	del(root);
				break;
			}
        case 4:
            {
                exit(0);
            }
        default:
            printf("enter valid input");
        }
	}
	while(op!=4);
	return 0;
}
