#include "../include/fizzbuzz.h"

#include <algorithm>

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

		std::string output;

		for (const auto &r : rules) {

			if (i % r.number == 0) {
				output += r.word;
			}
		}

		if (output.size() == 0) {
			output = std::to_string(i);
		}

		result[i] = output;
	}

	return result;
}
