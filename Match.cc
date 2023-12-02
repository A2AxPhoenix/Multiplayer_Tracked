#include "Match.h"
#include <limits>
#include <stdexcept>
using M = Match;

M::Match() {
	mapName = "Insert Map Here";
	gameMode = "Insert Game Mode Here";
	kills = 0;
	assists = 0;
	deaths = 0;
	score = 0;
	won = false;
	MVP = false;
}

M::Match(std::string newMapName, std::string newGameMode, int newKills, int newDeaths, int newAssists, int newScore) {
	set_mapName(newMapName);
	set_gameMode(newGameMode);
	set_kills(newKills);
	set_deaths(newDeaths);
	set_assists(newAssists);
	set_score(newScore);
}

// Getters
std::string M::get_mapName() const { return mapName; }
std::string M::get_gameMode() const { return gameMode; }
int M::get_kills() const { return kills; }
int M::get_deaths() const { return deaths; }
int M::get_assists() const { return assists; }
int M::get_score() const { return score; }
int M::get_shotsFired() const { return shotsFired; }
int M::get_shotsHit() const { return shotsHit; }
int M::get_seconds() const { return seconds; }
int M::get_minutes() const { return minutes; }
double M::get_accuracy() const { return double(shotsHit) / double(shotsFired); }
bool M::get_won() const { return won; }
bool M::get_MVP() const { return MVP; }

// Setters
void M::set_mapName(const std::string &newMapName) {
	for (char c : newMapName) if (isdigit(c)) 
		throw std::logic_error("Invalid map name. Threw on character " + std::to_string(c) + " in string " + newMapName);
	mapName = newMapName;
}
void M::set_gameMode(const std::string &newGameMode) {
	for (char c : newGameMode) if (isdigit(c)) 
		throw std::logic_error("Invalid game mode name. Threw on character " + std::to_string(c) + " in string " + newGameMode);
	gameMode = newGameMode;
}
void M::set_kills(const int &newKills) {
	if (newKills < 0) throw std::logic_error("Invalid amount of kills. Tried to enter " + std::to_string(newKills) + " when kills should be >= 0.");
	if (newKills >= std::numeric_limits<int>::max() - 1) throw std::overflow_error("Overflow Error Detected. Tried to enter " + std::to_string(newKills) + " when kills should be <" + std::to_string(std::numeric_limits<int>::max()) + ".");
	if (newKills <= std::numeric_limits<int>::min() + 1) throw std::underflow_error("Underflow Error Detected. Tried to enter " + std::to_string(newKills) + " when kills should be >" + std::to_string(std::numeric_limits<int>::min()) + ".");
	kills = newKills;
}
void M::set_deaths(const int &newDeaths) {
	if (newDeaths < 0) throw std::logic_error("Invalid amount of deaths. Tried to enter " + std::to_string(newDeaths) + " when deaths should be >= 0.");
	if (newDeaths >= std::numeric_limits<int>::max() - 1) throw std::overflow_error("Overflow Error Detected. Tried to enter " + std::to_string(newDeaths) + " when deaths should be <" + std::to_string(std::numeric_limits<int>::max()) + ".");
	if (newDeaths <= std::numeric_limits<int>::min() + 1) throw std::underflow_error("Underflow Error Detected. Tried to enter " + std::to_string(newDeaths) + " when deaths should be >" + std::to_string(std::numeric_limits<int>::min()) + ".");
	deaths = newDeaths;
}
void M::set_assists(const int &newAssists) {
	if (newAssists < 0) throw std::logic_error("Invalid amount of assists. Tried to enter " + std::to_string(newAssists) + " when score should be >= 0.");
	if (newAssists >= std::numeric_limits<int>::max() - 1) throw std::overflow_error("Overflow Error Detected. Tried to enter " + std::to_string(newAssists) + " when assists should be <" + std::to_string(std::numeric_limits<int>::max()) + ".");
	if (newAssists <= std::numeric_limits<int>::min() + 1) throw std::underflow_error("Underflow Error Detected. Tried to enter " + std::to_string(newAssists) + " when assists should be >" + std::to_string(std::numeric_limits<int>::min()) + ".");
	assists = newAssists;
}
void M::set_score(const int &newScore) {
	if (newScore >= std::numeric_limits<int>::max() - 1) throw std::overflow_error("Overflow Error Detected. Tried to enter " + std::to_string(newScore) + " when score should be <" + std::to_string(std::numeric_limits<int>::max()) + ".");
	if (newScore <= std::numeric_limits<int>::min() + 1) throw std::underflow_error("Underflow Error Detected. Tried to enter " + std::to_string(newScore) + " when score should be >" + std::to_string(std::numeric_limits<int>::min()) + ".");
	score = newScore;
}
void M::set_seconds(const int &newSeconds) {
	if (newSeconds < 0) throw std::logic_error("Invalid amount of seconds. Tried to enter " + std::to_string(newSeconds) + " when seconds should be >= 0.");
	if (newSeconds >= std::numeric_limits<int>::max() - 1) throw std::overflow_error("Overflow Error Detected. Tried to enter " + std::to_string(newSeconds) + " when seconds should be <" + std::to_string(std::numeric_limits<int>::max()) + ".");
	if (newSeconds <= std::numeric_limits<int>::min() + 1) throw std::underflow_error("Underflow Error Detected. Tried to enter " + std::to_string(newSeconds) + " when seconds should be >" + std::to_string(std::numeric_limits<int>::min()) + ".");
	seconds = newSeconds;
}
void M::set_minutes(const int &newMinutes) {
	if (newMinutes < 0) throw std::logic_error("Invalid amount of minutes. Tried to enter " + std::to_string(newMinutes) + " when minutes should be >= 0.");
	if (newMinutes >= std::numeric_limits<int>::max() - 1) throw std::overflow_error("Overflow Error Detected. Tried to enter " + std::to_string(newMinutes) + " when minutes should be <" + std::to_string(std::numeric_limits<int>::max()) + ".");
	if (newMinutes <= std::numeric_limits<int>::min() + 1) throw std::underflow_error("Underflow Error Detected. Tried to enter " + std::to_string(newMinutes) + " when minutes should be >" + std::to_string(std::numeric_limits<int>::min()) + ".");
	minutes = newMinutes;	
}
void M::set_shotsFired(const int &newShotsFired) {
	if (newShotsFired < 0) throw std::logic_error("Invalid amount of shots fired. Tried to enter " + std::to_string(newShotsFired) + " when shots fired should be >= 0.");
	if (newShotsFired >= std::numeric_limits<int>::max() - 1) throw std::overflow_error("Overflow Error Detected. Tried to enter " + std::to_string(newShotsFired) + " when shots fired should be <" + std::to_string(std::numeric_limits<int>::max()) + ".");
	if (newShotsFired <= std::numeric_limits<int>::min() + 1) throw std::underflow_error("Underflow Error Detected. Tried to enter " + std::to_string(newShotsFired) + " when shots fired should be >" + std::to_string(std::numeric_limits<int>::min()) + ".");
	shotsFired = newShotsFired;	
}
void M::set_shotsHit(const int &newShotsHit) {
	if (newShotsHit < 0) throw std::logic_error("Invalid amount of shots hit. Tried to enter " + std::to_string(newShotsHit) + " when shots hit should be >= 0.");
	if (newShotsHit >= std::numeric_limits<int>::max() - 1) throw std::overflow_error("Overflow Error Detected. Tried to enter " + std::to_string(newShotsHit) + " when shots hit should be <" + std::to_string(std::numeric_limits<int>::max()) + ".");
	if (newShotsHit <= std::numeric_limits<int>::min() + 1) throw std::underflow_error("Underflow Error Detected. Tried to enter " + std::to_string(newShotsHit) + " when shots hit should be >" + std::to_string(std::numeric_limits<int>::min()) + ".");
	shotsHit = newShotsHit;
}
void M::set_won(const bool &newWon) {
	won = newWon;
}
void M::set_MVP(const bool &newMVP) {
	MVP = newMVP;
}

std::ostream& operator<<(std::ostream& outs, const Match &m) {
	outs << "Match: " << m.get_gameMode() << std::endl;
	outs << "\tMap Name: " << m.get_mapName() << std::endl;
	outs << "\tDuration: " << m.get_minutes() << ":" << m.get_seconds() << std::endl;
	outs << "\tKills: " << m.get_kills() << std::endl;
	outs << "\tAssists: " << m.get_assists() << std::endl;
	outs << "\tDeaths: " << m.get_deaths() << std::endl;
	outs << "\tOutcome of Match: ";
	if (m.get_won()) outs << "Won" << std::endl; 
	else outs << "Loss" << std::endl; 
	outs << "\tWas MVP: " << std::boolalpha << m.get_MVP() << std::endl;
	return outs;
}
std::istream& operator>>(std::istream& ins, Match &m) {
	ins >> m.gameMode >> m.mapName >> m.kills;
	return ins;
}

double M::KDA_Conversion() { 
	const double ASSIST_BONUS = 0.25;
	double assistModifier = assists * ASSIST_BONUS;
	if (deaths == 0) return (double)kills + assistModifier;
	else {
		return (double(kills) + assistModifier) / (double)deaths;
	}
}
double M::KD_Conversion() {
	if (deaths == 0) return (double)kills;
	else return (double)kills / double(deaths);
}
