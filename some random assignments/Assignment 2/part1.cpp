// ********************************
// Description: This program swaps the values of two different variables!
// Author: Aaron Nguyen
// COMSC-165-5065
// Date: September 13, 2025
// Status: Complete
// ********************************

#include <iostream>

void exchange(int&, int&);

int main() {
    int first;
    int second;

    std::cout << "Enter the first nubmer\nThen hit enter" << std::endl;
    std::cin >> first;

    std::cout << "Enter the second nubmer\nThen hit enter" << std::endl;
    std::cin >> second;

    std::cout << "You input the numbers " << first << " and " << second <<"." << std::endl;

    exchange(first, second);

    std::cout << "After swapping, the first number has the value of " << first << " which was the value of thesecond number" << std::endl;
    std::cout << "The second number has the value of " << second << " which was the value of the first number" << std::endl;

}

void exchange(int& number1, int& number2) {
    int temp = number1;

    number1 = number2;
    number2 = temp;
}
