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
 * Last Modified:  2018-08-23
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#include "headers.h"

int main()
{
    //string str("-91283472332d");
    //string str("  +0 123");
    string str("  1+0 123");
    //string str("  +2147483648");

    if (str.empty())
        return 0;

    int res = 0, sign = 1, sign_cnt = 0, num_flag = 0;

    for (size_t i = 0; i < str.size(); i++)
    {
        if (isspace(str[i]))
        {
            if (num_flag == 1)
                break;
            continue;
        }
        else if (str[i] == '-' || str[i] == '+')
        {
            if (num_flag == 1)
                break;
            num_flag = 1;
            sign = (str[i] == '-') ? -1 : 1;
        }
        else if (isdigit(str[i]))
        {
            num_flag = 1;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && (str[i] - '0') > 7))
                cout << (sign > 0 ? INT_MAX : INT_MIN);
            res = res * 10 + int(str[i] - '0');
        }
        else
            break;
    }
    cout << res * sign;

    getchar();
    return 0;
}