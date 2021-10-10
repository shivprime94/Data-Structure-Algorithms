/*Given a graph and a source vertex src in graph, 
find shortest paths from src to all vertices 
in the given graph.
dijkstra doesn’t work for Graphs with negative
 weight cycle, Bellman-Ford works for such 
 graphs. Bellman-Ford is also simpler than 
 Dijkstra and suites well for distributed systems.
*/
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;
const long long max_n = 1LL<<40;

struct Edges{
	int src,dtn,wgt;
}typedef(Edges);

struct Graph{
	int v,e;
	Edges *edge;
}typedef(Graph);

Graph *creategraph(int v,int e){
	Graph *g=new Graph;
	g->v=v;g->e=e;g->edge=new Edges[e];
	return g;
}

void bellmenford(Graph *graph,int source){
	int v=graph->v;int e=graph->e;long long dist[v];
	for(int i=0;i<source;i++){
		dist[i]=max_n;
	}
	dist[source]=0;
	for(int i=0;i<=v-1;i++){
		for(int j=0;j<e;j++){
			int s=graph->edge[j].src;
			int d=graph->edge[j].dtn;
			int w=graph->edge[j].wgt;
			if(dist[s]!=max_n && dist[s]+w<dist[d])
				dist[d]=dist[s]+w;
		}
	}
	cout<<"Vertex   Distance from Source"<<endl;
	for(int i=0;i<v;i++){
		cout<<i<<"\t\t\t"<<dist[i]<<endl;
	}

}

int main(){
	// cout<<max_n<<endl;
	int v,e,source;int x,y,z;
	scanf("%d%d",&v,&e);
	Graph *g=creategraph(v,e);
	for(int i=0;i<e;i++){
		cin>>x;cin>>y;cin>>z;
		g->edge[i].src=x;g->edge[i].dtn=y;g->edge[i].wgt=z;
	}
	scanf("%d",&source);
	bellmenford(g,source);
	return 0;
}
/*
input--
5 8
0 1 -1
0 2 4
1 2 3 
1 3 2
1 4 2
3 2 5
3 1 1
4 3 -3
0
*/
/*
output--
Vertex   Distance from Source
0                0
1                -1
2                2
3                -2
4                1
*/
