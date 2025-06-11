#include "levels_data.h"

[[maybe_unused]] bool isDigit(char c){
    return '0'<=c && c<='9';
}

int findLength(string s){
    int n = s.size(), curr = 0, minus = 0, totalRes = 0, counter = 0;
    for (int i=0; i<n; i++){
        if (isDigit(s[i])){
            curr = 10 * curr + (s[i] - '0');
            minus++;
        }else{
            totalRes+=curr;
            if (curr) counter++;
            curr = 0;
        }
    }
    return totalRes + n - minus - counter;
}

pair<pair<int,int>,vector<char>> parse(string s){
    string worker;
    int rows = 1, columns = 0, n = s.size();
    for (int i=0; i<n; i++){
        if (s[i]=='|'){
            columns = std::max(findLength(worker), columns);
            worker = ""; rows++;
        } else worker+=s[i];
    }

    vector<char> mass;
    int counter = 0, altcounter = 0;
    for (int i=0; i<n; i++){
        if (s[i]=='|'){
            for (int i=0; i<columns-altcounter; i++) mass.push_back(' ');
            altcounter = 0;
            continue;
        }
        if (isDigit(s[i])){
            counter = 10 * counter + (s[i] - '0');
        }else{
            for (int j=0; j<counter; j++){
                mass.push_back(s[i]);
            }
            if (!counter) mass.push_back(s[i]);
            altcounter += (counter) ? counter : 1;
            counter = 0;
        }
    }
    for (int i=0; i<columns-altcounter; i++) mass.push_back(' ');
    return {{rows, columns}, mass};
}