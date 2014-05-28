#include <iostream>

using namespace std;

bool dfs(int **& capacities, int nodes);
void readData(int **& flow, int **& capacities, int & nodes, char * file);
int pushRelabelHighestLabel(const int * const * C, int ** F, int source, int sink, int nodes);
int pushRelabel(const int * const * C, int ** F, int source, int sink, int nodes);

void printMatrix(const int * const * M, int nodes) {
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
	 int **flow, **capacities, nodes;
	 char * option, *file;
	 file = argv[1];
	 option = argv[2];
	 readData(flow, capacities, nodes, file);
	 bool path_exists = dfs(capacities, nodes);
	 if (path_exists) {
	   	cout << "W zadanym grafie istnieje ścieżka łącząca źródło i ujście." << endl;
	 }
	 else {
	   	cout << "W zadanym grafie nie istnieje ścieżka łącząca źródło i ujście." << endl;
	   	return 0;
	 }

	 cout << "Capacity:" << endl;
	 printMatrix(capacities, nodes);

	 if (*option == '1') {
		 cout << "Podstawowa wersja algorytmu 'push-relabel'" << endl;
		 cout << "Max Flow:" << endl << pushRelabel(capacities, flow, 0, nodes - 1, nodes) << endl;
	 }
	 else {
		 cout << "Wersja algorytmu 'push-relabel', gdzie zastosowano regułę 'highest label selection rule'" << endl;
		 cout << "Max Flow:" << endl << pushRelabelHighestLabel(capacities, flow, 0, nodes - 1, nodes) << endl;
	 }

	 cout << "Flows:" << endl;
	 printMatrix(flow, nodes);

	 return 0;
 }
