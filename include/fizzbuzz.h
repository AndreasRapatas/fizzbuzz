#ifndef FIZZBUZZ_H
#define FIZZBUZZ_H

#include <vector>
#include <string>
#include <map>

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

std::map<unsigned, std::string> fizzbuzz(
	unsigned start,
	unsigned finish,
	std::vector<Rule> rules
);

#endif // FIZZBUZZ_H
