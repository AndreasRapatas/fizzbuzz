#include <iostream>
#include "fizzbuzz.h"

int main() {

	fizzbuzz(1, 50, {
		{800, 3, "Fizz"},
		{500, 5, "Buzz"},
		{700, 9, "Haxx"}
	});

	return 0;
}
