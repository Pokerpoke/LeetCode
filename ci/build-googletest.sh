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

# get scripts path
SCRIPT_DIR=$(dirname $(readlink -f $0))
cd ${SCRIPT_DIR}/..
PROJECT_DIR=$(pwd)
cd ${PROJECT_DIR}

cd /tmp
git clone https://github.com/google/googletest.git
mkdir build
cd build
cmake ..
make -j8
sudo make install