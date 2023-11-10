# LeetCode C++ 本地调试环境

[![Build Status](https://github.com/Pokerpoke/LeetCode/actions/workflows/LeetCode.yml/badge.svg)](https://github.com/Pokerpoke/LeetCode/actions)

**注** 适用于Ubuntu/WSL

详细用法参见[使用VSCode进行LeetCode C++本地调试](https://github.com/Pokerpoke/LeetCode/blob/master/doc/%E4%BD%BF%E7%94%A8VSCode%E8%BF%9B%E8%A1%8CLeetCode%20C%2B%2B%E6%9C%AC%E5%9C%B0%E8%B0%83%E8%AF%95.md)

## 依赖

- cmake
- googletest

- Ubuntu20.04及以上执行：`sudo apt install build-essential cmake libgtest-dev`

## 创建新git分支

项目为了不污染master分支，解答放到了solutions分支下，如果直接fork过去可以直接在master分支上提交题解，单独创建solutions分支也可以。

## 生成模板并调试运行

通过复制或者提供的脚步生成模板，将会在`src`目录下生成相应模板，根据题目进行修改相关函数名称即可。

脚本使用`${ID}.${SOLUTION_NAME}.cc`的方式创建文件

```shell
./generate_template ${ID}.${SOLUTION_NAME}
```

调试运行，执行脚本或者在VSCode中点击CMake扩展的Debug按钮。

```shell
./leetcode ./src/${ID}.${PROBLEM_NAME}
```
