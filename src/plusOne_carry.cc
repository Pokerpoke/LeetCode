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
    vector<int> digits = {9, 8, 7, 6, 5, 4, 3, 2, 1, 9};

    int carry = 1;
    for (int i = digits.size() - 1; i >= 0; i--)
    {
        if (carry == 0)
            // return digits;
            break;
        int sum = digits[i] + carry;
        digits[i] = sum % 10;
        carry = sum / 10;
    }
    for (auto it : digits)
    {
        cout << it << endl;
    }
    if (carry == 1)
        digits.insert(digits.begin(), 1);

    for (auto it : digits)
    {
        cout << it;
    }

    getchar();
    return 0;
}