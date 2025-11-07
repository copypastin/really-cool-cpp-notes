// ********************************
// Description: Using pointers, recieve and store values in an array. Then, find average median and mode.
// Author: Aaron Nguyen
// COMSC-165-5065
// Date: October 11, 2025
// Status: Complete
// ********************************

#include <vector>
#include <iostream>


double findAverage(int* values, int surveyed);

double findMedian(int* values, int surveyed);

int findMode(int* values, int surveyed);



int main() {
    std::cout << "Enter the amount of students surveyed" << std::endl;

    int numOfPeople;

    std::cin >> numOfPeople;

    int* value = new int[numOfPeople];

    for(int i = 0; i < numOfPeople; i++) {
        std::cout << "Enter a value for person #" << i +1 << std::endl;
        int userValue;

        while (true) {
            std::cin >> userValue;
            if (userValue >= 0) break;
        }

        value[i] = userValue;
    }

    std::cout << "The avergae value is: " << findAverage(value, numOfPeople) << std::endl;
    std::cout << "The median value is: " << findMedian(value, numOfPeople) << std::endl;
    std::cout << "The mode value is: " << findMode(value, numOfPeople) << std::endl;
 
}

double findAverage(int* values, int surveyed) {
    double total = 0;

    for(int i = 0; i < surveyed; i++) {
        total += *(values+i);
    }

    return total / surveyed;
}

double findMedian(int* values, int surveyed) {
    bool swapped = false;
    
    for (int i = 0; i < surveyed - 1; ++i) {
        swapped = false;
        for (int j = 0; j < surveyed - 1 - i; ++j) {
            if (*(values + j) > *(values + j + 1)) {
                int temp = *(values+j);
                *(values+j) = *(values+j + 1);
                *(values+j + 1) = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    if (surveyed % 2 == 0) {
        int target = surveyed/2;
        return (*(values+target) + *(values+target+1))/2;
    }
    else return *(values+surveyed/2 + 1);
}

int findMode(int* values, int surveyed) {
    int mostCommonValue = 0;
    int countToBeat = 0;

    for(int i = 0; i < surveyed; i++) {
        int currentVal = *(values+i);
        int currentCount = 0;

        for(int j = 0; j < surveyed; j++) {
            if(currentVal == *(values+j)) {
                currentCount++;

                if(currentCount > countToBeat) {
                    mostCommonValue = currentVal;
                    countToBeat = currentCount;
                }
            }
        }
    }

    if(countToBeat < 1) return -1;
    else return mostCommonValue;
}