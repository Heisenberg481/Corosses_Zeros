#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SPACE 32
#define X 88
#define O 79

int matrix[4][4] = {{SPACE,SPACE,SPACE,SPACE,},
                    {SPACE,SPACE,SPACE,SPACE,},
                    {SPACE,SPACE,SPACE,SPACE,},
                    {SPACE,SPACE,SPACE,SPACE,}};

void printMatrix(), playerTurn(), computerTurn(), resetMatrix();
int check(), whoWin(int row, int column), invalidEnter(int row, int column);

int main()
{
    int win = 0, restart = 0;
    while (!win)
    {
        printMatrix();
        playerTurn();
        win = check();
        if (win)
            break;
        computerTurn();
        win = check();
    }
    printMatrix();

    printf("TRY AGAIN? (0 for exit)\n");
    scanf("%d", &restart);
    if (restart)
    {
        resetMatrix();
        main();
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
            printf("%c", matrix[i][j]);
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
    if (invalidEnter(row, column) == 1)
    {
        matrix[row][column] = X;
    }
}

int invalidEnter(int row, int column)
{
    if (((row > 3) || (row < 1) || (column > 3) || (column < 1)))
    {
        printf("Invalid enter, try againg(Numbers must be from 1 to 3)\n");
        playerTurn();
    }
    else if ((matrix[row][column] != 32))
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
        if ((matrix[1][i] == matrix[2][i]) && (matrix[2][i] == matrix[3][i]))
        {
            return whoWin(1, i);
        }
        if ((matrix[i][1] == matrix[i][2]) && (matrix[i][2] == matrix[i][3]))
        {
            return whoWin(i, 1);
        }
    }
    if ((matrix[1][1] == matrix[2][2]) && (matrix[2][2] == matrix[3][3]))
    {
        return whoWin(1, 1);
    }
    if ((matrix[1][3] == matrix[2][2]) && (matrix[2][2] == matrix[3][1]))
    {
        return whoWin(1, 3);
    }
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            if (matrix[i][j] == SPACE)
                return 0;
        }
    }
    printf("Draw!!!\n");
    return 3;
}

void computerTurn()
{
    int row, column;
    row = ((rand() % (3 - 1 + 1)) + 1);
    column = ((rand() % (3 - 1 + 1)) + 1);
    if (matrix[row][column] != SPACE)
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
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j < 4; j++)
        {
            matrix[i][j] = SPACE;
        }
    }
}

int whoWin(int row, int column)
{
    if (matrix[row][column] == X)
    {
        printf("YOU WON!\n");
        return 1;
    }
    else if (matrix[row][column] == O)
    {
        printf("I WON!!!\n");
        return 2;
    }
    else
    {
        return 0;
    }
}