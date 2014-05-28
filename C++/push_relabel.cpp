#include <stdlib.h>

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define INFINITE 10000000

void push(const int * const * C, int ** F, int *excess, int u, int v);

void relabel(const int * const * C, const int * const * F, int *height, int u, int nodes) {
  int v;
  int min_height = INFINITE;
  for (v = 0; v < nodes; v++) {
    if (C[u][v] - F[u][v] > 0) {
      min_height = MIN(min_height, height[v]);
      height[u] = min_height + 1;
    }
  }
}

void discharge(const int * const * C, int ** F, int *excess, int *height, int *seen, int u, int nodes) {
  while (excess[u] > 0) {
    if (seen[u] < nodes) {
      int v = seen[u];
      if ((C[u][v] - F[u][v] > 0) && (height[u] > height[v])){
    push(C, F, excess, u, v);
      }
      else
    seen[u] += 1;
    } else {
      relabel(C, F, height, u, nodes);
      seen[u] = 0;
    }
  }
}

void moveToFront(int i, int *A) {
  int temp = A[i];
  int n;
  for (n = i; n > 0; n--){
    A[n] = A[n-1];
  }
  A[0] = temp;
}

int pushRelabel(const int * const * C, int ** F, int source, int sink, int nodes) {
  int *excess, *height, *list, *seen, i, p;

  excess = (int *) calloc(nodes, sizeof(int));
  height = (int *) calloc(nodes, sizeof(int));
  seen = (int *) calloc(nodes, sizeof(int));

  list = (int *) calloc((nodes-2), sizeof(int));

  for (i = 0, p = 0; i < nodes; i++){
    if((i != source) && (i != sink)) {
      list[p] = i;
      p++;
    }
  }

  height[source] = nodes;
  excess[source] = INFINITE;
  for (i = 0; i < nodes; i++)
    push(C, F, excess, source, i);
  p = 0;
   while (p < nodes - 2) {
     int u = list[p];
     int old_height = height[u];
     discharge(C, F, excess, height, seen, u, nodes);
     if (height[u] > old_height) {
       moveToFront(p,list);
       p=0;
     }
     else
       p += 1;
   }
   int maxflow = 0;
   for (i = 0; i < nodes; i++)
     maxflow += F[source][i];

   free(list);

   free(seen);
   free(height);
   free(excess);

   return maxflow;
 }
