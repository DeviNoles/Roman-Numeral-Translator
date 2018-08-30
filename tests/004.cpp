#include <cassert>
#include <cmath>
#include "../src/roman.hpp"

int main () {
        Roman p("LXXVIII");   // 78

        p.operator++(70);
        assert(p.GetInt() == 148);
        assert(p.GetRoman() == "CXLVIII");


        Roman c("CI");   // 101
        
        c++;
        assert(c.GetInt() == 102);
        

        c--;
        assert(c.GetRoman() == "CI");
        c--;
             
        c.operator--(10);
        assert(c.GetRoman() == "XC");
        
        Roman e("MMXX");      // 2020
        assert(e.GetInt() == 2020);
        assert(e.GetAD() == 1267);
        
        
	return 0;
}

