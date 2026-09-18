#include<stdio.h>
#include<stdlib.h>
#define MAX_VERTICES 100
struct Node{
	int vertex;
	struct Node* next;
};
struct Graph{
	struct Node* adjLists[MAX_VERTICES];
	int visited[MAX_VERTICES];
};
struct Node* createNode(int v){
	struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
	newNode->vertex=v;
	newNode->next=NULL;
	return newNode;
}
struct Graph* createGraph(){
	struct Graph* graph=(struct Graph*)malloc(sizeof(struct Graph));
	int i;
	for(i=0;i<MAX_VERTICES;i++){
	    graph->adjLists[i]=NULL;
	    graph->visited[i]=0;
	}
	return graph;
}
void addEdges(struct Graph* graph,int src,int dest){
	struct Node* newNode=createNode(dest);
	newNode->next=graph->adjLists[src];
	graph->adjLists[src]=newNode;
	newNode=createNode(src);
	newNode->next=graph->adjLists[dest];
	graph->adjLists[dest]=newNode;
}
void printGraph(struct Graph* graph){
	int v;
	for(v=0;v<MAX_VERTICES;v++){
	    if(graph->adjLists[v]!=NULL){
	       struct Node* temp=graph->adjLists[v];
	       printf("Adjacency list of vertex %d:",v);
	       while(temp){
	            printf("%d->",temp->vertex);
	            temp=temp->next;
	       }
	       printf("NULL\n");
	    }
	}
}
void DFS(struct Graph* graph,int startVertex){
	struct Node* adjList=graph->adjLists[startVertex];
	struct Node* temp=adjList;
	graph->visited[startVertex]=1;
	printf("Visited %d\n",startVertex);
	while(temp!=NULL){
	     int connectedVertex=temp->vertex;
	     if(graph->visited[connectedVertex]==0){
	        DFS(graph,connectedVertex);
	     }
	     temp=temp->next;
	}
}
int main(){
	struct Graph* graph=createGraph();
	addEdges(graph,0,1);
	addEdges(graph,0,2);
	addEdges(graph,1,2);
	addEdges(graph,1,3);
	addEdges(graph,2,3);
	printf("Graph:\n");
	printGraph(graph);
	printf("\nDFS Traversal starting from vertex 0:\n");
	DFS(graph,0);
	return 0;
}
	

