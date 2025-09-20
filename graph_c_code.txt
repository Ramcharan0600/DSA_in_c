#include <stdio.h>
#include<stdlib.h>

struct node{
  int vertex;
  struct node*next;
};

struct Graph{
  int numVertex;
  struct node**adjList;
};

struct node*Createnode(int v){
  struct node*new_node = (struct node*)malloc(sizeof(struct node));
  new_node->vertex = v;
  new_node->next = NULL;
  return new_node;
}

struct Graph*Creategraph(int vertices){
  struct Graph*graph = (struct Graph*)malloc(sizeof(struct Graph));
  graph->numVertex = vertices;
  graph->adjList = (struct node**)malloc(vertices*sizeof(struct node*));
  for (int i=0;i<vertices;i++){
    graph->adjList[i] = NULL;
  }
  return graph;
}

void AddEdge(struct Graph*graph,int src,int dest){
  struct node*new_node = Createnode(dest);
  new_node->next = graph->adjList[src];
  graph->adjList[src] = new_node;
  
  
}
void Printgraph(struct Graph*graph){
  for (int i=0;i<graph->numVertex;i++){
    struct node*temp = graph->adjList[i];
    printf("Adjacency list of vertex %d: ",i);
    while(temp){
      printf("%d ->",temp->vertex);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

int main()
{
  int vertices = 5;
    struct Graph *graph = Creategraph(vertices);

    AddEdge(graph, 0, 1);
    AddEdge(graph, 0, 4);
    AddEdge(graph, 1, 2);
    AddEdge(graph, 1, 3);
    AddEdge(graph, 1, 4);
    AddEdge(graph, 2, 3);
    AddEdge(graph, 3, 4);

    Printgraph(graph);

    return 0;
}