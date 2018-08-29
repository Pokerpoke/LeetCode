/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   姜阳 (j824544269@gmail.com)
 * @date     2018-08
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2018-08-07
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#include "headers.h"

int main()
{
    vector<vector<char>> board{{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                               {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                               {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                               {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                               {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                               {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                               {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                               {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                               {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    // vector<vector<char>> board{{'.', '.', '.', '.', '5', '.', '.', '1', '.'},
    //                            {'.', '4', '.', '3', '.', '.', '.', '.', '.'},
    //                            {'.', '.', '.', '.', '.', '3', '.', '.', '1'},
    //                            {'8', '.', '.', '.', '.', '.', '.', '2', '.'},
    //                            {'.', '.', '2', '.', '7', '.', '.', '.', '.'},
    //                            {'.', '1', '5', '.', '.', '.', '.', '.', '.'},
    //                            {'.', '.', '.', '.', '.', '2', '.', '.', '.'},
    //                            {'.', '2', '.', '9', '.', '.', '.', '.', '.'},
    //                            {'.', '.', '4', '.', '.', '.', '.', '.', '.'}};

    for (int i = 0; i < 9; i++)
    {
        unordered_set<char> row_set;
        unordered_set<char> col_set;
        for (int j = 0; j < 9; j++)
        {
            // row
            if (board[i][j] != '.')
            {
                if (row_set.find(board[i][j]) == row_set.end())
                    row_set.insert(board[i][j]);
                else
                    return false;
            }
            // column
            if (board[j][i] != '.')
            {
                if (col_set.find(board[j][i]) == col_set.end())
                    col_set.insert(board[j][i]);
                else
                    return false;
            }
            // cell
            if (i % 3 == 0 && j % 3 == 0)
            {
                unordered_set<char> cell_set;
                for (int cell_i = (i / 3) * 3; cell_i < (i / 3) * 3 + 3; cell_i++)
                {
                    for (int cell_j = (j / 3) * 3; cell_j < (j / 3) * 3 + 3; cell_j++)
                    {
                        if (board[cell_i][cell_j] != '.')
                        {
                            if (cell_set.find(board[cell_i][cell_j]) == cell_set.end())
                                cell_set.insert(board[cell_i][cell_j]);
                            else
                                return false;
                        }
                    }
                }
            }
        }
    }

    cout << "True" << endl;
    getchar();
    return true;
}