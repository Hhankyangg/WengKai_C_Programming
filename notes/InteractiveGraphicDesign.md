# 交互图形设计

## 函数指针

### 函数指针的定义

````c
#include <stdio.h>
void fun(int a)
{
    printf("Value of a is %d\n", a);
}
  
int main()
{
    void (*fun_ptr)(int) = &fun;		// 函数指针的定义
    (*fun_ptr)(10);
  
    return 0;
}
````

运行结果: 

````
Value of a is 10
````

### 函数指针的应用

#### 函数指针列表( 根据用户输入不同调用不同函数 )

````c
void f(int a) {
    printf("in f");
}
void g(int a) {
    printf("in g");
}
void h(int a) {
    printf("in h");
}

int main() {
    int i;
    scanf("%d", &i);
    void (*pF[])(int) = {&f, &g, &h};	// 函数指针列表的定义
    if (i>=0 && i<sizeof(pF)/sizeof(pF[0])) {
        (*pF[i])(0);
    }
    return 0;
}
````

#### 函数指针作为函数参数

````c
#include <stdio.h>
int plus(int a, int b) {
    return a+b;
}
int minus(int a, int b) {
    return a-b;
}

void cal(int (*f)(int, int)) {
    printf("%d ", (*f)(5, 1));
}

int main() {
    cal(&plus);
    cal(&minus);
    return 0;
}
````

运行结果

````c
6 4 
````

