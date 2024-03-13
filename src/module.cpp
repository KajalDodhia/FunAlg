#include "Rcpp.h"
using namespace Rcpp;
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <list>
#include "FUNDAMENTAL_ALGORITHM.h"


//conversion from Rcpp dataframe to unordered_map
// input of function is data frame
// output unordered map where keys are of type std::string and values are vectors of strings (std::vector<std::string>)
std::unordered_map<std::string, std::vector<std::string>> marshalling(DataFrame input)
{
  // create empty unordered map for output
  std::unordered_map <std::string, std::vector<std::string>>  result;
  //gets the names (keys) of the columns in the DataFrame input and stores them in a CharacterVector called keys 
  CharacterVector keys = input.names();
  //populate unordered map with entries from list of vectors

  //iterate over keys
  for (int i=0; i<keys.size(); i++)
  {
    //converts each key from a CharacterVector to a C++ string using as<std::string>() and stores it in the key variable.
    std::string key = as<std::string> (keys[i]);

    // retrieves the corresponding column values from the DataFrame input and stores them in a std::vector<std::string> called values
    std::vector <std::string> values = input[key];
    
    result[key] = values;
  }
  // ouput unordered map
  return result;
}

CharacterVector stable_marriage(DataFrame P1_tab, DataFrame P2_tab)
{
    auto p1 = marshalling(P1_tab);
    auto p2 = marshalling(P2_tab);
    std::unordered_map<std::string, std::string> matching = FUNDAMENTAL_ALGORITHM(p1,p2);
    return wrap(matching); // to make it work with R
}  



RCPP_MODULE(marshalling) 
{
function("marshalling", &marshalling);

}

RCPP_MODULE(stable_marriage) 
{
function("stable_marriage", &stable_marriage);

}
