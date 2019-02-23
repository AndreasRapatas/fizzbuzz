# fizzbuzz
A C++ library implementing the game FizzBuzz
# Features
* Maps each value to the resulting string
* Accepts multiple rules (E.g. 3:Fizz, 5:Buzz, 9:Haxx)
* The rules can be sorted with a priority value (bigger value comes first)
# Usage
From 1 to 20 with rules:
* 3 => Fizz
* 5 => Buzz
* 9 => Haxx
* Fizz comes before Haxx comes before Buzz!
```c++
map<unsigned, string> result = fizzbuzz(1, 20, {
	{"Fizz", 3, 800},
	{"Buzz", 5, 500},
	{"Haxx", 9, 700}
});
```
Result "1 2 Fizz 4 Buzz Fizz 7 8 FizzHaxx Buzz 11 Fizz 13 14 FizzBuzz 16 17 FizzHaxx 19"
# Installation
```bash
git clone https://github.com/Rapatas/fizzbuzz
mkdir -p fizzbuzz/build
cd fizzbuzz/build
cmake ..
make install # As root
```
