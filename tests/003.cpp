#include <cassert>
#include "../src/roman.hpp"

int main () {

	Roman p(100);
	Roman q(10);
	Roman r(370);


	/* Test getting coordinates. */
	assert(p.GetInt() == 100);
	assert(r.GetInt() == 370);

	return 0;
}

