/*
 * Name: snake_game.cpp
 * Author: Gus Allred
 * Created: 10/30/23
 * Revised: 11/15/23
 * Purpose: Simple visual snake game. I'm following a tutorial from NVitanovic on YouTube
 * Part 1: https://www.youtube.com/watch?v=E_-lMZDi7Uw
 * Part 2: https://youtu.be/W1e5wO7XR2w?si=VzWno4buDizIHEh4
 * Part 3: https://youtu.be/PSoLD9mVXTA?si=Ur484WmPnLL-2Mq4
 */

#include <iostream>
// conio.h handles input and output for this program
#include <conio.h>

// Game over method
bool gameOver;
// Create map dimension variables
const int WIDTH = 70;
const int HEIGHT = 40;

// Create head position variables
int x;
int y;
int fruitX;
int fruitY;
// Create score variable
int score;

// Tail consists of multiple segment
// Each segment follows the segment in front of it
// First array is x coordinate of tail, and second array is y coordinate of tail
int tailX[100];
int tailY[100];
// nTail variable specifies length of the tail
int nTail;

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
            // If the cursor is on the snake's head,
            // print the head of the snake, which will be an "O"
            if (i == y && j == x)
                std::cout << "O";
            // Else if the the cursor is on the fruit's coordinates,
            // print the fruit, which will be an "F"
            else if (i == fruitY && j == fruitX)
                std::cout << "F";
            // Else, print a a blank line
            else
            {
                // keep track of whether we've printed the tail segment or not
                bool print = false;
                // for loop to draw tail
                for (int k = 0; k < nTail; k++)
                {
                    // if tailX is equal to x coordinate and tailY is equal to y coordinate
                    if (tailX[k] == j && tailY[k] == i)
                    {
                        // print the tail segment
                        std::cout << "o";
                        print = true;
                    }
                }
                // if the segment wasn't printed, print blank space
                if (!print)
                    std::cout << " ";
            }
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

    // Continuously print score
    std::cout << "Score: " << score << std::endl;
}

// User input method
void input()
{
    // Check if the keyboard key is pressed
    if (_kbhit())
    {
        // Switch to move snake with "wasd" video game standard
        switch (_getch())
        {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        // last case is to quit game by pressing x
        case 'x':
            gameOver = true;
            break;
        }
    }
}

// Game logic method
void logic()
{
    // remember previous x coordinate of the first element of the tail
    int prevX = tailX[0];
    // remember previous y coordinate of the first element of the tail
    int prevY = tailY[0];
    int prev2X;
    int prev2Y;

    // set first element to follow head
    tailX[0] = x;
    tailY[0] = y;

    // print the moving tail with a for loop that iterates throught the length of the tail
    for (int i = 1; i < nTail; i++)
    {
        // remember position of current segment
        prev2X = tailX[i];
        prev2Y = tailY[i];
        // assign current position as previous position
        tailX[i] = prevX;
        tailY[i] = prevY;
        // update prevX and prevY to prev2X and prev2Y
        prevX = prev2X;
        prevY = prev2Y;
    }

    // switch to determine direction the snake moves based on what was input
    switch (dir)
    {
    case LEFT:
        // if we go left, x coordinate decreases
        x--;
        break;
    case RIGHT:
        // if we go right, x coordinate increases
        x++;
        break;
    case UP:
        // if we go up, y coordinate increases
        y--;
        break;
    case DOWN:
        // if we go down, y coordinate decreases
        y++;
        break;
    default:
        break;
    }

    // Terminate the game if our head leaves the map
    if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
        gameOver = true;

    // if player hits their tail, they will die
    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;

    // If fruit is eaten, the tail and score increase
    if (x == fruitX && y == fruitY)
    {
        // increase the score
        score += 10;
        // place fruit in new random location
        fruitX = rand() % WIDTH;
        fruitY = rand() % HEIGHT;
        // increase the tail
        nTail++;
    }
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