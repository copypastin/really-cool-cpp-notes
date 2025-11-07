// ********************************
// Description: Using strings, make an algorithm to allow the user to edit a string
// Author: AAron Nguyen
// COMSC-165-5065
// Date: October 22, 2025
// Status: Complete
// ********************************

#include <cstring>
#include <iostream>
#include <cstdlib>

int search(char sourceString[], char targetString[]);
void insertString(char sourceString[], char targetString[], int position);
void appendString(char sourceString[], char targetString[]);
void deleteString(char sourceString[], char targetString[]);
void replaceString(char sourceString[], char toReplace[], char replaceWith[]);

const int MAX_SIZE = 100;

int main() {

    char option;
    char mainString[MAX_SIZE];
    char tempString[MAX_SIZE];
    char replaceStringNew[MAX_SIZE];
    int index;
    int position; 

    std::cout << "Enter a string" << std::endl;
    std::cin.getline(mainString, MAX_SIZE - 1); 

    do {
        std::cout << "\nCurrent string: " << mainString << std::endl;
        std::cout << "Choose an option: (s - search, i - insert, a - append, d - delete, r - replace, e-exit)" << std::endl;

        std::cin >> option;

        std::cin.ignore(MAX_SIZE, '\n');

        if (option == 's') {
            std::cout << "Enter a string to be searched:" << std::endl;
            std::cin.getline(tempString, MAX_SIZE - 1);

            index = search(mainString, tempString);
            if (index == -1) {
                std::cout << "Not found" << std::endl;
            } else {
                std::cout << "Found at position: " << index << std::endl;
            }
        }
        else if (option == 'i') {
            std::cout << "Enter index where to insert:" << std::endl;
            std::cin >> position;

            std::cin.ignore(MAX_SIZE, '\n');

            std::cout << "Enter a string to be inserted:" << std::endl;
            std::cin.getline(tempString, MAX_SIZE - 1);

            if (position < 0 || position > (int)strlen(mainString)) {
                std::cout << "Invalid index." << std::endl;
            } else {
                insertString(mainString, tempString, position);
                std::cout << "Updated string: " << mainString << std::endl;
            }
        }
        else if (option == 'a') {
            std::cout << "Enter a string to be appended:" << std::endl;
            std::cin.getline(tempString, MAX_SIZE - 1);

            appendString(mainString, tempString);
            std::cout << "Updated string: " << mainString << std::endl;
        }
        else if (option == 'd') {
            std::cout << "Enter a string to be deleted:" << std::endl;
            std::cin.getline(tempString, MAX_SIZE - 1);

            deleteString(mainString, tempString);
        }
        else if (option == 'r') {
            std::cout << "Enter the string to be replaced:" << std::endl;
            std::cin.getline(tempString, MAX_SIZE - 1);

            std::cout << "Enter the replacing string:" << std::endl;
            std::cin.getline(replaceStringNew, MAX_SIZE - 1);

            replaceString(mainString, tempString, replaceStringNew);
        }
        else if (option == 'e') {
            std::cout << "Bye" << std::endl; 
            break;
        }
        else {
            std::cout << "Invalid Input" << std::endl;
        }

    } while (option != 'e'); 
    
    return 0; 
}


int search(char sourceString[], char targetString[])
{
    int sourceLength, targetLength, index, returnValue;
    sourceLength = strlen(sourceString);
    targetLength = strlen(targetString);
    index = -1;

    for (int i = 0; i < (sourceLength - (targetLength - 1)); i++)
    {
        returnValue = strncmp(&sourceString[i], targetString, targetLength);

        if (returnValue == 0)
        {
            index = i;
            break;
        }
    }

    return index;
}

void insertString(char sourceString[], char targetString[], int position) {
    char tempTail[MAX_SIZE]; 
    strcpy(tempTail, &sourceString[position]);
    strcpy(&sourceString[position], targetString);
    strcat(sourceString, tempTail);
}

void appendString(char sourceString[], char targetString[]) {
    strcat(sourceString, targetString);
}

void deleteString(char sourceString[], char targetString[]) {
     int index = search(sourceString, targetString);

    if (index == -1) {
        std::cout << "Not found" << std::endl;
    } else {
        int lenToDelete = strlen(targetString);

        if (sourceString[index + lenToDelete] == ' ') {
            lenToDelete++; 
        }
        
        strcpy(&sourceString[index], &sourceString[index + lenToDelete]);
        std::cout << "Updated string: " << sourceString << std::endl;
    }
}

void replaceString(char sourceString[], char toReplace[], char replaceWith[]) {
    int index = search(sourceString, toReplace);

    if (index == -1) {
        std::cout << "String to be replaced, Not found" << std::endl;
    } else {
        char tempTail[MAX_SIZE]; 
        int lenToReplace = strlen(toReplace);

        strcpy(tempTail, &sourceString[index + lenToReplace]);
        strcpy(&sourceString[index], replaceWith);
        strcat(sourceString, tempTail);
        
        std::cout << "Updated string: " << sourceString << std::endl;
    }
}