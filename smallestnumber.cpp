// Copyright (c) 2023 Lucas DeBruyn All rights reserved

// Created by: Lucas DeBruyn
// Created on: January 2023
/* This program finds the smallest number in an array of
randomly generated numbers*/

#include <array>
#include <iostream>
#include <random>

template <size_t N>
int findingNumber(std::array<int, N> randomList) {
    // This function finds the smallest number
    int smallestNumber;

    for (int counter = 0; counter < randomList.size(); counter++) {
        if (randomList[counter] < smallestNumber) {
            smallestNumber = randomList[counter];
        }
    }
    return smallestNumber;
}

int main() {
    // This is the main function

    std::array<int, 10> generatedRandomList;
    int randomNumber;
    int smallestNumber;

    std::random_device rseed;
    std::mt19937 rgen(rseed());
    std::uniform_int_distribution<int> idist(0, 100);

    std::cout << "Here is a list of random numbers:" << std::endl;
    std::cout << "" << std::endl;

    for (int counter = 0; counter < 10; counter++) {
        randomNumber = idist(rgen);
        generatedRandomList[counter] = randomNumber;
        std::cout << "The random number " << counter + 1 <<
        " is: " << randomNumber << std::endl;
    }
    smallestNumber = findingNumber(generatedRandomList);

    std::cout << "" << std::endl;
    std::cout << "The smallest number is " << smallestNumber << std::endl;

    std::cout << "\nDone." << std::endl;
}
