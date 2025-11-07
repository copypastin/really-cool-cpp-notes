// ********************************
// Description: This program calculates grades using the sum of assingments
// Author: Aaron Nguyen
// COMSC-165-5065
// Date: September 13, 2025
// Status: Complete
// ********************************

#include <iostream>

void calculate(int, int, int&);

int main(){
    int gradeSum = 0;
    int numGrades;
    int gradeAvg;

    std::cout << "Enter the number of grades" << std::endl;
    std::cin >> numGrades;

    for(int i = 0; i < numGrades; i++) {
        std::cout << "Enter a numeric grade between 0-100" << std::endl;
        int tempGrade;
        std::cin >> tempGrade;

        gradeSum += tempGrade;
    }

    calculate(gradeSum, numGrades, gradeAvg);

    if(gradeAvg >= 90) {
        std::cout << "The grade is A" << std::endl;
    }
    else if(gradeAvg >= 80) {
        std::cout << "The grade is B" << std::endl;
    }
    else if(gradeAvg >= 70) {
        std::cout << "The grade is C" << std::endl;
    }
    else if(gradeAvg >= 60) {
        std::cout << "The grade is D" << std::endl;
    }
    else {
        std::cout << "The grade is F" << std::endl;
    }
}

void calculate(int sum, int num, int& avg){
    avg =  sum * 1.0 / num;
}