# JNIDemo
jni学习系列源码
首先，看一下项目的体系架构。项目分为3个部分：Java部分，c／c++部分，以及一个makefile文件。

java部分：定义native方法，并加载动态连接库，当然还有我们项目的源码，class文件，res资源等。

c/c++部分：包括.c或.cpp文件以及.h头文件，在.c/.cpp文件中实现java层中定义的native方法。

Makefile文件：是对 java 、src 目录下的文件进行编译组织进而生成可执行文件的文件

接下来通过一系列实例来学习JNI编程：<BR>
1. 如何调用C/C++中的函数<BR>
2. 如何调用C/C++中自定义的函数<BR>
3. 如何在jni函数中访问java类中的对象实例域<BR>
4. 如何在jni函数中访问java类中的静态实例域<BR>
5. 如何在jni函数中调用java对象的方法<BR>
6. 如何在jni函数中调用java类的静态方法<BR>
7. 如何在jni函数中传递基本数据类型参数<BR>
8. 如何在jni函数中传递对象类型参数<BR>
9. 如何在jni函数中处理字符串<BR>
10. 如何在jni函数中处理数组<BR>
11. 处理jni函数中的返回值情况<BR>
12. 在jni中实现创建java类对象<BR>
13. jni编程实践……<BR>
