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
    vector<int> digits = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    vector<int> res;
    long long num = 0;
    int n = digits.size();
    int i = 1;
    for (auto it : digits)
    {
        num *= 10;
        num += it;
    }
    num++;
    while (num != 0)
    {
        res.push_back(num % 10);
        num = num / 10;
    }
    reverse(res.begin(), res.end());

    for (auto it : res)
    {
        cout << it;
    }

    getchar();
    return 0;
}