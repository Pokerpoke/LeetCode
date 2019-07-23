# LeetCode C++/JS 本地调试环境

## 1. C++

### 简介

- 适用于Ubuntu/WSL
- @TODO: Run windows with vcpkg

### 依赖

- cmake
- googletest

#### 1. Ubuntu/WSL

```shell
sudo apt install cmake googletest
```

#### 2. Windows

从[CMake官网](https://cmake.org/download/)下载安装CMake。

根据[microsoft/vcpkg](https://github.com/microsoft/vcpkg)上的步骤安装vcpkg

```powershell
.\vcpkg install googletest
```

### 用法

生成模板，将会在src目录下生成相应模板，根据题目进行修改即可。

因为C++不支持数字打头的函数名，直接用题目中的solution名字作为problem_name吧。（或许以后加上可以文件名与solution名字不同）

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
