/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   姜阳 (pokerpoke@qq.com)
 * @date     2018-09
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2018-09-11
 * Modified By:    姜阳 (pokerpoke@qq.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        vector<int> cur_row, pre_row;
        if (numRows == 0)
            return res;
        cur_row.push_back(1);
        res.push_back(cur_row);
        for (int i = 2; i <= numRows; i++)
        {
            pre_row = cur_row;
            cur_row.clear();
            cur_row.push_back(1);
            for (int j = 1; j < pre_row.size(); j++)
            {
                cur_row.push_back(pre_row[j - 1] + pre_row[j]);
            }
            cur_row.push_back(1);
            res.push_back(cur_row);
        }
        return res;
    }
};

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    Solution s;
    for (auto row : s.generate(5))
    {
        for (auto col : row)
            cout << col << " ";
        cout << endl;
    }
    for (auto row : s.generate(0))
    {
        for (auto col : row)
            cout << col << " ";
        cout << endl;
    }

    return RUN_ALL_TESTS();
}