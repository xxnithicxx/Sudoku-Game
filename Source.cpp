#include "Board.h"

int main()
{
    // Init board with 9 x 9 sizes
    int **board = InitBoardSudoku();

    // Print board
    PrintSudoku(board);

    system("pause");
    return 0;
}