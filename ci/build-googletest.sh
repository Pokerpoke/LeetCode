#!/bin/sh
################################################################################
# 
# Copyright (c) 2019 NUAA AeroLab
# 
# @author   Jiang Yang (pokerpoke@qq.com)
# @date     2019-07
# @brief    
# @version  0.0.1
# 
# Last Modified:  2019-07-29
# Modified By:    Jiang Yang (pokerpoke@qq.com)
# 
################################################################################
git clone https://github.com/google/googletest.git
cd googletest
mkdir build
cd build
cmake ..
make -j8
sudo make install