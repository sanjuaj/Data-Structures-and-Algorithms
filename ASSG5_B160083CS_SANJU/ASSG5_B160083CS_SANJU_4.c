#include<stdio.h>
#include<stdlib.h>
#include<limits.h>


struct Edge
{
	int start;
	int end;
	int weight;
};

struct Graph
{
	int vertex_set;
	int edge_set;
	struct Edge *edge;

};

struct Graph* make_graph(int v,int e);

int Check(struct Graph *graph,int start);

void main()
{
	int i,j;
	int edges,vertices;
	int res;
	scanf("%d %d\n",&vertices,&edges);
	struct Graph *graph=make_graph(vertices,edges);
	for(i=0;i<edges;i++)
	{
		scanf("%d %d %d",&graph->edge[i].start,&graph->edge[i].end,&graph->edge[i].weight);
	}
	res=Check(graph,0);
	printf("%d\n",res);
}

struct Graph* make_graph(int v,int e)
{
	struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));
	graph->vertex_set=v;
	graph->edge_set=e;
	graph->edge =(struct Edge*)malloc(e*sizeof(struct Edge));
	return graph;
}

int Check(struct Graph *graph,int start)
{
	int i,j;
	int v=graph->vertex_set;
	int e=graph->edge_set;
	int len[v];

	for(int i=1;i<v;i++)
	len[i]=INT_MAX;
	len[start]=0;

	for(i=1;i<=v-1;i++)
	{
		for(j=0;j<e;j++)
		{
		int start=graph->edge[j].start;
		int end=graph->edge[j].end;
		int wt=graph->edge[j].weight;
		if(len[start]!=INT_MAX && len[start] + wt < len[end])
			len[end]=len[start]+wt;
		}
	}


	for(i=0;i<e;i++)

	{
		int start=graph->edge[i].start;
		int end=graph->edge[i].end;
		int wt=graph->edge[i].weight;
		if(len[start]!=INT_MAX && len[start] + wt < len[end])
			return 1;
	}

	return -1;
}