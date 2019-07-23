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
 * Last Modified:  2018-08-06
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#include "headers.h"

int main()
{
    vector<int> nums = {0, 1, 0, 3, 12};

    int slow = 0, fast = 0;
    for (fast = 0; fast < nums.size(); fast++)
    {
        if (nums[fast] != 0)
        {
            nums[slow] = nums[fast];
            slow++;
        }
    }
    for (; slow < nums.size(); slow++)
    {
        nums[slow] = 0;
    }

    for (auto it : nums)
    {
        cout << it;
    }

    getchar();
    return 0;
}