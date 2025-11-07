#include <iostream>
#include <vector>      // Added for std::vector
using namespace std;

// Function Prototype (No changes needed here)
bool testPIN(const int [], const int [], int);

int main ()
{
    const int NUM_DIGITS = 7; // Number of digits in a PIN


    vector<int> pin1 = {2, 4, 1, 8, 7, 9, 0};
    vector<int> pin2 = {2, 4, 6, 8, 7, 9, 0};
    vector<int> pin3 = {1, 2, 3, 4, 5, 6, 7};

    if (testPIN(pin1.data(), pin2.data(), NUM_DIGITS))
        cout << "ERROR: pin1 and pin2 report to be the same.\n";
    else
        cout << "SUCCESS: pin1 and pin2 are different.\n";

    if (testPIN(pin1.data(), pin3.data(), NUM_DIGITS))
        cout << "ERROR: pin1 and pin3 report to be the same.\n";
    else
        cout << "SUCCESS: pin1 and pin3 are different.\n";

    if (testPIN(pin1.data(), pin1.data(), NUM_DIGITS))
        cout << "SUCCESS: pin1 and pin1 report to be the same.\n";
    else
        cout << "ERROR: pin1 and pin1 report to be different.\n";
        
    return 0;
}

//******************************************************************

// The following function accepts two int arrays. The arrays are   *

// compared. If they contain the same values, true is returned.    *

// If the contain different values, false is returned.             *

//******************************************************************

 

bool testPIN(const int custPIN[], const int databasePIN[], int size)

{

   for (int index = 0; index < size; index++)

   {

      if (custPIN[index] != databasePIN[index])

         return false; // We've found two different values.

   }

   return true; // If we make it this far, the values are the same.

}