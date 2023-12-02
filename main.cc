#include "read.h"
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <string>
#include <unistd.h>
#include "Player.h"
#include "errorFunct.h"
#include "modifiers.h"
using namespace std;

const int MAX = 5; // 5 tries to get things right.
int banhammer = 0; // Track number of goofs.

//TODO: Make work with Command Line Parameters
int main() {
	enum FIRST_MENU { IMPORT_SINGLE = 1, IMPORT_ALL, WRITE, QUIT = 4 };
	system("figlet Multiplayer Tracker");
	
	usleep(500'000);
	unordered_map<int, Match> singleMatchData;
	while (true) {
		try {
			int readOrWrite = read("Please enter if you want to:\n1) Import one file\n2) Import all files (Must end in .csv or .txt)\n3) Write to a file\n4) Quit\n");
			if (readOrWrite < IMPORT_SINGLE or readOrWrite > QUIT) 
				die("You needed to input a number between 1 and 4. Number of tries remaining: " + to_string(MAX - banhammer));
			if (readOrWrite == IMPORT_SINGLE) {
				string filename = read<string>("Please enter the file you want to read: \n"); 
				ifstream ins(filename);
				if (!ins) die("Error opening file: " + filename + ". Number of tries remaining: " + to_string(MAX - banhammer));
				cout << "Loading game data for " + filename << endl;
				string trash = readline(ins);
				cout << trash << endl;
				while (ins) {
					string line = readline(ins);
					if (!ins) break;
					cout << line << endl;
					istringstream iss(line);
					while (iss) {
						string gameNumber;
						getline(iss, gameNumber, ',');
						if (!iss) break;
						int gameNum = stoi(gameNumber);
						string gameType;
						getline(iss, gameType, ',');
						string mapName;
						getline(iss, mapName, ',');
						string kills;
						getline(iss, kills, ',');
						string deaths;
						getline(iss, deaths, ',');
						string assists;
						getline(iss, assists, ',');
						string score;
						getline(iss, score, ',');
						string gameMinutes;
						getline(iss, gameMinutes, ':');
						string gameSeconds;
						getline(iss, gameSeconds, ',');
						string mvp;
						getline(iss, mvp, ',');
						uppercaseify(mvp);
						string gameOutcome;
						getline(iss, gameOutcome, ',');
						uppercaseify(gameOutcome);
						if (!iss) break;
						Match m(mapName, gameType, stoi(kills), stoi(deaths), stoi(assists), stoi(score));
						
						m.set_minutes(stoi(gameMinutes));
						m.set_seconds(stoi(gameSeconds));
						if (mvp == "NO") m.set_MVP(false);
						else m.set_MVP(true);
						if (gameOutcome == "LOSS") m.set_won(false); 
						else m.set_won(true);
						singleMatchData.insert({gameNum, m});
					}
				}
				break;
			}
			else if (readOrWrite == IMPORT_ALL) {
			}
			else if (readOrWrite == WRITE) {
			}
			else if (readOrWrite == QUIT) {
				return EXIT_SUCCESS;
			}
			else {
				die("You need to input a number between 1 and 2.");
			}
		}
		catch (exception &e) {
			cout << e.what() << endl;
			reset_state();
			if (banhammer < MAX) 
				banhammer++;
			else break;
		}
	}
	//TODO: Other options once done with importing
}
