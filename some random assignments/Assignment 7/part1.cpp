// ********************************
// Description: Sort soccer players by last name using Structured Data Types!
// Aaron Nguyen
// COMSC-165-5065
// Date: October 26, 2025
// Status: Complete
// ********************************

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cstdlib>



struct splayer
{
    char lname[20];
    char fname[20];
    int birthmonth;
    int birthday;
    int birthyear;
};

// prototypes
 
void getData(splayer[]);
void makeCopy(const splayer [], splayer[]);
void showData (const splayer []);
void bubbleSort(splayer []);
void swapp (splayer &, splayer &);
int searchPlayer(const splayer [], char[]);
void findPlayer(splayer players[]);


int main()
{
    splayer players[10];
    splayer sortPlayers[10];
    int choice;

    getData(players);
    makeCopy(players, sortPlayers);

    std::cout << "Choose an option:\n (1 - display original data, 2 - sort data (array) , 3 - display sorted data ( array),  4 - search by last name 5 - exit the program) " << std::endl;
    while (std::cin >> choice)
    {
        if (choice == 1)
        {
            showData(players);
        }
        else if (choice == 2)
        {
            bubbleSort(sortPlayers);
            std::cout << "Data sorted." << std::endl;
        }
        else if (choice == 3)
        {
            showData(sortPlayers);
        }
        else if (choice == 4)
        {
            findPlayer(sortPlayers);
        }
        else if (choice == 5)
        {
            std::cout << "Exiting program." << std::endl;
            break;
        }
        else
        {
            std::cout << "Invalid option. Please try again." << std::endl;
        }

        std::cout << "Choose an option:\n (1 - display original data, 2 - sort data (array) , 3 - display sorted data ( array),  4 - search by last name 5 - exit the program) " << std::endl;


    }

    return 0;
}

void getData(splayer players[]) {

    std::fstream in ("inputs.txt");
    if (in.is_open()) {
        for (int i = 0; i < 10; i++) {
            in >> players[i].lname;
            in >> players[i].fname;
            in >> players[i].birthmonth;
            in >> players[i].birthday;
            in >> players[i].birthyear;
        }
        in.close();
    }
}
void makeCopy(const splayer data[], splayer copy[]) {
    for (int i = 0; i < 10; i++) {
        copy[i] = data[i];
    }
}
void showData (const splayer players[]) {
    for (int i = 0; i < 10; i++)
    {
        std::cout << players[i].lname << " ";
        std::cout << players[i].fname << " ";
        std::cout << players[i].birthmonth << "/";
        std::cout << players[i].birthday << "/";
        std::cout << players[i].birthyear << std::endl;
    }
}
void bubbleSort(splayer players[]) {
    for (int pass = 0; pass < 9; pass++) {
        for (int i = 0; i < 9 - pass; i++) {
            if (std::strcmp(players[i].lname, players[i + 1].lname) > 0) {
                swapp(players[i], players[i + 1]);
            }
        }
    }
}
void swapp (splayer &a, splayer &b) {
    splayer temp = a;
    a = b;
    b = temp;
}
int searchPlayer(const splayer players[], char characters[]) {
    for (int i = 0; i < 10; i++) {
        if (std::strcmp(players[i].lname, characters) == 0) {
            return i;
        }
    }
    return -1; // not found
}

void findPlayer(splayer players[]) {
    while(true) {
        char characters[20];
        std::cout << "Enter last name to search (or '//' to quit): ";
        std::cin >> characters;
        if (std::strcmp(characters, "//") == 0) {
            break;
        }
        int index = searchPlayer(players, characters);
        if (index != -1) {
            std::cout << "Player found: " << players[index].fname << " " << players[index].lname << ", Born on " 
                      << players[index].birthmonth << "/" << players[index].birthday << "/" << players[index].birthyear << std::endl;
        } else {
            std::cout << "Player with last name " << characters << " not found." << std::endl;
        }
    }
}
