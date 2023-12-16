#include "modifiers.h"
#include "errorFunct.h"

void uppercaseify(std::string &s) {
	for (char &c : s) c = toupper(c);
}

void import_data(const std::string &filename, std::unordered_map<int, Match> &matchHistory, Match &m) {
	int totalMatches = matchHistory.size();
	std::ifstream ins(filename);
	try{
		std::cout << "Loading game data for " + filename << std::endl;
		std::string trash = readline(ins);
		while (ins) {
			std::string line = readline(ins);
			if (!ins) break;
			std::istringstream iss(line);
			while (iss) {
				std::string gameNumber;
				getline(iss, gameNumber, ',');
				if (!iss) break;
				int gameNum = stoi(gameNumber) + totalMatches;
				std::string gameType;
				getline(iss, gameType, ',');
				std::string mapName;
				getline(iss, mapName, ',');
				std::string kills;
				getline(iss, kills, ',');
				std::string deaths;
				getline(iss, deaths, ',');
				std::string assists;
				getline(iss, assists, ',');
				std::string score;
				getline(iss, score, ',');
				std::string gameMinutes;
				getline(iss, gameMinutes, ':');
				std::string gameSeconds;
				getline(iss, gameSeconds, ',');
				std::string mvp;
				getline(iss, mvp, ',');
				uppercaseify(mvp);
				std::string gameOutcome;
				getline(iss, gameOutcome, ',');
				uppercaseify(gameOutcome);
				if (!iss) break;

				m.set_mapName(mapName);
				m.set_gameMode(gameType);
				m.set_kills(stoi(kills));
				m.set_deaths(stoi(deaths));
				m.set_assists(stoi(assists));
				m.set_score(stoi(score));
				m.set_minutes(stoi(gameMinutes));
				m.set_seconds(stoi(gameSeconds));
				if (mvp == "NO") m.set_MVP(false);
				else m.set_MVP(true); 
				if (gameOutcome == "LOSS") m.set_won(false);
				else m.set_won(true);
				matchHistory.insert({gameNum, m});
			}
		}
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
		reset_state();
	}
}
