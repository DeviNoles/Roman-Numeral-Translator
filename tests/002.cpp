#include <cassert>
#include "../src/roman.hpp"

int main () {

	Roman p;

	/* Test setters*/
	p.SetRoman("MMXVII");

	assert(p.GetRoman() == "MMXVII" && p.GetInt() == 2017);

	p.SetRoman(2016);

	assert(p.GetRoman() == "MMXVI" && p.GetInt() == 2016);

	return 0;
}

