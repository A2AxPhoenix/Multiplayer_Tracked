#ifndef PLAYER_H
#define PLAYER_H

#include <unordered_map>
#include <string>
#include "GameMode.h"

class Player {
	private:
		std::string gamertag;
		uint64_t kills; 
		uint64_t deaths;
		uint64_t assists;
		uint64_t score;
		uint64_t wins;
		uint64_t losses;
		uint64_t ties;
		uint64_t totalGames;
		uint64_t betrayals;
		uint64_t quitGames;
		uint64_t shotsFired;
		uint64_t shotsMissed;
		uint64_t shotsHit;
		uint64_t meleeKills;
		uint64_t headshotKills;
		std::unordered_map<std::string, int> medals;
		std::unordered_map<std::string, GameMode> gameModes;
	public:
};

#endif
