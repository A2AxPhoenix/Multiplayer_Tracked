#include "read.h"
#include <cstdlib>
#include <string>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <filesystem>
#include "Player.h"
#include "modifiers.h"
using namespace std;

const int MAX = 5;
int banhammer = 0;

//TODO: Make work with Command Line Parameters
int main() {
	const string ACCEPT_EXT = "csv"; // Only accepted file extensions
	enum FIRST_MENU { IMPORT_SINGLE = 1, IMPORT_ALL, WRITE, EXPORT, QUIT = 5 };
	system("figlet Multiplayer Tracker");

	usleep(500'000);
	unordered_map<int, Match> matchData;
	while (true) {
		try {
			int readOrWrite = read("Please enter if you want to:\n1) Import one file\n2) Import all files (Must end in .csv or .txt)\n3) Save Data\n4) Export Data to Disk\n5) Quit\n");
			if (readOrWrite < IMPORT_SINGLE or readOrWrite > QUIT) 
				die("You needed to input a number between 1 and 4. Number of tries remaining: " + to_string(MAX - banhammer));
			if (readOrWrite == IMPORT_SINGLE) {
				string path = "data/";
				string file = read<string>("Please enter the file you want to read: \n"); 
				string filename = path + file;
				ifstream ins(filename);
				if (!ins) 
					die("Error opening file: " + filename + ". Number of tries remaining: " + to_string(MAX - banhammer));
				Match m;
				import_data(filename, matchData, m);
				usleep(500'000);
				string loadData = read("Data loaded. Would you like to see the data (Enter \"Yes\" or \"No\"):\n");
				uppercaseify(loadData);
				if (loadData == "YES") {
					for (const auto &match : matchData) cout << match.second;
					break;
				}
				else if (loadData == "NO") break;
				else die("Please enter \"Yes\" or \"No\" whether you want to see the data. Number of tries remaining: " + to_string(MAX - banhammer));
			}
			else if (readOrWrite == IMPORT_ALL) {
				vector<string> files;
				for (const auto& dirEntry : filesystem::recursive_directory_iterator("data")) {
					files.push_back(dirEntry.path().string());
				}
				for (auto filename : files) {
					ifstream ins(filename);
					if (!ins) 
						die("Error opening file: " + filename + ". Number of tries remaining: " + to_string(MAX - banhammer));
					Match m;
					import_data(filename, matchData, m);
				}
				usleep(500'000);
				string loadData = read("Data loaded. Would you like to see the data (Enter \"Yes\" or \"No\"):\n");
				uppercaseify(loadData);
				if (loadData == "YES") {
					cout << "Total Matches: " << matchData.size() << endl;
					for (const auto &match : matchData) cout << match.second;
					break;
				}
				else if (loadData == "NO") break;
				else die("Please enter \"Yes\" or \"No\" whether you want to see the data. Number of tries remaining: " + to_string(MAX - banhammer));
			}
			else if (readOrWrite == WRITE) {
				string firstGame = read("Is this the first game of a new day? Enter \"Yes\" or \"No\".\n");
				Match m;
				int gameNum = matchData.size();
				while (true) {
					try {
						//TODO: Game Types and Maps must be checked versus the database of all maps and game types to catch errors
						string gameType = readline("Enter the game mode you played on: \n"); 
						string mapName = readline("Enter the map you played on: \n");
						int kills = read("Enter your kills: \n");
						if (kills < 0) die("You cannot have kills lower than 0. You entered " + to_string(kills) + ". Number of tries remaining: " + to_string(MAX - banhammer));
						m.set_kills(kills);
						int deaths = read("Enter your deaths: \n");
						if (deaths < 0) die("You cannot have deaths lower than 0. You entered " + to_string(deaths) + ". Number of tries remaining: " + to_string(MAX - banhammer));
						m.set_deaths(deaths);
						int assists = read("Enter your assists: \n");
						if (assists < 0) die("You cannot have assists lower than 0. You entered " + to_string(assists) + ". Number of tries remaining: " + to_string(MAX - banhammer));
						m.set_assists(assists);
						int score = read("Enter your score: \n");
						m.set_score(score);
						int minutes = read("Enter the minutes of your match: \n");
						if (minutes < 0) die("You cannot have negative time. You entered " + to_string(minutes) + ". Number of tries remaining: " + to_string(MAX - banhammer));
						m.set_minutes(minutes);
						int seconds = read("Enter the seconds of your match: \n");
						if (seconds < 0) die("You cannot have negative time. You entered " + to_string(seconds) + ". Number of tries remaining: " + to_string(MAX - banhammer));
						m.set_seconds(seconds);

						string mvp = read("Did you get MVP? Enter \"Yes\" or \"No\".\n");
						uppercaseify(mvp);
						if (mvp == "YES") m.set_MVP(true);
						else if (mvp == "NO") m.set_MVP(false);
						else die("You did not enter \"Yes\" or \"No\". You entered " + mvp + ". Number of tries remaining: " + to_string(MAX - banhammer));

						string outcome = read("Did you win or lose? Enter \"Win\" or \"Loss\".\n");
						uppercaseify(outcome);
						if (outcome == "WIN") m.set_won(true);
						else if (outcome == "LOSS") m.set_won(false);
						else die("You did not enter \"Win\" or \"Loss\". You entered " + outcome + ". Number of tries remaining: " + to_string(MAX - banhammer));
						matchData.insert({gameNum, m});

						string more = read("Enter more matches? Enter \"Yes\" or \"No\".\n");
						uppercaseify(more);
						if (more == "YES") continue;
						else if (more == "NO") break;
						else die("You did not enter \"Yes\" or \"No\". You entered " + more + ". Number of tries remaining: " + to_string(MAX - banhammer));

					}
					catch(exception &e) {
						cout << e.what() << endl;
						reset_state();
						if (banhammer < MAX) 
							banhammer++;
						else break;
					}
				}
			}
			else if (readOrWrite == EXPORT) {
				string fileWrite = read("Enter the file you want to export data to: \n");
				ofstream outs("data/" + fileWrite);
				int lowerBounds = read("Enter the lower bound of game IDs you want to save to disk (0 - " + to_string(matchData.size() - 1) + ").\n");
				if (lowerBounds < 0 or lowerBounds > matchData.size()) 
					die("You entered an invalid ID that was either less than 0 or above " + to_string(matchData.size() - 1) + ". Number of tries remaining: " + to_string(MAX - banhammer));
				int upperBounds = read("Enter the upper bound of game IDs you want to save to disk (" + to_string(lowerBounds) + " - " + to_string(matchData.size() - 1) + ").\n");
				if (upperBounds < lowerBounds or upperBounds > matchData.size())
					die("You entered an invalid ID that was either less than " + to_string(lowerBounds) + " or above " + to_string(matchData.size() - 1) + ". Number of tries remaining: " + to_string(MAX - banhammer));
			}
			else if (readOrWrite == QUIT) {
				return EXIT_SUCCESS;
			}
			else {
				die("You need to input a number between " + to_string(IMPORT_SINGLE) + "and" + to_string(QUIT) + ".");
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
