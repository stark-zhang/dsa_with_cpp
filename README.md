# DSA with Modern Cpp

#### preface

最近在重新阅读CLRS和其他相关的算法与数据结构教材，于是萌生了使用Modern C++动手实现一下这些经典算法与数据结构的想法。这个repo即作为该想法落地的产物。

在大学时代，我曾经用Python实现过类似的东西，不过时隔已久，当时写过的东西都已经丢失了，而且当时的工作不够系统性，时至今日已无太大的参考价值。顺便感觉到，已经学了很多年C++（我第一次接触C++是在2017年）但是没有系统性实践过使用C++实现一些东西，总感觉学到的东西是无本之木，不够坚实，“纸上得来终觉浅，绝知此事要躬行”。

#### Code Style

在这个repo中，绝大部分代码都将使用`template`实现，所有的代码都放在`dsa`这个命名空间中。其中所有的头文件都使用如下的宏进行保护：
```c++
#ifndef __BDS_MODULE_SUBMOULE_IMPL_H
#define __BDS_MODULE_SUBMOULE_IMPL_H

// effective code

#endif /*__BDS_MODULE_SUBMOULE_IMPL_H*/
```
其中，`BDS`是Basic Data Structure的缩写，目前的主要工作主要是放在基本数据结构的实现和调试上；而算法将会使用`ALG`作为宏的前缀；而`MODULE`作为文件划分的粒度，例如在`include/vector/vector.h`中，对应`VECTOR`；而`SUBMODULE`和`IMPL`对应具体实现文件，例如`include/vector/vector_impl.h`中使用的宏是`__BDS_VECTOR_IMPL_H`，而`include/vector/impl/vector_read.hpp`中对应的则是`__BDS_VECTOR_READDATA_IMPL_H`；依次类推即可。这样文件之间的关系也一目了然了。

目前的构想是，实现一部分较为通用的数据结构，然后将它们作为基础去构建复杂的数据结构。至于具体是采取`has-a`还是`is-a`的关系，则视具体情况而定。在基础的数据结构中，尽量保证和STL提供的类似结构的接口兼容，例如提供迭代器和分配器接口，提供就地构造等等……

代码的编译和测试基于GCC以及LLVM，如果打算使用MS Windows查看编译代码，可以选择使用[msys2](https://www.msys2.org/)。

整个项目支持C++17，对C++11/14/20的支持（已经实现）尚未测试：例如在`vector.h`中，对`iterator`和`allocator`的定义就进行了这样的workaround，支持C++17以及之前的`LegacyIterator`和C++20的`Iterator based on Concepts`，也支持了在C++17中引入的`inline variable`等。

#### Planning

而今项目只是完成了部分数据结构的定义，在未来将会引入Unit Test并使用CMake作为项目管理器，完善测试用例以及Benchmark，总之，按照一个成熟工程的发展路线前进。到这一步已经不仅仅是对C++和DSA的学习了，也是对工程架构能力的考验。

要实现的数据结构基本和CLRS中出现的顺序一致，即从连续性结构到非连续性结构，从线性结构到非线性结构，从树到二叉树再到红黑树，乃至AVL，直到图论等等，相应算法的实现将会穿插在数据结构的实现中。

如果读者需要更详细的文档，可以访问[我的博客](https://stephen-zhang.cn)以获取我的学习笔记。

#### Reference

1. *CLRS(3rd edition)*, by Tomas H. Corman, Charles E. Leiserson, Ronald L. Rivest andClifford Stein
2. [*Algorithms*, by Jeff Erickson](http://jeffe.cs.illinois.edu/teaching/algorithms)
3. *C++ Primer(5th edition)*, by Stanley B. Lippman, Josee Lajoie and Barbara E, Moo
4. *Linux Kernel Development(3rd edition)*, by Robert Love
5. [C++ Reference](https://en.cppreference.com/w/)
6. *Effective Modern C++*, by Scott Meyers
