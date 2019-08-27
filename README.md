# LeetCode C++/JS 本地调试环境

[![Build Status](https://travis-ci.com/Pokerpoke/LeetCode.svg?branch=master)](https://travis-ci.com/Pokerpoke/LeetCode)

## 1. C++

**适用于Ubuntu/WSL**

详细用法参见[使用VSCode进行LeetCode C++本地调试](doc/使用VSCode进行LeetCode\ C++本地调试.md)

### 依赖

- cmake
- googletest

### 用法

生成模板，将会在src目录下生成相应模板，根据题目进行修改即可。

因为C++不支持数字打头的函数名，那就添加一个后缀，${PROBLEM_NAME}_{ID}.名字作为solution_name吧。

```shell
./generate_template ${PROBLEM_NAME}_{ID}
```

调试运行

```shell
./leetcode ${PROBLEM_NAME}_{ID}
```
