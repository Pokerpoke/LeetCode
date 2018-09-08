/**
 * 
 * Copyright (c) 2018 NUAA Jiang Yang
 * 
 * @file
 * @author   姜阳 (j824544269@gmail.com)
 * @date     2018-09
 * @brief    
 * @version  0.0.1
 * 
 * Last Modified:  2018-09-08
 * Modified By:    姜阳 (j824544269@gmail.com)
 * 
 */
#include "headers.h"

class Solution
{
  public:
    vector<string> fizzBuzz(int n)
    {
        vector<string> res;
        for (size_t i = 1; i <= n; i++)
        {
            if (i % 5 == 0)
            {
                if (i % 3 == 0)
                    res.emplace_back("FizzBuzz");
                else
                    res.emplace_back("Buzz");
            }
            else if (i % 3 == 0)
                res.emplace_back("Fizz");
            else
                res.emplace_back(to_string(i));
        }
        return res;
    }
};

int main(int argc, char const *argv[])
{
    Solution s;
    vector<string> res;
    res = s.fizzBuzz(20);
    for (auto it : res)
        cout << it << endl;
    return 0;
}
