#include <iostream>
#include <stdexcept>
#include <numeric>
#include <limits>

void die(const std::string &s = "BAD INPUT!") { throw std::logic_error(s); }
void reset_state() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
