# LeetCode C++本地调试

项目地址：[Pokerpoke/LeetCode](https://github.com/Pokerpoke/LeetCode)

1.0版本参见[LeetCode C++ 本地调试V1.0](https://www.jianshu.com/p/da70ee7da21c)。

由于有了WSL，可以在Windows使用Ubuntu，同时最新版本的VSCode开始集成WSL了，所以在Windows下不需要搭建运行环境了，统一使用Ubuntu 18.04，可以直接写答案了~~~。

推荐自己撸一个自己用，把刷的题的活学活用了。

## 1.准备工作

所需工具如下：

- [git](https://git-scm.com/)
  - 用以进行版本管理，Windows从官网下载，Linux执行`sudo apt install git`
- [WSL](https://docs.microsoft.com/zh-cn/windows/wsl/install-win10)
  - 按照教程开启即可
- [CMake](https://cmake.org/)
  - CMake请安装version 3.10+，Ubuntu 18.04软件源中的版本可能导致[Unknown CMake command "gtest_discover_tests"](https://github.com/Pokerpoke/LeetCode/issues/1)
- [googletest](https://github.com/google/googletest)
  - Ubuntu 18.04源中带的Googletest不含cmake集成，请从github中编译安装最新版本

### Googletest安装

```shell
git clone https://github.com/google/googletest.git
mkdir build && cd build
cmake ..
make
sudo make install
```

## 2.Ubuntu

Ubuntu按照[VS Code与CMake真乃天作之合](https://zhuanlan.zhihu.com/p/52874931)一文中的进行配置即可，编译和调试都很方便，不需要其他操作。

## 3.Windows(WSL)

Windows Subsystem for Linux, 顾名思义，Windows的Linux子系统，在VSCode的某次更新以后可以直接集成WSL开发了，可乐坏我了，这不就大一统了么。遂抛弃前面用的VCpkg，使用WSL了。

首先，在项目文件夹下右键选择"open with code"，如果没有安装VSCode的时候没有选择添加到右键菜单，直接从VSCode中打开也可。

![open wsl](https://raw.githubusercontent.com/Pokerpoke/Blog-images/master/%E4%BD%BF%E7%94%A8VSCode%E8%BF%9B%E8%A1%8CLeetCode%20C%2B%2B%E6%9C%AC%E5%9C%B0%E8%B0%83%E8%AF%95/vscode-open-wsl.png)

将当前文件夹从WSL中打开。

![reopen folder in wsl](https://raw.githubusercontent.com/Pokerpoke/Blog-images/master/%E4%BD%BF%E7%94%A8VSCode%E8%BF%9B%E8%A1%8CLeetCode%20C%2B%2B%E6%9C%AC%E5%9C%B0%E8%B0%83%E8%AF%95/vscode-reopen-folder-in-wsl.png)

第一次打开，大部分本地的VSCode扩展均失效，需要在WSL中重新安装扩展，起码需要安装以下四个扩展

![install extensions in wsl](https://raw.githubusercontent.com/Pokerpoke/Blog-images/master/%E4%BD%BF%E7%94%A8VSCode%E8%BF%9B%E8%A1%8CLeetCode%20C%2B%2B%E6%9C%AC%E5%9C%B0%E8%B0%83%E8%AF%95/vscode-install-extensions-in-wsl.png)

重新载入VSCode即可看到插件起作用了，点击最下方状态栏中的CMake: Debug Ready，弹出框选择`Debug`就能完成CMake项目的配置了，点击下方状态栏中的Debug旁的目标名称可以选择不同的目标，也就是不同的题目。

![select-debug-target](https://raw.githubusercontent.com/Pokerpoke/Blog-images/master/%E4%BD%BF%E7%94%A8VSCode%E8%BF%9B%E8%A1%8CLeetCode%20C%2B%2B%E6%9C%AC%E5%9C%B0%E8%B0%83%E8%AF%95/select-debug-target.png)

## 4.开始刷题

首先生成题目模板，拷贝`src`目录中的`0.template.cc`，并重命名为`{PROBLEM_NAME}_{PROBLEM_ID}.cc`的格式，修改函数名称，输入输出或者使用项目根目录中的模板生成脚本，不是很难。

注意：这一步需要在WSL控制台中进行，也就是VSCode的终端中执行，毕竟这是一个Linux的Shell脚本。

```shell
./generate_template {PROBLEM_NAME}_{PROBLEM_ID}
```

修改测试用例，根据需求修改函数名、测试用例输入输出等等，下面为例程

```cpp
// 包含"include/headers.h"文件，引入常用头文件
// 如不包含，于"include/headers.h"文件中添加
#include "headers.h"

class Solution
// 题解类
{
public:
    int coinChange_322(vector<int> &coins, int amount)
    // 题解函数，这里写答案
    {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            for (auto coin : coins)
            {
                if (coin <= i)
                    dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

// 测试用例，每个测试用例一个函数段，直接复制修改
// 测试用例1
TEST(coinChange_322, coinChange_322_1)
{
    Solution s;
    vector<int> in = {1, 2, 5};
    int amount = 11;
    int ans = 3;
    // 希望返回值相同
    EXPECT_EQ(s.coinChange_322(in, amount), ans);
}
// 测试用例2
TEST(coinChange_322, coinChange_322_2)
{
    Solution s;
    vector<int> in = {2};
    int amount = 3;
    int ans = -1;
    EXPECT_EQ(s.coinChange_322(in, amount), ans);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
```

测试答案代码，执行以下命令

```shell
# 与前文中的目标同名，即文件名出去.cc后缀
./leetcode {PROBLEM_NAME}_{PROBLEM_ID}
```

或者点击VSCode状态栏上Debug按钮

![cmake extension usage](https://raw.githubusercontent.com/Pokerpoke/Blog-images/master/%E4%BD%BF%E7%94%A8VSCode%E8%BF%9B%E8%A1%8CLeetCode%20C%2B%2B%E6%9C%AC%E5%9C%B0%E8%B0%83%E8%AF%95/cmake-extension-usage.png)

如果修改VSCode中的快捷键，即可更加快速地进行调试。

![cmake keyboard shortcuts](https://raw.githubusercontent.com/Pokerpoke/Blog-images/master/%E4%BD%BF%E7%94%A8VSCode%E8%BF%9B%E8%A1%8CLeetCode%20C%2B%2B%E6%9C%AC%E5%9C%B0%E8%B0%83%E8%AF%95/cmake-keyboard-shortcuts.png)

## 5.可调试使用函数

由于使用Googletest，没法使用断点的方式进行调试，所以封装了几个简单的调试用函数。

打印树、链表

```cpp
// 树
print_tree(TreeNode *root);
// 链表
print_list(ListNode *list_head);
```

判断树、链表是否相等（通过值判断），主要用于测试用例中的结果判断

```cpp
// 树
bool is_same_tree(ListNode *list_head1, ListNode *list_head2);
// 链表
bool is_same_list(ListNode *list_head1, ListNode *list_head2);
```

例如：

```cpp
TEST(removeElements_203, removeElements_203_1)
{
    Solution s;
    // 构造输入链表
    List in = {1, 2, 6, 3, 4, 5, 6};
    // 构造答案链表
    List ans = {1, 2, 3, 4, 5};
    int val = 6;
    // 希望返回值为真
    EXPECT_TRUE(is_same_list(s.removeElements_203(in.head, val), ans.head));
}
```

## 6.树、链表类

链表比较简单，树的类的创建参照LeetCode中题目[二叉树的序列化与反序列化](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/)，注意LeetCode中使用层序遍历来序列化、反序列化二叉树，同时创建树、链表中new出来的资源记得在析构函数中进行释放。

可以考虑自己撸一个头文件出来，还能考虑API的设计，也算一种实践了，嘻嘻。

## 7.参考网页

1. [LeetCode C++ 本地调试V1.0](https://www.jianshu.com/p/da70ee7da21c)
2. [适用于Windows的Linux子系统安装指南](https://docs.microsoft.com/zh-cn/windows/wsl/install-win10)
3. [Developing in WSL with VSCode](https://code.visualstudio.com/docs/remote/wsl)
4. [VS Code与CMake真乃天作之合](https://zhuanlan.zhihu.com/p/52874931)
5. [二叉树的序列化与反序列化](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/)
