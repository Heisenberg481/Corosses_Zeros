#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPACE ' '

int matrix[4][4] = {{
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
                    },
                    {
                        SPACE,
                        SPACE,
                        SPACE,
                        SPACE,
                    }};

void printMatrix(), playerTurn(), computerTurn(), invalidEnter(int row, int column);
int check();

int main()
{
    int win = 0;
    while (win == 0)
    {
        printMatrix();
        playerTurn();
        win = check();
        computerTurn();
        win = check();
    }
    if (win == 1){
        printf("YOU WON!");
    }
    else if (win == 2){
        printf("I WON!!!");
    }
    return 0;
}

void printMatrix()
{
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            printf("|");
            printf("%d", matrix[i][j]);
        }
        printf("|");
        printf("\n");
    }
}

void playerTurn()
{
    int row, column;
    printf("Row:");
    scanf("%d", &row);
    printf("Column:");
    scanf("%d", &column);
    invalidEnter(row, column);
    matrix[row][column] = 88;
}

void invalidEnter(int row, int column)
{
    if ((row > 3) || (row < 1) || (column > 3) || (column < 1))
    {
        printf("Invalid enter, try againg");
        playerTurn();
    }
}

int check()
{
    for (int i = 1; i < 4; i++)
    {
        if ((matrix[1][i] == matrix[2][i]) && (matrix[2][i] == matrix[3][i]))
        {
            if (matrix[1][i] == 88)
            {
                return 1;
            }
            else if (matrix[1][i] == 79)
            {
                return 2;
            }
        }
        else if ((matrix[i][1] == matrix[i][2]) && (matrix[i][2] == matrix[i][3]))
        {
            if (matrix[i][1] == 88)
            {
                return 1;
            }
            else if (matrix[1][i] == 79)
            {
                return 2;
            }
        }
        else if ((matrix[1][1] == matrix[2][2]) && (matrix[2][2] == matrix[3][3])){
            if (matrix[1][1] == 88 && matrix[2][2] == 88 && matrix[3][3] == 88)
            {
                return 1;
            }
            else if (matrix[1][1] == 79 && matrix[2][2] == 79 && matrix[1][1] == 79)
            {
                return 2;
            }
        }
        else if ((matrix[1][3] == matrix[2][2]) && (matrix[2][2] == matrix[3][1])){
            if (matrix[1][3] == 88 && matrix[2][2] == 88 && matrix[3][1] == 88)
            {
                return 1;
            }
            else if (matrix[1][3] == 79 && matrix[2][2] == 79 && matrix[3][1] == 79)
            {
                return 2;
            }
        }
        else
        {
            return 0;
        }
    }
}

void computerTurn()
{
    int row, column;
    row = ((rand() % (3 - 1 + 1)) + 1);
    column = ((rand() % (3 - 1 + 1)) + 1);
    printf("%d %d\n", row, column);
    if (matrix[row][column] != 32)
    {
        computerTurn();
    }
    else
    {
        matrix[row][column] = 79;
    }
}