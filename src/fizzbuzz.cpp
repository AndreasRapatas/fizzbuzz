#include "../include/fizzbuzz.h"

using namespace std;

map<unsigned, string> fizzbuzz(
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

	map<unsigned, string> result;

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
