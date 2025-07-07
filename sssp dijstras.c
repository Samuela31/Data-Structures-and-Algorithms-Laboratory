#include <stdio.h>
#define INFINITY 9999
#define MAX 9


void Dijkstra(int G[MAX][MAX], int n, int src) {
  int cost[MAX][MAX], d[MAX], pred[MAX];
  int color[MAX], cnt, mindistance, cur, i, j;

  // Creating cost matrix
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      if (G[i][j] == 0)
        cost[i][j] = INFINITY;
      else
        cost[i][j] = G[i][j];

  for (i = 0; i < n; i++) {
    d[i] = cost[src][i];
    pred[i] = src;
    color[i] = 0;
  }

  d[src] = 0;
  color[src] = 1;
  cnt = 0;

  while (cnt < n) {
    mindistance = INFINITY;

    for (i = 0; i < n; i++)
      if (d[i] < mindistance && !color[i]) {
        mindistance = d[i];
        cur = i;
      }

    color[cur] = 1;
    for (i = 0; i < n; i++)
      if (!color[i] && (mindistance + cost[cur][i] < d[i])) {
          d[i] = mindistance + cost[cur][i];
          pred[i] = cur;
        }
    cnt++;
  }

  // Printing the distance
  for (i = 0; i < n; i++)
    if (i != src) {
      printf("\nDistance from source %d to %d: %d",src, i, d[i]);
    }
}
int main() {
  int i, j;
  int Graph[MAX][MAX] = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

  Dijkstra(Graph, 9, 0);

  return 0;
}
