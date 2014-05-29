#include <iostream>
#include <fstream>
#include <sys/time.h>

using namespace std;

bool dfs(int **& capacities, int nodes);
void readData(int **& flow, int **& capacities, int & nodes, char * file);
int pushRelabelHighestLabel(const int * const * C, int ** F, int source, int sink, int nodes);
int pushRelabel(const int * const * C, int ** F, int source, int sink, int nodes);

//funkcja wypisując na standardowe wyjście macierze: przepustowości i przepływów
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

	 //cout << "Przepustowości:" << endl;
	 //printMatrix(capacities, nodes);
	 int maxFlow;
	 struct timeval time;
	 double startTime, endTime, executionTime;
	 if (*option == '1') {
		 cout << "Podstawowa wersja algorytmu 'push-relabel'." << endl;
		 gettimeofday(&time, NULL);
		 startTime = time.tv_sec * 1000.0 + time.tv_usec / 1000.0;
		 maxFlow = pushRelabel(capacities, flow, 0, nodes - 1, nodes);
		 gettimeofday(&time, NULL);
		 endTime = time.tv_sec * 1000.0 + time.tv_usec / 1000.0;
	 }
	 else {
		 cout << "Wersja algorytmu 'push-relabel', gdzie zastosowano regułę 'highest label selection rule'." << endl;
		 gettimeofday(&time, NULL);
		 startTime = time.tv_sec * 1000.0+ time.tv_usec/1000.0;
		 maxFlow = pushRelabelHighestLabel(capacities, flow, 0, nodes - 1, nodes);
		 gettimeofday(&time, NULL);
		 endTime = time.tv_sec * 1000.0 + time.tv_usec / 1000.0;
	 }
	 executionTime = endTime - startTime;

	 //cout << "Przepływy:" << endl;
	 //printMatrix(flow, nodes);

	 ofstream outputFile;
	 outputFile.open("results.txt", std::ios_base::app);
	 outputFile << "Option: " << *option << endl;
	 outputFile << "Maksymalny przepływ:" << endl << maxFlow << endl;
	 outputFile << "Wykonanie algorytmu zajęło " << executionTime << " milisekund." << endl << endl;
	 outputFile.close();

	 cout << "Maksymalny przepływ:" << endl << maxFlow << endl;
	 cout << "Wykonanie algorytmu zajęło " << executionTime << " milisekund." << endl;

	 return 0;
 }
