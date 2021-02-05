#include<stdio.h>
#include<stdlib.h>
struct queue
{
	int q[20];
	int f;
	int r;
};
struct queue *s;
struct queue* enqueue(struct queue *s,int k)
{

    s->r++;
    s->q[s->r]=k;
    return s;
}
int isempty(struct queue *s)
{
    if(s->f==s->r)
        return 1;
    return 0;
}
int dequeue(struct queue *s)
{
    s->f++;
    return s->q[s->f];
}
void dfs(int k,int visit[],int a[20][20],int n)
{
	int j;
	if(visit[k]==0)
						{
							visit[k]=1;
							printf("%d\t",k);
							for(j=0;j<n;j++)
							{
								if(a[k][j]==1 && visit[j]==0)
								{
									dfs(j,visit,a,n);
								}
							}
						}
}
int main()
{
	int a[20][20],visit[20];
	int j=0,i=0,k=0,n,opt;

	s=(struct queue*)malloc(sizeof(struct queue));
	s->f=-1;
	s->r=-1;
	printf("enter size of matrix:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		visit[i]=0;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	
	do
	{
		printf("1.BFS\n2.DFS\n3.Exit\n");
		printf("enter your choice");
		scanf("%d",&opt);
		switch(opt)
		{
			case 1:
				{
					s=enqueue(s,0);
					while(!isempty(s))
					{
						k=dequeue(s);
						if(visit[k]==0)
						{
							visit[k]=1;
							printf("%d\t",k);
							for(j=0;j<n;j++)
							{
								if(a[k][j]==1)
								{
									s=enqueue(s,j);
								}
							}
						}
					}
					printf("\n");
					break;
				}
			case 2:
			{
					s=enqueue(s,0);
					for(i=0;i<n;i++)
					{
						visit[i]=0;
					}
					while(!isempty(s))
					{
						k=dequeue(s);
						dfs(k,visit,a,n);
					}
					printf("\n");
					break;
			}
			case 3:
			{
				exit(0);
			}
		}
	}
	while(opt!=3);
}
