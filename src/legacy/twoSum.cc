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
    vector<int> nums = {3, 2, 4};
    int target = 6;
    vector<int> res;

    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
        map.emplace(target - nums[i], i);
        if (map.find(nums[i]) != map.end() && i != map[nums[i]])
        {
            res.push_back(map[nums[i]]);
            res.push_back(i);
        }
    }

    for (auto it : res)
    {
        cout << it;
    }

    getchar();
    return 0;
}