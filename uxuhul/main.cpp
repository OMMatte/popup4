//  Created by Mathias Lindblom on 2014-01-27.
//  Copyright (c) 2014 Mathias Lindblom. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

u_int calculateOutcome(std::vector<std::vector<u_int>> preferences, u_int currentPriest, u_int followingResults[8]) {
    
    u_int newFollowingResults[8];
    for(u_int index = 0; index < 8; index++) {
        int bestPrefScore = 9;
        int bestPrefIndex;
        for(int bit = 0; bit < 3; bit++) {
            int newIndex = index ^ (1 << bit);
            int finalResult = followingResults[newIndex];
            int prefScore = preferences[currentPriest][finalResult];
            if(prefScore < bestPrefScore) {
                bestPrefScore = prefScore;
                bestPrefIndex = newIndex;
            }
        }
        if(currentPriest == 0) {
            return followingResults[bestPrefIndex];
        }
        newFollowingResults[index] = followingResults[bestPrefIndex];
    }
    
    return calculateOutcome(preferences, currentPriest - 1, newFollowingResults);
}

std::string preferenceIndexToString(u_int index) {
    std::string returnString = "";
    for(u_int i = 1; i <= 4; i += i){
        if((index & i) == i) {
            returnString = "Y" + returnString;
        } else {
            returnString = "N" + returnString;
        }
    }
    return returnString;
}


int main(int argc, const char * argv[])
{
    std::string line;
    std::getline(std::cin, line);
    unsigned int testCases = std::stoi(line);
    
    for(unsigned int testcase = 0; testcase < testCases; testcase++){
        std::getline(std::cin, line);
        unsigned int nrPriests = std::stoi(line);
        std::vector<std::vector<u_int>> preferences;
        
        for(int i = 0; i < nrPriests; i++){
            std::getline(std::cin, line);
            std::istringstream iss(line);
            std::vector<std::string> stringPrefs = {std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{}};
            std::vector<u_int> prefs;
            for(int p = 0; p < 8; p++) {
                prefs.push_back(std::stoi(stringPrefs[p]));
            }
            preferences.push_back(prefs);
        }
        u_int resultIndex = 0;
        if(nrPriests != 0) {
            u_int defaultResult[8]{0,1,2,3,4,5,6,7};
            resultIndex = calculateOutcome(preferences, nrPriests - 1, defaultResult);
        }
        
        std::cout << preferenceIndexToString(resultIndex) << std::endl;
    }
    return 0;
}





