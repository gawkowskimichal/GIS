#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void read_data(int **& flow, int **& capacities, int & nodes, char * file) {
	string line;
	ifstream input_file(file);
	if (input_file.is_open()) {
		while (getline(input_file,line)) {
			//cout << line << endl;
			int pos = line.find(' ');
			int initial_pos = 0;
			vector<string> split_line;
			while (pos != string::npos) {
				split_line.push_back(line.substr(initial_pos, pos - initial_pos));
				initial_pos = pos + 1;
				pos = line.find(' ', initial_pos);
			}
			split_line.push_back(line.substr(initial_pos));
			/*for (std::vector<string>::iterator i = split_line.begin(); i != split_line.end(); ++i) {
				cout << *i << endl;
			}*/
			//cout << split_line[0] << endl;
			if (split_line[0].compare("c") == 0) {
				continue;
			}
			else if (split_line[0] == "p") {
				nodes = atoi(split_line[2].c_str());
				cout << nodes << endl;
				flow = (int **) calloc(nodes, sizeof(int*));
				capacities = (int **) calloc(nodes, sizeof(int*));
					   for (int i = 0; i < nodes; i++) {
					     flow[i] = (int *) calloc(nodes, sizeof(int));
					     capacities[i] = (int *) calloc(nodes, sizeof(int));
					   }
			}
			else if (split_line[0] == "n") {

			}
			else if (split_line[0] == "a") {
				capacities[atoi(split_line[1].c_str()) - 1][atoi(split_line[2].c_str()) - 1] = atoi(split_line[3].c_str());
			}
			else {
				//cout << "Niepoprawny format pliku wejściowego." << endl;
				//exit(0);
			}
		}
	}
	else {
		cout << "Nie można otworzyć pliku out.txt" << endl;
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
