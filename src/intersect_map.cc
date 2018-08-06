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
    vector<int> nums1 = {1, 2, 2, 3, 3, 3, 3, 3, 3, 1};
    vector<int> nums2 = {2, 2, 3, 3};

    vector<int> res;
    unordered_map<int, int> map;
    for (auto it : nums1)
    {
        map[it]++;
    }
    for (auto it : nums2)
    {
        if (map[it] > 0)
        {
            res.push_back(it);
            map[it]--;
        }
    }

    for (auto it : res)
        cout << it << endl;

    getchar();
    return 0;
}