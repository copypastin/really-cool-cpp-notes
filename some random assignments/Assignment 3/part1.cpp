// ********************************
// Description: This program sorts and averages temperature
// Author: Aaron Nguyen
// COMSC-165-5065
// Date: September 21, 2025
// Status: Complete
// ********************************



#include <iostream>
#include <vector>
#include <iomanip> 
#include <string>    



std::vector<int> inputTemperatures();
void bubbleSortTemperatures(std::vector<int>& arr);
double calculateAverage(const std::vector<int>& arr);
void printTemperatures(const std::vector<int>& arr, const std::string& label);

int main() {
    std::cout << "Welcome to the Temperature Analysis Program" << std::endl;

    std::vector<int> temperatures = inputTemperatures();
    printTemperatures(temperatures, "\nOriginal temperatures:");

    double averageTemp = calculateAverage(temperatures);

    bubbleSortTemperatures(temperatures);
    printTemperatures(temperatures, "Sorted temperatures (ascending):");

    std::cout << "\nThe average temperature is:" << std::fixed << std::setprecision(2) << averageTemp << std::endl;

    return 0;
}


 // Prompts user to enter the number of temperatures and then the temp itself. Returns a list of numbers.

std::vector<int> inputTemperatures() {
    std::vector<int> temps;
    int numTemps = 0;

    while (true) {
        std::cout << "Enter the number of temperatures up to 10: ";
        std::cin >> numTemps;
        if (std::cin.good() && numTemps > 0 && numTemps <= 10) {
            break;
        }
    }

    for (int i = 0; i < numTemps; ++i) {
        int temp;
        std::cout << "Enter temperature for day " << i + 1 << ": ";
        std::cin >> temp;
        while (std::cin.fail()) {
            std::cout << "Invalid input. Please enter an integer." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Enter temperature for day " << i + 1 << ": ";
            std::cin >> temp;
        }
        temps.push_back(temp);
    }
    return temps;
}

// works by repeatedly stepping through the list, comparing each pair of adjacent items and swapping them if they are in the wrong order. repeated until no swaps are needed,
void bubbleSortTemperatures(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;
    for (int i = 0; i < n - 1; i++) {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j+1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // If no two elements were swapped by inner loop = then break
        if (!swapped) break;
        
    }
}

// Calculates the average of a list of integers using a manual loop.
double calculateAverage(const std::vector<int>& arr) {
    if (arr.empty()) return 0.0;
    

    double sum = 0.0;
    for (int temp : arr) {
        sum += temp;
    }

    return sum / arr.size();
}

// print the contents of the temperature vector.
void printTemperatures(const std::vector<int>& arr, const std::string& label) {
    std::cout << label;
    for (int temp : arr) {
        std::cout << " " << temp;
    }
    std::cout << std::endl;
}