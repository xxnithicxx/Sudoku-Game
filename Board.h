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

class BAS
{
private:
    bool registered[9] = {false};

public:
    /**
     * @brief Check if the number is valid in the row.
     *
     * @param board
     * @param row
     * @param number
     * @return true if the number is already registered.
     * @return false if the number is not yet registered.
     */
    bool isRegistered(int num)
    {
        for (int i = 0; i < 9; i++)
        {
            if (registered[i] == true && num == i + 1)
            {
                return true;
            }
        }
        return false;
    }

    // Check row
    void checkRow(int **board, int index)
    {
        for (int i = 0; i < 9; i++)
        {
            if (isRegistered(board[index][i]))
            {
                // Put BAS algorithm here.
                /*
                1.) The cell is not part of the current row or column being sorted
                2.) The number in that cell has not been registered
                3a.) The cell being swapped in OR out is not part of a row or column that has been previously sorted
                3b.) The cell is in the row or column adjacent to the duplicate value. 
                */

                // Find position of the duplicate value.
                // duplicatePos will be the one who we wish to swap fisrt
                int duplicatePos = i;
                for (int j = 0; j < 9; j++)
                {
                    if (board[index][j] == board[index][i])
                    {
                        duplicatePos = j;
                        break;
                    }
                }
                 
                // 1.)
                



            }
            else
            {
                registered[board[index][i] - 1] = true;
            }
        }
    }

    // Check column
    void checkCollums(int **board, int index)
    {
        for (int i = 0; i < 9; i++)
        {
            if (isRegistered(board[i][index]))
            {
                // 1 7 9 2 0 / 3 4 5 6 8
            }
            else
            {
                registered[board[i][index] - 1] = true;
            }
        }
    }
}

// Check and sort the board.
void replenishSudoku(int **board)
{
    // Make a dump array that represent the element already registered.
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
