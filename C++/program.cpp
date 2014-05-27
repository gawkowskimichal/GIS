#include <stdlib.h>
#include <iostream>
#include "read_data.h"
#include "dfs.h"

using namespace std;

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define INFINITE 10000000

int nodes;

void push(const int * const * C, int ** F, int *excess, int u, int v) {
  int send = MIN(excess[u], C[u][v] - F[u][v]);
  F[u][v] += send;
  F[v][u] -= send;
  excess[u] -= send;
  excess[v] += send;
}

void relabel(const int * const * C, const int * const * F, int *height, int u) {
  int v;
  int min_height = INFINITE;
  for (v = 0; v < nodes; v++) {
    if (C[u][v] - F[u][v] > 0) {
      min_height = MIN(min_height, height[v]);
      height[u] = min_height + 1;
    }
  }
};

void discharge(const int * const * C, int ** F, int *excess, int *height, int *seen, int u) {
  while (excess[u] > 0) {
    if (seen[u] < nodes) {
      int v = seen[u];
      if ((C[u][v] - F[u][v] > 0) && (height[u] > height[v])){
    push(C, F, excess, u, v);
      }
      else
    seen[u] += 1;
    } else {
      relabel(C, F, height, u);
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

int pushRelabel(const int * const * C, int ** F, int source, int sink) {
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
     discharge(C, F, excess, height, seen, u);
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

 void printMatrix(const int * const * M) {
   int i,j;
   for (i = 0; i < nodes; i++) {
     for (j = 0; j < nodes; j++)
       cout << M[i][j] << "\t";
     cout << endl;
   }
 }

 int main(int argc, char *argv[]) {
	 if (argc != 3) {
		 cout << "Program uruchomiony z niepoprawną liczbą argumentów." << endl;
		 cout << "Poprawne wywołanie 'GIS ścieżka_do_pliku flaga'" << endl;
		 return 0;
	 }
	 int **flow, **capacities;
	 read_data(flow, capacities, nodes, argv[1]);
	 bool path_exists = dfs(capacities, nodes);
	 if (path_exists) {
	   	cout << "Ścieżka istnieje" << endl;
	 }
	 else {
	   	cout << "Ścieżka nie istnieje" << endl;
	   	return 0;
	 }


   cout << "Capacity:" << endl;
   printMatrix(capacities);



   cout << "Max Flow:" << endl << pushRelabel(capacities, flow, 0, 10) << endl;

   cout << "Flows:" << endl;
   printMatrix(flow);

   return 0;
 }
