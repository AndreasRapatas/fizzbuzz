#include <cassert>
#include "../include/fizzbuzz.h"

int main() {

	auto result = fizzbuzz(1, 20, {
		{"Fizz", 3, 800},
		{"Buzz", 5, 500},
		{"Haxx", 9, 700}
	});

	assert(result[1] == "1");
	assert(result[2] == "2");
	assert(result[3] == "Fizz");
	assert(result[4] == "4");
	assert(result[5] == "Buzz");
	assert(result[6] == "Fizz");
	assert(result[7] == "7");
	assert(result[8] == "8");
	assert(result[9] == "FizzHaxx");
	assert(result[10] == "Buzz");
	assert(result[11] == "11");
	assert(result[12] == "Fizz");
	assert(result[13] == "13");
	assert(result[14] == "14");
	assert(result[15] == "FizzBuzz");
	assert(result[16] == "16");
	assert(result[17] == "17");
	assert(result[18] == "FizzHaxx");
	assert(result[19] == "19");

	return 0;
}
