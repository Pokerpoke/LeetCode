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
 * Last Modified:  2018-08-04
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#include "headers.h"

int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};

    int res = 0;
    for (auto it : nums)
    {
        res ^= it;
    }
    cout << res;

    getchar();
    return 0;
}