#include "../include/fizzbuzz.h"

#include <algorithm>
#include <sstream>

std::map<unsigned, std::string> fizzbuzz(
	unsigned start,
	unsigned finish,
	std::vector<Rule> rules
) {
	std::sort(
		rules.begin(),
		rules.end(),
		[] (const Rule &lhs, const Rule &rhs) {
			return lhs.priority > rhs.priority;
		}
	);

	std::map<unsigned, std::string> result;

	for (size_t i = start; i != finish; ++i) {

		std::stringstream output("");

		for (const auto &r : rules) {

			if (i % r.number == 0) {
				output << r.word;
			}
		}

		if (output.str() == "") {
			output << i;
		}

		result[i] = output.str();
	}

	return result;
}
