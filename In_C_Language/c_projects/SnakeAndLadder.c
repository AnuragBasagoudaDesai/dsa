

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Function to roll a die
int rollDie()
{
    return (rand() % 6) + 1;
}

// Global variables for players
int player1 = 0, player2 = 0;



// Function to switch players
int switchPlayer(int currentPlayer)
{
    if (currentPlayer == 1)
    {
        return 2;
    }
    else
        return 1;
}

// Function to print the game board
void printBoard()
{
    int board[101];

    for (int index = 0; index <= 100; index++)
    {
        board[index] = 0;
    }

    int alt = 0;
    int iterLR = 101;
    int iterRL = 80;
    int val = 100;

    while (val--)
    {
        if (alt == 0)
        {
            iterLR--;

            if (iterLR == player1)
            {
                printf("#p1 ");
            }
            else if (iterLR == player2)
            {
                printf("#p2 ");
            }
            else
                printf("%3d ", iterLR);

            if (iterLR % 10 == 1)
            {
                printf("\n\n");
                alt = 1;
                iterLR -= 10;
            }
        }
        else
        {
            iterRL++;

            if (iterRL == player1)
            {
                printf("#p1 ");
            }
            else if (iterRL == player2)
            {
                printf("#p2 ");
            }
            else
                printf("%3d ", iterRL);

            if (iterRL % 10 == 0)
            {
                printf("\n\n");
                alt = 0;
                iterRL -= 30;
            }
        }
    }
}

// Function to move a player considering snakes and ladders
int movePlayer(int currentPosition, int roll)
{
    int newPosition = currentPosition + roll;
    int snakesAndLadders[101];

    for (int i = 0; i <= 100; i++)
    {
        snakesAndLadders[i] = 0;
    }

    // Positive weights represent a ladder, negative weights represent a snake
    snakesAndLadders[6] = 40;
    snakesAndLadders[23] = -10;
    snakesAndLadders[45] = -7;
    snakesAndLadders[61] = -18;
    snakesAndLadders[65] = -8;
    snakesAndLadders[77] = 5;
    snakesAndLadders[98] = -10;

    int newSquare = newPosition + snakesAndLadders[newPosition];

    if (newSquare > 100)
    {
        printf("That move goes beyond 100. You stay at the same place.\n");
        return currentPosition;
    }

    return newSquare;
}

// Main function
int main()
{
    srand(time(0));
    int currentPlayer = 1;
    int won = 0;
    printf("Ladder and Snake Game\n");

    while (!won)
    {
        printf("Player %d, press Enter to roll the die...\n", currentPlayer);
        getchar();
        int roll = rollDie();
        printf("You rolled a %d\n", roll);

        if (currentPlayer == 1)
        {
            player1 = movePlayer(player1, roll);
            printf("Player 1 is now at square %d\n", player1);
            printBoard();
            if (player1 == 100)
            {
                printf("Player 1 has won the game!\n");
                won = 1;
            }
        }
        else if (currentPlayer == 2)
        {
            player2 = movePlayer(player2, roll);
            printf("Player 2 is now at square %d\n", player2);
            printBoard();
            if (player2 == 100)
            {
                printf("Player 2 has won the game!\n");
                won = 1;
            }
        }

        currentPlayer = switchPlayer(currentPlayer);
    }

    return 0;
}
