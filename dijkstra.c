#include<stdio.h>
#include<stdlib.h>

#define INF 999999
#define NIL -999999
#define max 5

int q[max+1],d[max+1],pi[max+1],size,S[max+1],c;
void printpath(int i, int j)
{
	if(pi[j]=NIL)
	{
		printf("%d",j);
	}
	else
	{
		printpath(i,pi[j]);
		printf("->%d",j);
	}
}


void display()
{
	int i;
	printf("The d list..\n");
	for(i=1;i<=max;i++)
	{

		printf("\n d[%d]:%d",i,d[i]);
	}
printf("\n The predecesor list..\n");
	for(i=1;i<=max;i++)
	{
		if(pi[i]!=NIL)
			printf("\n pi[%d]:%d",i,pi[i]);
		else
			printf("n pi[%d]:NIL",i);
	}
	printf("\n\n");
}

void init(int g[max+1][max+1],int s)
{
	int v;
	for(v=1;v<=max;v++)
	{
		d[v]=INF;
		pi[v]=NIL;
	}
	d[s]=0;
}


int min_heapify(int i)
{
	int l,r,smallest,temp;

	l=2*i;
	r= l+1;

	if((l<=size)&&(q[l]<q[i]))
		smallest=l;
	else
		smallest=i;
	if((r<=size)&&(q[r]<q[smallest]))
		smallest=r;
	if(smallest!=i)
	{
		temp=q[i];
		q[i]=q[smallest];
		q[smallest]=temp;
		min_heapify(smallest);
	}
}


int extract_min()
{
	int min,loc;
	if(size<1)
		printf("\nHeap underflow !!\n");
	min=q[1];
	q[1]=q[size];
	-- size;
	min_heapify(1);
	return(min);
}



void decrease_key(int i, int key)
{
        int temp,parent;
        q[i]=key;
        parent=i/2;
        while((i>1)&&(q[parent]>q[i]))
        {
                temp=q[parent];
                q[parent]=q[i];
                q[i]=temp;
                i=parent;
        }
}


void relax (int u,int v,int w[max+1][max+1])
{

	int key,i;
	key=d[u]+w[u][v];
	if(d[v]>key)
	{
		d[v]=key;
		pi[v]=u;
	}
	i=v;
	decrease_key(i,key);
}


void dijkstra(int g[max+1][max+1], int w[max+1][max+1],int s)
{
	int i,u,v,loc;
	c=0;
	init(w,s);
	for(i=1;i<=max;i++)
	{
		S[i]=NIL;
		q[i]=d[i];
	}
	while(size!=0)
	{
		u=extract_min();

		for(i=1;i<=max;i++)
		{
			if(d[i]==u)
			{
				S[++c]=i;
				break;
			}
		}
		for(v=1;v<=max;v++)
		{
			if((g[i][v]>0)&&(g[i][v]<INF))
			{
				relax(i,v,w);
			}
		}
	}
}



int main()
{
	int g[max+1][max+1]={{0,0,0,0,0,0},
				{0,0,10,INF,5,INF},
				{0,INF,0,1,2,INF},
				{0,INF,INF,0,INF,4},
				{0,INF,3,9,0,2},
				{0,7,INF,6,INF,0}};
	int i,s;
	size=5;
	s=1;
	dijkstra(g,g,s);
	display();
	for(i=1;i<=max;i++)
	{
		printf("\n The Shortest path from %d to %d: \n",s,i);
		printpath(s,i);
		printf("\n");
	}

}
