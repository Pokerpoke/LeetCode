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
 * Last Modified:  2018-08-02
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#include "headers.h"

int main()
{
    vector<int> prices = {1, 2, 3, 4, 5};
    vector<int> prices2 = {2, 3, 1, 8, 7};

    if (prices.size() <= 0)
        return 0;

    int max = 0;
    int d = 0;

    for (int i = 1, j = 0; i < prices.size(); i++)
    {
        d = prices[i] - prices[i - 1];
        max += d > 0 ? d : 0;
    }
    cout << max;

    getchar();
    return 0;
}