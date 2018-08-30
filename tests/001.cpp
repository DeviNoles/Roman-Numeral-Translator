#include <cassert>
#include "../src/roman.hpp"

int main () {

	/* Default constructor. */
	Roman p;

	assert(p.GetRoman() == "");
        assert(p.GetInt() == 0);

	/* Parameterized constructor. */
	Roman p1("VII");
	assert(p1.GetRoman() == "VII");
        assert(p1.GetInt() == 7);

	/* Parameterized constructor. */
	Roman p2(1900);
	assert(p2.GetRoman() == "MCM");
        assert(p2.GetInt() == 1900);

	return 0;
}

