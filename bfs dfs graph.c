#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};

struct graph {
  int numVertices;
  struct node** adjLists;
  int* color;
};

// Creating a node
struct node* createNode(int val) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = val;
  newNode->next = NULL;
  return newNode;
}

// Creating a graph
struct graph* createGraph(int vertices) {
  struct graph* g = malloc(sizeof(struct graph));
  g->numVertices = vertices;

  g->adjLists = malloc(vertices * sizeof(struct node*));
  g->color = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    g->adjLists[i] = NULL;
    g->color[i] = 0;
  }

  return g;
}

// Add edge
void addEdge(struct graph* g, int src, int dest) {
  // Add edge from src to dest
  struct node* newNode = createNode(dest);
  newNode->next = g->adjLists[src];
  g->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = createNode(src);
  newNode->next = g->adjLists[dest];
  g->adjLists[dest] = newNode;

}

// BFS algorithm
void bfs(struct graph* g, int src) {
  int q[100], front=-1, rear=-1;

  g->color[src] = 1;
  rear++; q[rear]=src;

  while (rear!=front) {
    /*for (int i = front+1; i <=rear ; i++) {
      printf("%d ", q[i]);
    }*/
    front++;
    int currentVertex = q[front];
    printf("%d ", currentVertex);

    struct node* temp = g->adjLists[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (g->color[adjVertex] == 0) {
        g->color[adjVertex] = 1;
        rear++; q[rear] =adjVertex;
      }
      temp = temp->next;
    }
  }
}

// DFS algo
void dfs(struct graph* g, int src) {
  int s[100], top=-1;

  g->color[src] = 1;
  top++; s[top]=src;

  while (top!=-1) {
    int currentVertex = s[top]; top--;
    printf("%d ", currentVertex);

    struct node* temp = g->adjLists[currentVertex];

    while (temp) {
      int adjVertex = temp->vertex;

      if (g->color[adjVertex] == 0) {
        g->color[adjVertex] = 1;
        top++; s[top] =adjVertex;
      }
      temp = temp->next;
    }
  }
}

int main() {
  struct graph* graph = createGraph(9);
  addEdge(graph, 1, 2);
  addEdge(graph, 1, 5);
  addEdge(graph, 2, 5);
  addEdge(graph, 2, 3);
  addEdge(graph, 5, 6);
  addEdge(graph, 3, 4);
  addEdge(graph, 3, 6);
  addEdge(graph, 6, 4);
  addEdge(graph, 4, 7);

  printf("BFS: ");
  bfs(graph, 1);

  printf("\nDFS: ");

  struct graph* g = createGraph(9);
  addEdge(g, 1, 2);
  addEdge(g, 1, 6);
  addEdge(g, 2, 6);
  addEdge(g, 2, 3);
  addEdge(g, 6, 7);
  addEdge(g, 3, 4);
  addEdge(g, 4, 5);
  addEdge(g, 7, 4);
  addEdge(g, 7, 8);

  dfs(g, 1);

  return 0;
}
