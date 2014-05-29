#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

//funkcja odczytująca z pliku tekstowego dane opisujące
//sieć, w której wyznaczany będzie maksymalny przepływ
void readData(int **& flow, int **& capacities, int & nodes, char * file) {
	string line;
	ifstream inputFile(file);
	if (inputFile.is_open()) {
		while (getline(inputFile,line)) {
			int pos = line.find(' ');
			int initialPos = 0;
			vector<string> splitLine;
			while (pos != string::npos) {
				splitLine.push_back(line.substr(initialPos, pos - initialPos));
				initialPos = pos + 1;
				pos = line.find(' ', initialPos);
			}
			splitLine.push_back(line.substr(initialPos));
			if (splitLine[0].compare("c") == 0) {
				continue;
			}
			else if (splitLine[0] == "p") {
				nodes = atoi(splitLine[2].c_str());
				flow = (int **) calloc(nodes, sizeof(int*)); //macierz wymiarów NxN,
															//zwierająca przepływy między poszczególnymi wierzchołkami
				capacities = (int **) calloc(nodes, sizeof(int*)); //macierz wymiarów NxN, zawierająca przepustowości
																	//gałęzi między poszczególnymi wierzchołkami
					   for (int i = 0; i < nodes; i++) {
					     flow[i] = (int *) calloc(nodes, sizeof(int));
					     capacities[i] = (int *) calloc(nodes, sizeof(int));
					   }
			}
			else if (splitLine[0] == "n") {

			}
			else if (splitLine[0] == "a") {
				capacities[atoi(splitLine[1].c_str()) - 1][atoi(splitLine[2].c_str()) - 1] = atoi(splitLine[3].c_str());
			}
			else {
				cout << "Niepoprawny format pliku wejściowego." << endl;
				exit(0);
			}
		}
	}
	else {
		cout << "Nie można otworzyć pliku " << file << endl;
		exit(0);
	}
}
