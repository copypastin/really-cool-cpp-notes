// ********************************
// Description: This program sorts, search, and finds the average of the data set
// Author: Aaron Nguyen
// COMSC-165-5065
// Date: September 28, 2025
// Status: Complete
// ********************************


#include <vector>
#include <iostream>

void sort(std::vector<int>& listOfNumbers);

int binarySearch(std::vector<int> listOfNumbers, int target);

double findAverage(std::vector<int> listOfNumbers);

int main () {
    std::cout << "Enter the amount of the values you'd like to enter." << std::endl;
    int MAX = 0;
    std::cin >> MAX;

    std::vector<int> numList;

    for(int i = MAX; i > 0; i--){
        std::cout << "Enter your number: " << std::endl;
        int value;
        std::cin >> value;
        
        numList.push_back(value);
    }

    sort(numList);

    std::cout << "Enter the numebr you are looking for" << std::endl;
    int target;

    std::cin >> target;
    
    std::cout <<"The number is at the position: "<< binarySearch(numList, target) << std::endl;

    std::cout << "The average number in the list is: " << findAverage(numList) << std::endl;
}

void sort(std::vector<int>& listOfNumbers) {
    bool swapped = false;
    
    for (int i = 0; i < listOfNumbers.size() - 1; ++i) {
        swapped = false;
        for (int j = 0; j < listOfNumbers.size() - 1 - i; ++j) {
            if (listOfNumbers[j] > listOfNumbers[j + 1]) {
                int temp = listOfNumbers[j];
                listOfNumbers[j] = listOfNumbers[j + 1];
                listOfNumbers[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    for (int x : listOfNumbers) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    
}

int binarySearch(std::vector<int> listOfNumber, int target) {
    for(int i = 0; i < listOfNumber.size(); i++) {
        if(listOfNumber[i] == target) {
            return i;
        }
    }
    return -1;
}

double findAverage(std::vector<int> listOfNumber) {
    int total = 0;
    for(int i = 0; i < listOfNumber.size(); i++) {
        total += listOfNumber[i];
    }

    return (1.0 * total) / listOfNumber.size();
}