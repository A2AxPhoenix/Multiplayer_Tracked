#include "modifiers.h"
#include <cctype>

void uppercaseify(std::string &s) {
	for (char &c : s) c = toupper(c);
}
