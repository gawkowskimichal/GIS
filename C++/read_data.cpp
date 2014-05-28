#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void readData(int **& flow, int **& capacities, int & nodes, char * file) {
	string line;
	ifstream inputFile(file);
	if (inputFile.is_open()) {
		while (getline(inputFile,line)) {
			//cout << line << endl;
			int pos = line.find(' ');
			int initialPos = 0;
			vector<string> splitLine;
			while (pos != string::npos) {
				splitLine.push_back(line.substr(initialPos, pos - initialPos));
				initialPos = pos + 1;
				pos = line.find(' ', initialPos);
			}
			splitLine.push_back(line.substr(initialPos));
			/*for (std::vector<string>::iterator i = splitLine.begin(); i != splitLine.end(); ++i) {
				cout << *i << endl;
			}*/
			//cout << splitLine[0] << endl;
			if (splitLine[0].compare("c") == 0) {
				continue;
			}
			else if (splitLine[0] == "p") {
				nodes = atoi(splitLine[2].c_str());
				flow = (int **) calloc(nodes, sizeof(int*));
				capacities = (int **) calloc(nodes, sizeof(int*));
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
				//cout << "Niepoprawny format pliku wejściowego." << endl;
				//exit(0);
			}
		}
	}
	else {
		cout << "Nie można otworzyć pliku " << file << endl;
		exit(0);
	}
	//exit();
	/*int i;
	flow = (int **) calloc(nodes, sizeof(int*));
	capacities = (int **) calloc(nodes, sizeof(int*));
	   for (i = 0; i < nodes; i++) {
	     flow[i] = (int *) calloc(nodes, sizeof(int));
	     capacities[i] = (int *) calloc(nodes, sizeof(int));
	   }

	   //Sample graph
	   capacities[0][1] = 2;
	   capacities[0][2] = 9;
	   capacities[1][2] = 1;
	   capacities[1][3] = 0;
	   capacities[1][4] = 0;
	   capacities[2][4] = 7;
	   capacities[3][5] = 7;
	   capacities[4][5] = 4;
	*/
}
