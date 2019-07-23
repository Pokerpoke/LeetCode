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

int main(int argc, char const *argv[])
{
    vector<int> nums = {1, 2, 3, 3, 4, 5, 6};

    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 1; i++)
    {
        if (nums[i] == nums[i + 1])
            cout << "true";
    }

    for (auto it : nums)
    {
        cout << it;
    }

    getchar();
    return 0;
}
