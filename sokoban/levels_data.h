#ifndef SOKOBAN_LEVELS_DATA_H
#define SOKOBAN_LEVELS_DATA_H

#include <cstdlib>
#include <iostream>
#include <vector>

using std::string;
using std::vector;
using std::pair;


 bool isDigit(char c);
int findLength(string s);
pair<pair<int,int>,vector<char>> parse(string s);


#endif //SOKOBAN_LEVELS_DATA_H
