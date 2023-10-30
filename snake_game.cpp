/*
 * Name: snake_game.cpp
 * Author: Gus Allred
 * Created: 10/30/23
 * Revised: 
 * Purpose: Simple visual snake game. I'm following a tutorial from NVitanovic on YouTube
 * https://www.youtube.com/watch?v=E_-lMZDi7Uw
 */

#include <iostream>

// Game over method
bool gameOver;
// Create map dimension variables
const int WIDTH = 20;
const int HEIGHT = 20;

// Create head position variables
int x;
int y;
int fruitX;
int fruitY;

// Create score variable
int score;

// Create direction enumeration so the snake
// continuously moves in a direction when a button is pressed
enum rDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
// Create variable for direction enumeration
rDirection dir;


// Game initialization method
void setup()
{
    // Make sure game is not over when it starts
    gameOver = false;

    // Set direction to stopped
    dir = STOP;

    // Center the snake head in the center of the map
    x = WIDTH / 2;
    y = HEIGHT / 2;

    // Create random number for x location of the fruit.
    // This creates a random number between 0 and the WIDTH
    // of the screen - 1
    fruitX = rand() % WIDTH;

    // Create random number for y location of the fruit.
    // This creates a random number between 0 and the HEIGHT
    // of the screen - 1
    fruitY = rand() % HEIGHT;

    // Start score at 0
    score = 0;
}

// Screen drawing method
void draw()
{
    // Clear the screen
    // std::system("clear") for Linux
    std::system("cls");

    // Display the map's top wall using a for loop.
    // Adding one to the width for test portion of the loop
    // so the top and bottom line up with middle
    for (int i = 0; i < WIDTH + 1; i++)
        std::cout << "-";
    
    // Move to next line
    std::cout << std::endl;

    // Display map using nested for loop to create a matrix
    for (int i = 0; i < HEIGHT; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            // If the x location is 0, print the wall character
            if (j == 0)
                std::cout << "|";
            // else, print a a blank line
            else
                std::cout << " ";
            // If the x location is at the width edge, print the wall character
            if (j == WIDTH - 1)
                std::cout << "|";
        }
        // Move to next line to print each row below the previous
        std::cout << std::endl;
    }

    // Display the map's bottom wall using a for loop.
    // Adding one to the width for test portion of the loop
    // so the top and bottom line up with middle
    for (int i = 0; i < WIDTH + 1; i++)
        std::cout << "-";

    // Move to next line
    std::cout << std::endl;
}

// User input method
void input()
{

}

// Game logic method
void logic()
{

}

// Main method
int main()
{
    // Initialize game settings on start
    setup();
    // Game loop
    while (!gameOver)
    {
        // Game method calls
        draw();
        input();
        logic();
    }

    return 0;
}