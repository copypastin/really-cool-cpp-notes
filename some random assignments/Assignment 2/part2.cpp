// ********************************
// Description: This program calculates the MPH using the user's inputs
// Author: Aaron Nguyen
// COMSC-165-5065
// Date: September 13, 2025
// Status: Complete
// ********************************

#include <iostream>
#include <iomanip>

void calculate(int, int, float&);

int main(){
    int miles;
    int hours;
    float speed;

    std::cout << "Please input the miles traveled" << std::endl;
    std::cin >> miles;
    std::cout << "Please input the hours traveled" << std::endl;

    std::cin >> hours;

    calculate(miles, hours, speed);

    std::cout << std::fixed << std::setprecision(2) << "Your speed is " << speed << " miles per hour" << std::endl;


}

void calculate(int miles, int hours, float& milesPerHour) {
    milesPerHour = (miles * 1.0) / hours;
}