#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPACE 32 // ascii cod for space
#define X 88     // ascii cod for X
#define O 79     // ascii cod for O

int matrix[4][4] = {{
                        SPACE,
                        SPACE,
                        SPACE,
                        SPACE,
                    }, // Matrix initialization
                    {
                        SPACE,
                        SPACE,
                        SPACE,
                        SPACE,
                    },
                    {
                        SPACE,
                        SPACE,
                        SPACE,
                        SPACE,
                    },
                    {
                        SPACE,
                        SPACE,
                        SPACE,
                        SPACE,
                    }};

// Function constructors
void printMatrix(), playerTurn(), computerTurn(), resetMatrix();
int check(), whoWin(int row, int column), invalidEnter(int row, int column);

int main()
{
    int win = 0, restart = 0;
    while (!win) // Obsessing until there is no victory
    {
        printMatrix(); // Print matrix
        playerTurn();  // Function of player turn
        win = check(); // Check the win
        if (win)       // if win exit from loop
            break;
        computerTurn(); // Fuction of compucter turn
        win = check();  // Check the win
    }
    printMatrix(); // Print matrix in end the game

    printf("TRY AGAIN? (0 for exit)\n");
    scanf("%d", &restart);
    if (restart) // Restart
    {
        resetMatrix();
        main();
    }
    return 0;
}

void printMatrix()
{
    for (int i = 1; i < 4; i++) // Loop for print row
    {
        for (int j = 1; j < 4; j++) // Loop for print columns
        {
            printf("|");                // print cell separator
            printf("%c", matrix[i][j]); // print matrix
        }
        printf("|"); // print cell separator
        printf("\n");
    }
}

void playerTurn()
{
    int row, column;
    printf("Row:");
    scanf("%d", &row); // Enter row
    printf("Column:");
    scanf("%d", &column); // Enter column
    if (invalidEnter(row, column) == 1) // Check for correct input and occupied cells 
    {
        matrix[row][column] = X; // Write in cell
    }
}

int invalidEnter(int row, int column)
{
    if (((row > 3) || (row < 1) || (column > 3) || (column < 1))) // Check for correct input
    {
        printf("Invalid enter, try againg(Numbers must be from 1 to 3)\n");
        playerTurn();
    }
    else if ((matrix[row][column] != 32)) // Check for occupied cells 
    {
        printf("Invalid enter, try againg (This place is occupied)\n");
        playerTurn();
    }
    else
    {
        return 1;
    }
}

int check() 
{
    for (int i = 1; i < 4; i++)
    {
        if ((matrix[1][i] == matrix[2][i]) && (matrix[2][i] == matrix[3][i])) //Check for row assembly
        {
            return whoWin(1, i); // Fuction for check who win
        }
        if ((matrix[i][1] == matrix[i][2]) && (matrix[i][2] == matrix[i][3])) //Check for column assembly
        {
            return whoWin(i, 1);// Fuction for check who win
        }
    }
    if ((matrix[1][1] == matrix[2][2]) && (matrix[2][2] == matrix[3][3])) // Checking for the collection of diagonals
    {
        return whoWin(1, 1);// Fuction for check who win
    }
    if ((matrix[1][3] == matrix[2][2]) && (matrix[2][2] == matrix[3][1])) // Checking for the collection of diagonals
    {
        return whoWin(1, 3);// Fuction for check who win
    }
    for (int i = 1; i < 4; i++) // Checking whether there are any empty cells
    {
        for (int j = 1; j < 4; j++)
        {
            if (matrix[i][j] == SPACE)
                return 0;
        }
    }
    printf("Draw!!!\n"); //If there are no empty cells and no one has won, then it is a draw
    return 3;
}

void computerTurn()
{
    int row, column;
    row = ((rand() % (3 - 1 + 1)) + 1); //Selection of a row in the range 1 - 3
    column = ((rand() % (3 - 1 + 1)) + 1); //Selection of a columns in the range 1 - 3
    if (matrix[row][column] != SPACE) //Check for cell availability
    {
        computerTurn();
    }
    else
    {
        matrix[row][column] = O;
    }
}

void resetMatrix()
{
    for (int i = 1; i < 4; i++) //Matrix cleaning
    {
        for (int j = 1; j < 4; j++)
        {
            matrix[i][j] = SPACE;
        }
    }
}
 
int whoWin(int row, int column) //Check who won
{ 
    if (matrix[row][column] == X)  // X - Player win
    {
        printf("YOU WON!\n");
        return 1;
    }
    else if (matrix[row][column] == O) // O - compucter win
    {
        printf("I WON!!!\n");
        return 2;
    }
    else
    {
        return 0;
    }
}