#ifndef BOARD_H
#define BOARD_H

// The second file header in program.
#include "Console.h"

/*
    PosY mean rows.
    PosX mean columns.
*/

void fillBox(int **&board, int posY, int posX)
{
    static int arrayNum[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sizeOfNum = 9;
    for (int k = 0; k < 3; k++)
    {
        for (int l = 0; l < 3; l++)
        {
            int randomNum = rand() % sizeOfNum;
            board[posY * 3 + k][posX * 3 + l] = arrayNum[randomNum];
            swap(arrayNum[randomNum], arrayNum[sizeOfNum - 1]);
            sizeOfNum--;
        }
    }
}

int **InitBoardSudoku(int n = 9)
{
    int **board = new int *[n];
    for (int i = 0; i < n; i++)
    {
        board[i] = new int[n];
    }

    // Fill all 3x3 box with given array of numbers.
    srand(time(NULL));
    int arrayNum[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sizeOfNum = 9;

    for (int i = 0; i < 3; i++) // Position of 3x3 box
    {
        for (int j = 0; j < 3; j++) // Position of 3x3 box
        {
            fillBox(board, i, j);
        }
    }

    return board;
}

void ReleaseSudoku(int **board)
{
    for (int i = 0; i < 9; i++)
    {
        delete[] board[i];
    }
    delete[] board;
}

void PrintSudoku(int **board)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << board[i][j];

            if (j % 3 == 2)
            {
                cout << "  ";
            }
            else
            {
                cout << "|";
            }
        }
        cout << endl;
        if (i % 3 == 2)
        {
            cout << "---------------------" << endl;
        }
    }
}

#endif
