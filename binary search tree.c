#include<stdio.h>
#include<stdlib.h>

struct tnode 
{
	int data;
	struct tnode *left;
	struct tnode *right;
};
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
		struct tnode *temp=root;
		struct tnode *nn;
		nn=(struct tnode*)malloc(sizeof(struct tnode));
		nn->left=NULL;
		nn->right=NULL;
		nn->data=ele;
		while(1)
		{
			if(temp->data>ele)
			{
				if(temp->left!=NULL)
				{
					temp=temp->left;
				}
				else
				{
					temp->left=nn;
					break;
				}
			}
			else
			{
				
				if(temp->right!=NULL)
				{
					temp=temp->right;
				}
				else
				{
					temp->right=nn;
					break;
				}
			}
		}
	}
	return root;
}
struct tnode* find(struct tnode *root,int ele)
{
	struct tnode *temp=root;
	int flag=0;
	if(root==NULL)
	{
		printf("Tree is empty");
	}
	else
	{
		
		
		while(1)
		{
			if(temp->data==ele)
			{
				flag=1;
				break;
			}
			else if(temp->data>ele)
			{
				if(temp->left!=NULL)
				{
					temp=temp->left;
				}
				else
				{
					break;
				}
			}
			else
			{
				
				if(temp->right!=NULL)
				{
					temp=temp->right;
				}
				else
				{
					break;
				}
			}
		}
	}
	
	if(flag==1)
	{
		printf("element is FOUND\n");
		return temp;
	}
	else
	{
		printf("element is NOT found\n");
		return NULL;
		
	}
}
struct tnode* del(struct tnode *root,int ele)
{
	struct tnode *temp,*temp1,*parent,*p;
	temp1=find(root,ele);
	parent=temp1;
	if(temp1!=NULL)
	{
		if(temp1->right!=NULL)
		{
			temp=temp1->right;
		}
	}
	else
	{
		printf("cannot delete element\n");
	}
	while(temp->left!=NULL)
	{
		p=temp;
		temp=temp->left;
	}
	temp1->data=temp->data;
	p->left=temp->right;
	return root;
}
void inorder(struct tnode *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
}
void preorder(struct tnode* root)
{
	if(root!=NULL)
	{
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
} 
void postorder(struct tnode *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
}
int main()
{
	struct tnode *root=NULL,*temp;
	int op,ele;
	do
	{
		printf("1.Insert\n2.Find\n3.Delete\n4.inorder\n5.preorder\n6.Postorder\n7.Exit\n\n");
		printf("enter your choice:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("enter element you want to add:");
				scanf("%d",&ele);
				root=insert(root,ele);
				break;
			case 2:
				printf("enter the element you want to find:");
				scanf("%d",&ele);
				temp=find(root,ele);
				break;
			case 3:
				printf("enter the element you want to delete:");
				scanf("%d",&ele);
				root=del(root,ele);
				break;
			case 4:
				inorder(root);
				printf("\n\n");
				break;
			case 5:
				preorder(root);
				printf("\n\n");
				break;
			case 6:
				postorder(root);
				printf("\n\n");
				break;
			case 7:
				exit(0);
			default:
				printf("enter valid inputs");
				break;
		}
	}
	while(op!=7);
}
