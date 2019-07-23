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
 * Last Modified:  2018-08-27
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#include "headers.h"

int main()
{
    vector<string> strs{{"flower"}, {"flow"}, {"flight"}};
    // vector<string> strs{{"ower"}, {"flow"}, {"flight"}};
    // vector<string> &strs{};

    if (strs.empty())
        return 0;

    string res;
    int min_size = strs[0].size();
    for (int i = 0; i < strs.size(); i++)
    {
        min_size = min_size < strs[i].size() ? min_size : strs[i].size();
    }
    for (int j = 0; j < min_size; j++)
    {
        int i = 0;
        char prefix = strs[i][j];
        while (i < strs.size() && j < strs[i].size() && strs[i][j] == prefix)
        {
            i++;
        }
        if (i == strs.size())
            res += prefix;
        else
            cout << res;
    }
    cout << res;

    getchar();
    return 0;
}