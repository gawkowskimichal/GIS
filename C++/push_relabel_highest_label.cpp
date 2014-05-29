#include <stdlib.h>

#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))
#define INFINITE 10000000

void push(const int * const * C, int ** F, int *excess, int u, int v);

//operacja relabel w wersij algorytmu z wyborem wierzchołka aktywnego
//dodatkowo odpowiada za wybór wierzchołka aktywnego o najwyższej etykiecie
void relabelHighestLabel(const int * const * C, const int * const * F, int *height, int u, int nodes, int * excess, int & highestLabelIndex) {
  int v;
  int min_height = INFINITE;
  for (v = 0; v < nodes; v++) {
    if (C[u][v] - F[u][v] > 0) {
      min_height = MIN(min_height, height[v]);
      height[u] = min_height + 1;
      if (height[highestLabelIndex] < height[u] && excess[u] > 0) {
    	  highestLabelIndex = u;
      }
    }
  }
}

//operacja discharge - modyfikuje wierzchołek aktywny aplikujac na nim operacje push i relabel
//aż do momentu, gdy stanie się on nieaktywny
void dischargeHighestLabel(const int * const * C, int ** F, int *excess, int *height, int *seen, int u, int nodes, int & highestLabelIndex) {
	while (excess[u] > 0) {
    if (seen[u] < nodes) {
      int v = seen[u];
      if ((C[u][v] - F[u][v] > 0) && (height[u] > height[v])){
    push(C, F, excess, u, v);
      }
      else
    seen[u] += 1;
    } else {
      relabelHighestLabel(C, F, height, u, nodes, excess, highestLabelIndex);
      seen[u] = 0;
    }
  }
}

//algorytm push-relabel w wersji z wyborem wierzchołka aktywnego o najwyższej etykiecie
int pushRelabelHighestLabel(const int * const * C, int ** F, int source, int sink, int nodes) {
	int *excess, *height, *list, *seen, i, p;
	excess = (int *) calloc(nodes, sizeof(int)); //wektor zawierający informację
  	  	  	  	  	  	  	  	  	  	  	  	  //o aktualnym stanie nasycenia wierzchołka
	height = (int *) calloc(nodes, sizeof(int)); //wektor zawierający oznaczenia ‘wysokości’ wierzchołków
	seen = (int *) calloc(nodes, sizeof(int)); //wektor kontrolujący liczbę prób przesunięcia
  	  	  	  	  	  	  	  	  	  	  	  //przepływu do sąsiednich wierzchołków
	list = (int *) calloc((nodes-2), sizeof(int)); //wektor indeksów wierzchołków zawierający
	  	  	  	  	  	  	  	  	  	  	  	  //wszystkie indeksy, poza indeksami źródła i ujścia
	int highestLabelIndex = 1;

	for (i = 0, p = 0; i < nodes; i++) {
		if((i != source) && (i != sink)) {
			list[p] = i;
			p++;
		}
	}
	height[source] = nodes;
	excess[source] = INFINITE;
	for (i = 0; i < nodes; i++) {
		push(C, F, excess, source, i);
	}
	bool activeNodes = true;
	while (activeNodes) {
		activeNodes = false;
		for (i = 1; i < nodes - 1; i++) {
			if (excess[i] > 0) {
				activeNodes = true;
			}
		}
		if (excess[highestLabelIndex] <= 0) {
			highestLabelIndex = nodes - 1;
			for (int j = nodes - 2; j >= 1; j--) {
				if (excess[j] > 0 && height[j] >= height[highestLabelIndex]) {
					highestLabelIndex = j;
				}
			}
		}
		int u = highestLabelIndex;
		dischargeHighestLabel(C, F, excess, height, seen, u, nodes, highestLabelIndex);
	}
	int maxFlow = 0;
	for (i = 0; i < nodes; i++) {
		maxFlow = maxFlow + F[source][i];
	}
	free(list);
	free(seen);
	free(height);
	free(excess);

	return maxFlow;
}



