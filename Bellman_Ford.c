#include<stdio.h>
#include<stdlib.h>

#define INF 999999
#define NIL -999999
int max = 5;
int d[5],pi[5];
void printpath(int i, int j);
void init(int g[max][max],int s);
int extract_min();
int min_heapify(int i);
void relux (int u,int v,int w[max][max]);
void decrease_key(int i, int key);
void bellman_ford(int g[max][max], int w[max][max],int s);
void display();


int q[max],d[max],pi[max],size,S[max],c, w[max][max];
void printpath(int i, int j)
{
	if(pi[i]==NIL)
	{
		printf("%d",j);
	}
	else
	{
		printpath(i,pi[j]);
		printf("->%d",j);
	}
}


void display(int w[max][max])
{
	int i,j,k;
	printf("the weight matrix..\n");
	for(i=0;i<max;i++)
	{
		for(j=0;j<max;j++)
		{
			if(w[i][j]!=INF)
				printf("%d",w[i][j]);
			else
				printf("INF");
		}
		printf("\n");
	}
	printf("\n the d list..\n");
	for(k=0;k<max;k++)
		printf("\nd[%d] : %d",k,d[k]);
	printf("\n the pi list..\n");
	for(k=0;k<max;k++)
	{
		if(pi[k]!=NIL)
			printf("\np[%d]:%d",k,pi[k]);
		else
			printf("npi[%d]:NIL",k);
	}
	printf("\n\n");
}

int main()
{
        int g[max][max]={{0,6,INF,7,INF},
                    		{INF,0,5,0,-4},
                             	{INF,-2,0,INF,INF},
                                {INF,INF,-3,0,9},
                                {2,INF,7,INF,0}};
        int status,i,source;
        source=0;
	status=bellman_ford(w,w,source);
	if(status)
		printf("bellman ford returned TRUE.. \n\n");
	else
		printf("bellma ford returned FALSE .. \n\n");

	display(w);
	for(i=0;i<max;i++)
	{
		printf("shortest path from %d to %d :",source,i);
		printpath(pi,i);
	}
	printf("\n")
}

/*
struct Edge{
        int
};

struct graph{
        int v;
        int e;
        struct Edge*edge;
};

*/


void init(int g[max][max],int s)
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
	if((r<+size)&&(q[r]<q[smallest]))
		smallest=r;
	if(smallest!=1)
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
		printf("heap underflow !!");
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


void relux (int u,int v,int w[max][max])
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


void bellman_ford(int g[max][max], int w[max][max],int s)
{
	int k,i,j;
	init_single_src(g,s);
	for(k=0;k<=max;k++)
	{
		for(i=0;i<max;i++)
		{
			for(j=0;j<max;j++)
			{
				relux(i,j,w);
			}
		}
	}
	for(i=0;i<max;i++)
	{
		for(j=0;j<max;j++)
		{
			if(d[i]>d[i]+w[i][j])
				return 0;
		}
	}
	return 1;
}

void relux (int u,int v,int w[max][max])
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
