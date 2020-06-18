## 1.const含义

常类型是指使用类型修饰符**const**说明的类型，常类型的变量或对象的值是不能被更新的。

## 2.const作用

+ 可以定义常量

```cpp
const int a=100;
```

+ 类型检查

    + const常量与`#define`宏定义常量的区别：
    > ~~<u>**const常量具有类型，编译器可以进行安全检查；#define宏定义没有数据类型，只是简单的字符串替换，不能进行安全检查。**</u>~~感谢两位大佬指出这里问题，见：[issue](https://github.com/Light-City/CPlusPlusThings/issues/5)

    + const定义的变量只有类型为整数或枚举，且以常量表达式初始化时才能作为常量表达式。
    + 其他情况下它只是一个 `const` 限定的变量，不要将与常量混淆。

+ 防止修改，起保护作用，增加程序健壮性

```cpp
void f(const int i){
    i++; //error!
}
```

+ 可以节省空间，避免不必要的内存分配

    + const定义常量从汇编的角度来看，只是给出了对应的内存地址，而不是像`#define`一样给出的是立即数。
    + const定义的常量在程序运行过程中只有一份拷贝，而`#define`定义的常量在内存中有若干个拷贝。
    
## 3.const对象默认为文件局部变量

<p><font style="color:red">注意：非const变量默认为extern。要使const变量能够在其他文件中访问，必须在文件中显式地指定它为extern。</font></p>

> 未被const修饰的变量在不同文件的访问

```cpp
// file1.cpp
int ext
// file2.cpp
#include<iostream>

extern int ext;
int main(){
    std::cout<<(ext+10)<<std::endl;
}
```

> const常量在不同文件的访问

```cpp
//extern_file1.cpp
extern const int ext=12;
//extern_file2.cpp
#include<iostream>
extern const int ext;
int main(){
    std::cout<<ext<<std::endl;
}
```

> 小结：<br>可以发现未被const修饰的变量不需要extern显式声明！而const常量需要显式声明extern，并且需要做初始化！因为常量在定义后就不能被修改，所以定义时必须初始化。</font></p>

## 4.定义常量

```c++
const int b = 10;
b = 0; // error: assignment of read-only variable ‘b’
const string s = "helloworld";
const int i,j=0 // error: uninitialized const ‘i’
```

上述有两个错误：
+ b 为常量，不可更改！
+ i 为常量，必须进行初始化！(因为常量在定义后就不能被修改，所以定义时必须初始化。)

## 5.指针与const

与指针相关的const有四种：

```c++
const char * a; //指向const对象的指针或者说指向常量的指针。指针的地址是变量，指针指向的值是常量,const修饰*
char const * a; //同上
char * const a; //指向类型对象的const指针。或者说常指针、const指针。指针的地址是常量，指针指向的值是变量,const修饰ptr
const char * const a; //指向const对象的const指针。
```

> **小结：** <br>
> 如果*const*位于`*`的左侧，则const就是用来修饰指针所指向的变量，即指针指向为常量；<br>如果const位于`*`的右侧，*const*就是修饰指针本身，即指针本身是常量。

具体使用如下：

```cpp
const int *ptr;
*ptr = 10; //error 由于定义了指针指向的值是常量，不可以修改的，所以是错误的
```

