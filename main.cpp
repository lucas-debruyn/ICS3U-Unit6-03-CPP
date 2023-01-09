// Copyright(c) 2022 Lucas DeBruyn All rights reserved.
//
// Created by: Lucas DeBruyn
// Created on: October 2022
// This program checks if you guessed the random number with user input

#include <iostream>
#include <random>
#include <string>

int main() {
    // creating variables

    std::string userNumberAsString;
    int randomNumber;
    int userNumberAsNumber;

    // random generator
    std::random_device rseed;
    std::mt19937 rgen(rseed());  // mersenne_twister
    std::uniform_int_distribution<int> idist(1, 10);
    randomNumber = idist(rgen);

    // input
    std::cout << "Enter a number between 1 and 10: ";
    std::cin >> userNumberAsString;

    // process and output
    try {
        userNumberAsNumber = std::stoi(userNumberAsString);
        if (userNumberAsNumber == randomNumber) {
            std::cout << "You guessed correctly!" << std::endl;
        } else {
            std::cout << "You guessed incorrectly, the number was "
                      << randomNumber << std::endl;
        }
    } catch (std::invalid_argument) {
        std::cout << "This was not an integer." << std::endl;
    }

    std::cout << std::endl;
    std::cout << "Done.";
}
