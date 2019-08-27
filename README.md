# LeetCode C++/JS 本地调试环境

[![Build Status](https://travis-ci.com/Pokerpoke/LeetCode.svg?branch=master)](https://travis-ci.com/Pokerpoke/LeetCode)

## 1. C++

### 简介

- 适用于Ubuntu/WSL

### 依赖

- cmake
- googletest

### 用法

生成模板，将会在src目录下生成相应模板，根据题目进行修改即可。

因为C++不支持数字打头的函数名，那就添加一个后缀，solution_NO.名字作为problem_name吧。

```shell
./generate_template ${PROBLEM_NAME}
```

调试运行

```shell
./leetcode ${PROBLEM_NAME}
```

## 2. JS用法

```shell
node ${PROBLEM_NAME}
```
