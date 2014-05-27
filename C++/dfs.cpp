#include <iostream>

void visit_node(int **&capacities, int * visited_vertices, int start, int stop, bool & path_exists) {
	//std::cout << "odwiedzany wierzchołek " << start << std::endl;
	//std::cout << "stop: " << stop << std::endl;
	if (start == stop) {
		path_exists = true;
		//std::cout << "test" << std::endl;
		return;
	}
	visited_vertices[start] = 1;
	for (int i = 0; i <= stop; i++) {
		//std::cout << start << "," << i << ":" << capacities[start][i] << std::endl;
		//std::cout << "visited_vertices[" << i << "]:" << visited_vertices[i] << std::endl;
		//std::cout << "odwiedzam wierzchołek " << i << "idę z " << start << std::endl;
		if (capacities[start][i] != 0 && visited_vertices[i] == 0) {
			//std::cout << capacities[start][i] << std::endl;
			//std::cout << "odwiedzam wierzchołek " << i << " idę z " << start << std::endl;
			visit_node(capacities, visited_vertices, i, stop, path_exists);
		}
	}
	visited_vertices[start] = 2;
}

bool dfs(int **& capacities, int nodes) {
	int visited_vertices[nodes];
	for (int i = 0; i < nodes; i++) {
		visited_vertices[i] = 0;
	}
	bool path_exists = false;
	visit_node(capacities, visited_vertices, 0, nodes - 1, path_exists);
	return path_exists;
}





