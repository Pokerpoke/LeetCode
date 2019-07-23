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

// use int will overflow
int main()
{
    int n = 4;

    string res("1");
    if (n <= 0)
        return 0;

    for (int i = 1; i < n; i++)
    {
        int index = 0;
        string temp;
        while (index < res.size())
        {
            int cnt = 0;
            char val = res[index];
            while (index < res.size() && res[index] == val)
            {
                cnt++;
                index++;
            }
            temp += to_string(cnt);
            temp += val;
        }
        res = temp;
    }
    cout << res;

    getchar();
    return 0;
}