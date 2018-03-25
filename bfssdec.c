#include<stdio.h>
#define MAX 20
int queue[MAX];
int a[MAX][MAX];  //Adjacency Matrix
int front=-1;
int rear=-1;
int visit[MAX];		//Keeps track of visited nodes
void enqueue(int a);
int delete();
int n;
void bfs(int a,int n);

int main()
{
int i,j,b;
printf("Enter no of nodes:");
scanf("%d",&n);

for(i=0;i<n;i++)
	visit[i]=0;

printf("Enter adjacency");
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		printf("is %d adjacent to %d",i,j);
		scanf("%d",&(a[i][j]));
	}
}

printf("Adjacency matrix is:");
for(i=0;i<n;i++)
{
	for(j=0;j<n;j++)
	{
		printf("%d",a[i][j]);
	}
printf("\n");
}


printf("\nEnter source");
scanf("%d",&b);

bfs(b,n);



}

void bfs(int a1,int n)
{
	int s,i;	
	enqueue(a1);
	visit[a1]=1;
	while(front!=-1)
	{
		s=delete();
		printf("%c",s+65);
		for(i=0;i<n;i++)
		{
			if(a[s][i] && visit[i]==0)
			{
				enqueue(i);
				visit[i]=1;
			}
		}
	}
}

void enqueue(int a)
{

	if(((front==0) && (rear==MAX-1)) || front==rear+1)
	{	printf("Overflow");
		return;
	}
	else if(front==-1)
	{
		front=0;
		rear=0;
	}
	else if(rear==MAX-1)
		rear=0;
	else
		rear++;

	queue[rear]=a;
}

int delete()
{
	int val;
	if(front==-1)
	{
		printf("Underflow");
		return -1;
	}
	
	val=queue[front];
	if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else if(front==MAX-1)
		front=0;
	else
		front++;
	return val;
}



		
	
