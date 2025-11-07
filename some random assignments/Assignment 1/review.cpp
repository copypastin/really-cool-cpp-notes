// ********************************
// Description: This program counts which is the favorite beverage
// Author: Aaron Nguyen
// COMSC-165-5065
// Date: September 7, 2025
// Status: Complete
// ********************************


#include <iostream>
#include <string>

int main()
{

    // 1. Coffee 2. Tea 3. Coke 4. Orange Juice

    std::string input = "";

    int coffeeCount = 0;
    int teaCount = 0;
    int cokeCount = 0;
    int ojCount = 0;
    int count = 0;

    std::cout << "Please input the favorite beverage of person #" <<count+1 <<": Choose 1, 2, 3, or 4 from the above menu or -1 to exit the program" << std::endl;

    while (std::cin >> input)
    {
        
        if(input == "1") {
            coffeeCount++;
        }
        else if(input == "2") {
            teaCount++;
        }
        else if(input == "3") {
            cokeCount++;
        }
        else if(input == "4") {
            ojCount++;
        }
        else if(input == "-1"){
            break; // EXIT
        }

        count++;
        std::cout << "Please input the favorite beverage of person #" <<count <<": Choose 1, 2, 3, or 4 from the above menu or -1 to exit the program" << std::endl;
    }

    std::cout << "The total number of people surveyed is " << count << ". The results are as follows:" << std::endl;
    std::cout << "********************************" << std::endl;

    std::cout << "Coffee " << coffeeCount << std::endl;
    std::cout << "Tea " << teaCount << std::endl;
    std::cout << "Coke " << cokeCount << std::endl;
    std::cout << "Orange Juice " << ojCount << std::endl;

    

}
