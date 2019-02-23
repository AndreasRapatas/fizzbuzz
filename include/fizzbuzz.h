#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

#include <vector>
#include <string>
#include <map>

struct Rule {

	std::string word;
	unsigned number;
	unsigned priority;

	Rule(
		const std::string &word,
		unsigned number,
		unsigned priority
	) :
		word(word),
		number(number),
		priority(priority)
	{}
};

std::map<unsigned, std::string> fizzbuzz(
	unsigned start,
	unsigned finish,
	std::vector<Rule> rules
);

#endif // FIZZBUZZ_H
