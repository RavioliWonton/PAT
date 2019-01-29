# Programming Ability Test Answer Repository

本人刷的PAT题目答案代码集......
有问题欢迎开Issue询问我。

## 代码原则

尽量做到空间利用优化。

## 编译环境 & 参数

MinGW-w64 GCC-7.3.0 x86_64-posix-seh revison 1
    x86_64-w64-mingw32-g++.exe -flto -Os -Weffc++ -Wall -std=c++14 -m64 -march=native -pipe -fno-tree-ch

LLVM Clang 7.0.0 trunk r333363
    clang++.exe -fms-extensions -m64 -Os -Wall -std=c++14

> *PAT官方使用的是gcc 6.4.0 与 Clang 6.0.1*
>
> *参数为g++ -DONLINE_JUDGE -fno-tree-ch -O2 -Wall -std=c++14 -pipe $src -lm -o $exe*
>
> *和clang++ -DONLINE_JUDGE -O2 -Wall -std=c++14 -pipe $src -lm -o $exe*
