#include <iostream>

void visit_node(int **&capacities, int start, int stop, bool & path_exists) {
	if (start == stop) {
		path_exists = true;
		return;
	}
	for (int i = 0; i <= stop; i++) {
		if (capacities[start][i] != 0) {
			visit_node(capacities, i, stop, path_exists);
		}
	}
}

bool dfs(int **& capacities, int nodes) {
	bool path_exists = false;
	visit_node(capacities, 0, nodes - 1, path_exists);
	return path_exists;
}





