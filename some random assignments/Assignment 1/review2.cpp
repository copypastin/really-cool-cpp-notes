// ********************************
// Description: This program counts the total amount of sick days by tellers
// Author: Aaron Nguyen
// COMSC-165-5065
// Date: September 7, 2025
// Status: Complete
// ********************************



#include <iostream>
#include <string>

int main()
{
    
    int numTellers = 0;
    int daysSick = 0;

    std::cout << "How many tellers worked at Nation’s Bank during each of the last three years ?" << std::endl;

    std::cin >> numTellers;


    // loops through num tellers
    for(int i = 1; i <= numTellers; i++) {
        // loops 3 times, to represent 3 years
        for(int j = 1; j <= 3; j++) {
            std::cout << "How many days was teller " << i << " out sick during year " << j << std::endl;
            int tempDays;
            std::cin >> tempDays;
            daysSick += tempDays;
        }
    }

    std::cout << "The " << numTellers << " tellers were out sick for a total of " << daysSick << " days during the 3 years.";

}