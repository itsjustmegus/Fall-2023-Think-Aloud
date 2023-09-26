/*
 * Name:    tic_tac_toe.cpp
 * Author:  Gus Allred
 * Cretaed: 09/13/23
 * Revised: 09/26/23
 * Purpose: Simple C++ tic tac toe game
 *          Following the tutorial from https://www.simplilearn.com/tutorials/cpp-tutorial/game-in-cpp
 */

#include <iostream>

// Initialize a character list for the squares in the game
char space[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
int row;
int column;
char token = 'x';
bool tie = false;
std::string n1;
std::string n2;

void functionOne();
void functionTwo();
bool functionThree();

int main()
{

    // Create a title
    std::cout << "+-------------------------------------------+" << std::endl;
    std::cout << "|           Gus' Tic Tac Toe Game           |" << std::endl;
    std::cout << "+-------------------------------------------+" << std::endl;

    std::cout << "Enter first player's name: ";
    std::getline(std::cin, n1);

    std::cout << "Enter second player's name: ";
    std::getline(std::cin, n2);

    std::cout << n1 << " is player 1 and goes first" << std::endl;
    std::cout << n2 << " is player 2 and goes second" << std::endl;

    // Loop until the game ends
    while (!functionThree())
    {
        functionOne();
        functionTwo();
        functionThree();
    }

    return 0;

}

void functionOne()
{

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

void functionTwo()
{

    int digit;

    if (token == 'x')
    {
        // Get player 1 input
        std::cout << n1 << ", Choose your square: ";
        std::cin >> digit;
    }

    if (token == 'o')
    {
        // Get player 2 input
        std::cout << n2 << ", Choose your square: ";
        std::cin >> digit;
    }

    if (digit == 1)
    {
        row = 0;
        column = 0;
    }
    
    if (digit == 2)
    {
        row = 0;
        column = 1;
    }

    if (digit == 3)
    {
        row = 0;
        column = 2;
    }

    if (digit == 4)
    {
        row = 1;
        column = 0;
    }

    if (digit == 5)
    {
        row = 1;
        column = 1;
    }

    if (digit == 6)
    {
        row = 1;
        column = 2;
    }

    if (digit == 7)
    {
        row = 2;
        column = 0;
    }

    if (digit == 8)
    {
        row = 2;
        column = 1;
    }

    if (digit == 9)
    {
        row = 2;
        column = 2;
    }

    else if (digit < 1 || digit > 9)
    {
        std::cout << "Invalid !!!" << std::endl;
    }

    if (token == 'x' && space[row][column] != 'x' && space[row][column] != 'o')
    {
        // Mark player choice on the game grid
        space[row][column] = 'x';
        token = 'o';
    }

    else if (token == 'o' && space[row][column] != 'x' && space[row][column] != 'o')
    {
        // Mark player choice on the game grid
        space[row][column] = 'o';
        token = 'x';
    }

    else
    {
        std::cout << "There is no empty space!" << std::endl;
        functionTwo();
    }

    functionOne();

}

bool functionThree()
{
    for (int i = 0; i < 3; i++)
    {
        if (space[i][0] == space[i][1] && space[i][0] == space[i][2] || space[0][i] == space[1][i] && space[0][i] == space[2][i])
        {
            return true;
        }
    }

    if (space[0][0] == space[1][1] && space[1][1] == space[2][2] || space[0][2] == space[1][1] && space[1][1] == space[2][0])
    {
        return true;
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (space[i][j] != 'x' && space[i][j] != 'o')
            {
                return false;
            }
        }
    }
    tie = true;
    return false;
}

// TODO: Determine wins and losses