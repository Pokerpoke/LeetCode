/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   姜阳 (j824544269@gmail.com)
 * @date     2018-08
 * @brief    旋转图像
 * @version  0.0.1
 * 
 * Last Modified:  2018-08-07
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#include "headers.h"

int main()
{
    vector<vector<int>> matrix{{1, 2, 3},
                               {4, 5, 6},
                               {7, 8, 9}};

    // transpose
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    // reverse
    for (int i = 0; i < matrix.size(); i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }

    for (auto row : matrix)
    {
        for (auto it : row)
        {
            cout << it;
        }
    }

    getchar();
    return 0;
}