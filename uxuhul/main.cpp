//  Created by Mathias Lindblom on 2014-01-27.
//  Copyright (c) 2014 Mathias Lindblom. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <set>
#include <stack>

bool isConsistent(std::vector<std::string> phoneNumbers[10]){

    std::set<std::string> consistanceMap;
    for(int d = 0; d < 10; d++){
        std::vector<std::string> dSizedPhoneNumbers= phoneNumbers[d];
        for(std::string phoneNr : dSizedPhoneNumbers) {
            for(int i = 0; i < d; i++) {
                if(consistanceMap.find(phoneNr.substr(0, i+1)) != consistanceMap.end()) {
                    return false;
                }
            }
            consistanceMap.insert(phoneNr);
        }
    }
    return true;
}

int main(int argc, const char * argv[])
{
    std::string line;
    std::getline(std::cin, line);
    unsigned int testCases = std::stoi(line);
    
    for(unsigned int testcase = 0; testcase < testCases; testcase++){
        std::getline(std::cin, line);
        unsigned int amountPhoneNumbers = std::stoi(line);
        std::vector<std::string> phoneNumbers[10];
        
        for(int i = 0; i < amountPhoneNumbers; i++){
            std::getline(std::cin, line);
            phoneNumbers[line.size() - 1].push_back(line);
        }
        
        if(isConsistent(phoneNumbers)) {
            std::cout << "YES" << std::endl;
        } else {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}





