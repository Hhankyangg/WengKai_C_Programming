# 程序结构

## 变量 (Global Variable & Local Variable)

### 全局变量 (Global Variable)

- 全局变量有全局的生存期和作用域
- 定义在所有函数外部

#### 全局变量初始化

- 没有做初始化的全局变量会得到 `0` 值
  - 指针则会得到 `NULL`
- 全局变量初始化发生在 `main`()之前
- 只能用编译时已知的值来初始化全局变量
- 不建议用一个全局变量初始化另一个全局变量

#### 全局变量的隐藏

在更小的地方定义更大的地方定义过的同名值, 之前定义的会在这个更小的地方被隐藏

````c
int gAll = 12;

void f(void);
int main() {
    f();
    printf("gAll in main is %d\n", gAll);
}

void f(void) {
    int gAll = 2;
    printf("gAll in f is %d\n", gAll);
}
````

运行结果：

````c
gAll in f is 2
gAll in main is 12
````

### 静态本地变量 (Static Variable)

- 在本地变量定义时加上`static`修饰符, 变成静态本地变量
- 函数离开的时候, 静态本地变量会继续存在并保持其指
- 静态本地变量初始化只在第一次进入这个函数时做, 以后进入函数会保持上次离开的值

````c
void f(void);
int main() {
    f();
    f();
    f();
}

void f(void) {
    static int all = 2;
    printf("all in f is %d\n", all);
    all += 2;
    printf("then all in f is %d\n", all);
}
````

运行结果

````c
all in f is 2
then all in f is 4
all in f is 4
then all in f is 6
all in f is 6
then all in f is 8
````

- 静态本地变量实际上是特殊的全局变量, 它和全局变量位于相同的内存区域, 
- 静态本地变量拥有全局的生存期, 函数内局部的作用域
- `static`在这里意为局部作用域

**尽量避免使用全局变量和静态本地变量**

## 宏 (Marco)

### 宏定义

#### 编译预处理指令

- `#`开头的是编译预处理指令
- `#define`来定义一个宏
- 他们不是 c语言 的成分, 但是 c语言 离不开他们

**编译过程**: `gcc`中发生了什么: 

````shell
program.c -> a.i -> a.s -> a.o -> a.exe
//        .i这里替换了宏为值  gcc成汇编语言.s
````

#### `#define`的用法

- `#define <name> <value>` 
- **注意:**后面不加`;` (因为这不是 c 的语句)
- 名字必须是一个词, 值可以是各种东西
- 在 c 编译器开始编译前, 编译预处理程序会把程序中名字替换成值
- 替换过程完全是 文本替换

### 宏

- 如果一个宏的指中有其他宏的名字, 也会被替换
- 如果一个宏的值超过一行, 最后一行之前的行末都需要加`\`
- 宏的值后面出现的注释不会被当作宏的值的一部分

- 可以定义没有值的宏, 这类宏用于条件编译, 后面会有代码查询这个宏是否被定义过

  `#define DEBUG `

- 预定义的宏: 

  - `_LINE_` : 当前源代码文件当前所在行号  `int`
  - ``_FILE_` : 当前源代码文件文件名  `str`   		    
  - `_DATE_` : 编译时候的日期  `str`
  - `_TIME_` : 编译时候的时间  `str`

### 带参数的宏

- `#define cube(x)((x)*(x)*(x))`

````c
#define cube(x)((x)*(x)*(x))
int main() {
    int i = 5;
    printf("%d", cube(i-2));
    return 0;
}
````

运行结果

````c
27
````

**注意:** 带参数的宏出现时

- 整个值都要有括号
- 参数出现的每个地方都要有括号

````c
//比较常用的宏
#define MIN(a,b) ((a)>(b)?(b),(a))
````

## 大程序结构

### 多个源代码文件

#### 编译单元

- 一个`.c`文件是一个编译单元
- 编译器每次只处理一个编译单元

### 头文件

将函数声明放到一个头文件 (.h文件) 中, 在需要调用这个函数的源代码文件 (.c文件) 中`#include`这个头文件, 就能让编译器在编译的时候知道函数的原型.

- 所有要调用, 和定义这个头文件里的函数原型的地方, 都要`#include "xxx.h"`
  - 使用, 定义这个函数的地方都应该有`#include`

- 头文件像是 "桥梁"

#### `""` 还是 `<>`

- `""`要求编译器现在当前目录找, 找不到再去编译器指定目录找
- `<>`让编译器只在指定的目录找
- 编译器自己知道自己标准库的头文件在哪
- 环境变量和编译器命令行参数可以指定寻找头文件的目录

#### `#include`误区

- `#include`不是用来 "引入" 库的
- `stdio.h`里只有原型, 具体函数的代码在另外的地方
- 现在c语言编译器默认会引入所有标准库
- `#include <stdio.h>`只是为了让编译器知道函数原型, 确保参数类型正确

#### 声明全局变量

在`.h`文件中用`extern [type] [name]`声明这个全局变量

````c
// main.c
#include <stdio.h>
#include "project.h"

int main() {
	int a = 8;
	printf("%d", max(a, gAll));
	return 0;
}
````

````c
// max.c
#include "project.h"

int gAll = 12;
int max(int a, int b) {
	return (a > b) ? a : b;
}
````

````c
// project.h
int max(int a, int b);
extern int gAll;
````

编译, 运行结果:

````
12
````

##### 声明和定义

- 声明时不产生代码的东西
  - 函数原型
  - 变量声明
  - 结构声明
  - 宏声明
  - 枚举声明
  - 类型声明
  - `inline`函数
- 定义是产生代码的东西
  - 函数, 变量... ...

**头文件中只能放声明 (最好不要放定义)**

#### 加入标准头文件结构做保护

- 运用条件编译和宏, 保证这个头文件在一个编译单元只会被`#include`一次

````c
//在头文件max.h中:
#ifndef _LIST_HEAD_
#define _LIST_HEAD_
xxxxxxx
#endif
````





