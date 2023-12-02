#ifndef MATCH_H
#define MATCH_H

#include <iostream>
#include <chrono>

class Match {
	private:
		std::string mapName = "";
		std::string gameMode = "";
		int kills = 0;
		int deaths = 0;
		int assists = 0;
		int score = 0;
		int shotsFired = 0;
		int shotsHit = 0;
		int seconds = 0;
		int minutes = 0;
		double accuracy = 0;
		bool won = false;
		bool MVP = false;
		// TODO: Add other match data including Medals, type of kill (headshots, melee, etc), and more data
	public:
		Match();
		Match(std::string newMapName, std::string newGameMode, int newKills, int newDeaths, int newAssists, int newScore);

		// Getters
		std::string get_mapName() const;
		std::string get_gameMode() const;
		int get_kills() const;
		int get_deaths() const;
		int get_assists() const;
		int get_score() const;
		int get_shotsFired() const;
		int get_shotsHit() const;
		int get_seconds() const;
		int get_minutes() const;
		double get_accuracy() const;
		bool get_won() const;
		bool get_MVP() const;

		// Setters
		void set_mapName(const std::string &newMapName);
		void set_gameMode(const std::string &newGameMode);
		void set_kills(const int &newKills);
		void set_deaths(const int &newDeaths);
		void set_assists(const int &newAssists);
		void set_score(const int &newScore);
		void set_seconds(const int &newSeconds);
		void set_minutes(const int &newMinutes);
		void set_shotsFired(const int &newShotsFired);
		void set_shotsHit(const int &newShotsHit);
		void set_won(const bool &newWon);
		void set_MVP(const bool &newMVP);

		friend std::ostream& operator<<(std::ostream& outs, const Match &m);
		friend std::istream& operator>>(std::istream& ins, Match &m);

		double KDA_Conversion();
		double KD_Conversion();
};

#endif
