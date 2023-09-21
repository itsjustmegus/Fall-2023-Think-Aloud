/*
 * Name:    tic_tac_toe.cpp
 * Author:  Gus Allred
 * Cretaed: 09/13/23
 * Revised: 09/20/23
 * Purpose: Simple C++ tic tac toe game
 *          Following the tutorial from https://www.simplilearn.com/tutorials/cpp-tutorial/game-in-cpp
 */

#include <iostream>


int main()
{

    // Create a title
    std::cout << "+-------------------------------------------+" << std::endl;
    std::cout << "|           Gus' Tic Tac Toe Game           |" << std::endl;
    std::cout << "+-------------------------------------------+" << std::endl;

    // Initialize a character list for the squares in the game
    char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

    // Build the game grid
    std::cout << "     |     |     \n";
    std::cout << "  " << space[0][0] << "  |  " << space[0][1] << "  |  " << space[0][2] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << space[1][0] << "  |  " << space[1][1] << "  |  " << space[1][2] << "  \n";
    std::cout << "_____|_____|_____\n";
    std::cout << "     |     |     \n";
    std::cout << "  " << space[2][0] << "  |  " << space[2][1] << "  |  " << space[2][2] << "  \n";
    std::cout << "     |     |     \n";

}

// Loop until the game ends

    // Get player input

    // Mark player choice on the game grid

// Determine wins and losses