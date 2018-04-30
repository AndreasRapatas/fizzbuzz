# fizzbuzz
A C++ library implementing the game FizzBuzz
# Features
* Maps each value to the resulting string
* Accepts multiple rules (E.g. 3 => Fizz, 5 => Buzz, 9 => Haxx)
* The rules can be sorted with a priority value (bigger value comes first)
# Example
From 1 to 49 with rules:
* 3 => Fizz
* 5 => Buzz
* 9 => Haxx
* Fizz comes before Haxx comes before Buzz!
```c++
map<unsigned, string> result = fizzbuzz(1, 50, {
  {800, 3, "Fizz"},
  {500, 5, "Buzz"},
  {700, 9, "Haxx"}
});
```
