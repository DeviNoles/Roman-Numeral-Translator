/**
 * @brief Roman Class
 */

#include <iostream>
#include <string>
#include <vector>
#include "roman.hpp"

std::string convertADInt_To_RomanAUC(int);
int convertRomanAUC_To_ADInt(std::string);

/**
 * @brief Default constructor.
 */
Roman::Roman() {
   romanStr = "";
}

/**
 * @brief Constructor.
 */
Roman::Roman(std::string s) {
   SetRoman(s);
}

/**
 * @brief Constructor.
 */
Roman::Roman(int n) {
   SetRoman(n);
}


/**
 * @brief Destructor.
 */
Roman::~Roman() {
}


/**
 * @brief Sets the string romanStr to the string input representing a Roman number.
 */
void Roman::SetRoman(std::string s) {
    romanStr = s;
}

/**
 * @brief Sets the string romanStr to the same integer input.
 */
void Roman::SetRoman(int n) {
    romanStr = convertADInt_To_RomanAUC(n-753);
}

/**
 * @brief Sets the string romanStr to the equivalent input AD year.
 */
void Roman::SetRomanWithAD(int n){
    romanStr = convertADInt_To_RomanAUC(n);
}

/**
 * @brief Gets the string romanStr representing the Roman number.
 */
std::string Roman::GetRoman() const{
    return romanStr;
}

/**
 * @brief Returns the Roman number in integer format
 */
int Roman::GetInt() const{
    if (romanStr.size()==0) 
      return 0;
    return convertRomanAUC_To_ADInt(romanStr)+753;
}

/**
 * @brief Returns the equivalent AD year for romanStr
 */
int Roman::GetAD() const{
    return convertRomanAUC_To_ADInt(romanStr);
}

/**
 * @brief Implements the += operator on the Roman class as follows:

  Modifies romanStr to (1) or (2) below:
  (1) romanStr+rn, if the raw sum is >0 and <4000; 
  (2) the Roman string for the boundary value, otherwise

  Returns the post-increment Roman object.

 */
Roman& Roman::operator+=(const Roman& rn){ 
  //romanStr = romanStr + rn;
  int sum = GetInt() + rn.GetInt();
  if (sum >= 4000) 
    sum=3246;
  romanStr=convertADInt_To_RomanAUC(sum-753); 
  return *this;
}

/**
 * @brief Implements operator++ on the Roman class as follows:

  Modifies romanStr to (1) or (2) below:
  (1) romanStr++(int), if the sum is >0 and <4000; 
  (2) the Roman string for the boundary value, otherwise

  Returns the pre-increment Roman object.

 */
Roman Roman::operator++(int n){ 
  Roman t(*this);
  int sum = GetInt();
  if( n != 0 )
    sum+=n;
  else 
    sum++;
  if (sum >= 4000) 
    sum=3999;
  if (sum <= 0) 
    sum=1;
  romanStr=convertADInt_To_RomanAUC(sum-753);
  return t;
}

/**
 * @brief Implements operator-- on the Roman class as follows: 

  Modifies romanStr to (1) or (2) below:
  (1) romanStr--(int), if the difference is >0 and <4000; 
  (2) the Roman string for the boundary value, otherwise

  Returns the pre-increment Roman object.
 */
Roman Roman::operator--(int n){
  Roman t(*this);
  int sum = GetInt();
  if( n != 0 )
    sum-=n;
  else 
    sum--;
  if (sum >= 4000) 
    sum=3999;
  if (sum <= 0) 
    sum=1;
  romanStr=convertADInt_To_RomanAUC(sum-753);
  return t;
} 

/**
  @brief converts an AD integer (>= -752 and <= 3246) to a Roman AUC string

  @param n is the input integer
  @return result is the output Roman numeral string
*/
std::string convertADInt_To_RomanAUC(int n)
{
    n = n + 753;
    std::string result = "";
    std::vector<std::string> ltrs {"M", "CM", "D", "CD", "C",
                                   "XC", "L", "XL", "X", "IX",
                                   "V", "IV", "I"
                                   };
    int vals[13] = {1000, 900, 500, 400, 100,
                    90, 50, 40, 10, 9, 5, 4, 1};

    for(int i = 0; i < 13; i++)
    {
      while(n >= vals[i])
      {
        n -= vals[i];
        result += ltrs[i];
      }
    }

    return result;
}


/**
  @brief converts a Roman AUC string to an AD integer

  @param instr is the Roman input string in years AUC.
  @return result is the output integer in years A.D.
*/
int convertRomanAUC_To_ADInt(std::string instr)
{
    if(instr == "")
    {
        return 0;
    }

    int result = 0, curr, ahead;
    int base = static_cast<int>('A');
    int romanValues[26] = {0};
    char letters[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
    int values[7] = {1000, 500, 100, 50, 10, 5, 1};

    for(int i = 0; i < 7; i++)
    {
        romanValues[static_cast<int>(letters[i]) - base] = values[i];
    }

    for(std::string::size_type i = 0; i < instr.length(); i++)
    {
        curr = static_cast<int>(instr[i]) - base;
        if(i + 1 < instr.length())
        {
            ahead = static_cast<int>(instr[i + 1]) - base;
            if(romanValues[curr] < romanValues[ahead])
            {
                result = result - romanValues[curr] + romanValues[ahead];
                i++;
            }
            else
            {
                result += romanValues[curr];
            }
        }
        else
        {
            result += romanValues[curr];
        }
    }

    return result-753;
}
