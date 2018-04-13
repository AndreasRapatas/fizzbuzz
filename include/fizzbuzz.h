#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>

struct Rule {

	unsigned priority;
	unsigned number;
	std::string word;

	Rule(
		unsigned priority,
		unsigned number,
		const std::string &word
	) :
		priority(priority)
		, number(number)
		, word(word)
	{}
};

void fizzbuzz(
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

	for (size_t i = start; i != finish + 1; ++i) {

		std::stringstream output("");

		for (const auto &r : rules) {

			if (i % r.number == 0) {
				output << r.word;
			}
		}

		if (output.str() == "") {
			output << i;
		}

		std::cout << output.str() << '\n';
	}
}

#endif // FIZZBUZZ_H
