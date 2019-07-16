//
//  main.cpp
//  poolBuddy
//
//  Created by Aaron Yoon on 7/13/19.
//  Copyright © 2019 Aaron Yoon. All rights reserved.
//
// Preprocessor information
#include <iostream>
#include "poolBuddyUser.h"
#include <ctime> // not yet used
#include <ctype.h>
#include <fstream>

/*int charChecker(char *holder) {
    int flagger = 0;
    holder = *holder;
    for (char& c: holder) {
        if (!isalpha(c) && !isspace(c)) {
            flagger = 1; // set the flag to catch the non-alphabetic character
            break;
        }
    }
    if (flagger == 1) {
        std::cout << "Please enter characters only.\n";
    }
    flagger = 0; return 0;
} */

void createUser () {
    std::ofstream myFile;
    myFile.open("pbUsers.txt");
    int flagger = 0;
    pbUser user1;
    std::cout << "Please enter your user account information:\n";
    // Enter first name
    while (1) {
        std::cout << "Enter your first name: ";
        std::cin >> user1.firstName;
        // Ensure user only enters alphanumeric characters
        for (char& c: user1.firstName) {
            if (!isalpha(c) && !isspace(c)) {
                flagger = 1; // set the flag to catch the non-alphabetic character
                break;
            }
        }
        if (flagger == 1) {
            std::cout << "Please enter characters only.\n";
        }
        flagger = 0; break;
    }
    // Enter last name
    while (1) {
        std::cout << "Enter your last name: ";
        std::cin >> user1.lastName;
        // Ensure user only enters alphanumeric characters
        for (char& c: user1.lastName) {
            if (!isalpha(c) && !isspace(c)) {
                flagger = 1; // set the flag to catch the non-alphabetic character
                break;
            }
        }
        if (flagger == 1) {
            std::cout << "Please enter characters only.\n";
        }
        flagger = 0; break;
    }
    // Enter Age
    while (flagger == 0) {
        std::cout << "Enter your age: ";
        std::cin >> user1.age;
        if (user1.age < 18) {
            std::cout << "Sorry, but you are too young.\n";
            flagger = 1;
        }else flagger = 0; myFile << user1.age << std::endl;break;
    }
    myFile.close();
    std::cout << "Account successfully created\n";
}

void menu() {
    int menuChoice = -1;
    std::cout << "Welcome to Pool Buddy\n";
    std::cout << "1: Log in to your account\n"; // needs to be created
    std::cout << "2: Create an account\n";
    std::cout << "3: Change your location\n"; // needs to be created
    std::cout << "Enter your choice :";
    std::cin >> menuChoice;
    switch (menuChoice) {
        case 0: exit(0);
        case 1: std::cout << "feature not yet implemented"; return;
        case 2: createUser();
        case 3: std::cout << "feature not yet implemented"; return;;
    }
    std::cout << " ";
}

int main(int argc, const char * argv[]) {
    // insert code here...
    menu();
    
    return 0;
}

