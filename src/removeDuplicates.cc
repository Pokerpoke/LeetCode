/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   姜阳 (j824544269@gmail.com)
 * @date     2018-07
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2018-08-29
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#include "headers.h"

int main()
{
    vector<int> nums = {0, 1, 1, 1, 2, 2, 2, 2};

    if (nums.empty())
        return 0;

    int i = 0, j = 0;

    for (; j < nums.size();)
    {
        if (nums[i] == nums[j])
        {
            j++;
        }
        else
        {
            nums[++i] = nums[j++];
        }
    }

    for (auto it : nums)
    {
        cout << it;
    }

    getchar();

    return 0;
}