#include <iostream>
#include <vector>
#include <fstream>
#include <unistd.h>
#include "Player.h"
#include <unordered_map>
using namespace std;

int main(int argc, char** argv) {
	system("figlet Multiplayer Tracked");
	// If argument count is greater than 0, then handle what user wants.
	// Procedure is:
	// 	► Check if the user is wanting to either 1) Read a file or 2) Write to a file with new game data. This is argv[0]
	// 	► Check argv[1] for filename
	// 	► If Read, then check argv[2] for one of the following options: 1) Print All Match Data 2) Print Best Game 3) Print Worst Game 4) Quit
	// 	► If Write, then check argv[2] for one of the following options: 1) Add Game Data 2) Remove Game Data 3) Quit
	bool readOrWrite = false;
	string filename;
	enum READ_CHOICES { ALL = 1, BEST, WORST, RQUIT = 4 };
	enum WRITE_CHOICES { ADD = 1, REMOVE, WQUIT = 3 };
	
	if (argc > 0) {

		if (atoi(argv[0]) == 1) readOrWrite = true;
		filename = argv[1];
		if (readOrWrite) {
			ifstream ins(filename);
			if (!ins) return 0;
			while (ins) {

			}
			int choice = atoi(argv[2]);
			
		}
		else if (!readOrWrite) {
			ofstream outs(filename);
		}
		else { 
			return 0;
		}
	}

	
	/*vector<string> args;
	string gameMode;
	string map;
	for (int i = 0; i < argc - 1; ++i) {
		string arg = argv[i + 1];
		if (isdigit(arg.at(0))) {
			string num = arg;
			args.push_back(num
		}
		args.push_back(argv[i]);
	}
	for (string s : args) cout << s << endl;
*/
}
