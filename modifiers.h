#ifndef MODIFIERS_H
#define MODIFIERS_H

#include "read.h"
#include <cctype>
#include <string>
#include <fstream>
#include <sstream>
#include "Match.h"
#include <unordered_map>
#include "errorFunct.h"

void uppercaseify(std::string &s);
void import_data(const std::string &filename, std::unordered_map<int, Match> &matchHistory, Match &m);

#endif
