#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))

//operacja push - ustawia maksymalną wartość przedprzepływu
//na krawędzi wychodzącej z wierzchołka u i wchodzącej do wierzchołka v
void push(const int * const * C, int ** F, int *excess, int u, int v) {
  int send = MIN(excess[u], C[u][v] - F[u][v]);
  F[u][v] += send;
  F[v][u] -= send;
  excess[u] -= send;
  excess[v] += send;
}




