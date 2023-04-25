# 数据类型(data type)

## 类型定义

````c
typedef int I;	//I 成为了 int 的别名, 故有: 
int a = 10; //等价于 I a = 10;

typedef struct date Date; //Date 为 struct date 别名
Date today = ...;		  //定义变量
typedef struct {
    int x;
    int y;
} point;				 //point 为 这个 struct 的名字
point pt1 = {1,2};		 //定义变量
````

## 枚举

### 声明枚举类型

```c
enum 枚举类型名字 {名字0, 名字1......};
enum COLORS {RED, YELLOW, GREEN};
```

由此, RED = 0, YELLOW = 1, GREEN = 2;

当我们有一些可以排列起来的常量值时, 枚举就相当于给了这些常量名字.

**注意**: 声明可在 `int main(){}`之前.

另外, 我们还可以指定值: 

````c
enum COLORS {RED=2, YELLOW, GREEN=5};
int main(){
    printf("%d, %d, %d", RED, YELLOW, GREEN);
    return 0;
}
````

运行结果: `2, 3, 5`

### 枚举使用

- 枚举量可以作为值.
- 枚举类型使用需要在前面加上`rnum`: `enum COLORS t = RED`.
- 枚举的变量可以作为`int`输入输出`(%d)`.

#### 枚举使用套路

在声明最后加上`NumOfXXX`, 此时他的下标正好为前面量的个数

```c
enum COLORS {RED, YELLOW, GREEN, NumOfCOLORS};
```

可以方便之后做遍历, 定义数组等.

### 虽然但是...

- 枚举现在很少用 ( 不好用 ) .
- 如果是有意义的排比的名字, 枚举会比`const int`方便.
- 枚举比宏 (macro) 好, 因为枚举有`int`类型.

## 结构 (Structure)

### 声明结构类型

**结构是一种类型, 与`int`, `double`等同等级别**

**注意**: 声明可以在任何一个代码块, 或在外部. (通常放在所有函数外面)

常见的两种声明形式: 

````c
//1
struct point {
    int x;
    int y;
};//注意';'
struct point p1, p2;	//p1, p2都是point中有x与y的值
//2
struct point {
    int x;
    int y;
} p1, p2;				//p1, p2都是point中有x与y的值
````

### 结构类型的使用

**注意**: 和本地变量一样, 函数内部声明的结构类型只能在函数内部使用.

所以通常在函数外声明结构这种类型, 在函数内部定义属于这种类型的变量.

````c
struct date {
    int month;
    int day;
    int year;
};
int main() {
    struct date today = {7, 12, 2012};	//初始化法1
    struct date thismonth = {.month=7, .year=2012};
    									//初始化法2, .day=0
    //注意, 上述直接{}赋值只能在初始化用, 后续要用必须 today = (struct date){1, 1, 2010}
    printf("%d-%d-%d\n", today.month, today.day, today.year);
    printf("%d-%d-%d\n", thismonth.month, thismonth.day, thismonth.year);
    return 0;
}
````

运行结果: 

````c
7-12-2012
7-0-2012
````

#### 结构的成员

可以将结构中的变量与数组对比来看:

|        结构中的变量         |  数组  |
| :-------------------------: | :----: |
| `today是结构变量 today.day` | `a[0]` |

#### 结构的运算

对于结构, 可以做赋值, 取地址, 也可以传递给函数参数.

````c
struct date {
    int month;
    int day;
    int year;
};
int main() {
    struct date today;			//没有初始化
    today = (struct date){7, 12, 2012};	//赋值, 类型转换
    struct date day;			//没有初始化
    day = today;				//赋值, 数组可不能这么用
    day.year = 2015;
    printf("%d-%d-%d\n", today.month, today.day, today.year);
    printf("%d-%d-%d\n", day.month, day.day, day.year);
    return 0;
}
````

运行结果:

````c
7-12-2012
7-12-2015		//输出2015证明day是区别于today的一个新的变量, 而非指针
````

#### 结构的指针

- 和数组不同, 结构变量的名字不是结构变量的地址, 必须用`&`取地址
- `struct date *pDate = &today;//定义了指向 struct date 的指针 pDate`

#### 结构变量作为函数参数

````c
int mumberOfDays(struct date d)	//定义返回int的函数，参数为结构中变量
    //原理是函数在函数内新建一个结构变量, 并复制调用者结构的值
    //也可以返回一个结构
````

下面写一个输入今天月日年计算明天日期的程序: 

````c
#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};				//define the structure
				
int daysOfMon(struct date d);		//a function to return the num of days in this month
int isLeap(struct date d); 			//a function to judge if this year is a leap year
				//declare function
int main() {
	//input today's date
	struct date today;
	printf("input today's date like 'month-day-year'\n");
	scanf("%d-%d-%d", &today.month, &today.day, &today.year);
	//judge
	struct date tomorrow = today;
	if (today.day != daysOfMon(today)) {
		tomorrow.day ++;
	}
	else if (today.month == 12) {
		tomorrow.day = 1;
		tomorrow.month = 1;
		tomorrow.year ++;
	}
	else {
		tomorrow.day = 1;
		tomorrow.month ++; 
	}
	//printf
	printf("tomorrow date is %d-%d-%d\n", tomorrow.month, tomorrow.day, tomorrow.year);
    return 0;
}

int daysOfMon(struct date d) {
	int daysofmon = 0;
	int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (isLeap(d) && d.month==2) {
		daysofmon = 29;
	}
	else {
		daysofmon = days[d.month-1];
	}
	return daysofmon;
}
int isLeap(struct date d) {
	int isleap = 0;
	if ((d.year%4==0 && d.year%100!=0) || d.year%400==0) {
		isleap = 1;
	}
	return isleap;
}
````

#### 输入结构

- 没有直接的方式可以一次`scanf`一个结构

````c
//输入结构方法一
struct point {
    int x;
    int y;
};
struct point getStruct(void);	//定义函数 getStruct, 没有参数, 返回一个 struct point 的变量
int main() {
    struct point y = {0, 0};
    y = getStruct();			//直接让 structure = structure
    printf("%d, %d", y.x, y.y);
    return 0;
}
struct point getStruct(void) {
    struct point tmp;
    scanf("%d %d", &tmp.x, &tmp.y);
    return tmp;
}
````

输入: 

````c
2 3
````

运行结果: 

````c
2, 3
````
#### 结构变量的指针作为参数 (比传入整个值更为推荐)

表示指针所指的结构变量中的成员: 

````c
struct date {
    int month;
    int day;
    int year;
} myday;
struct date *p = &myday;
//2种方式用指针表示成员
(*p).month = 12;		//'.'的运算级高于'*'
p->month = 12;
````

用结构变量的指针优化结构输入函数: 

````c
//输入结构方法二
struct point {
    int x;
    int y;
};

struct point* getStruct(struct point *p);	//定义函数 getStruct, 参数是一个指针, 返回一个指针
void print(struct point *p);	//定义函数print, 参数是一个指针
//把 getStruct 的返回值设置成指针而不是 void 其实是一种"套路写法", 后续会提到
int main() {
    struct point y = {0, 0};
    print(getStruct(&y));	//先读,再输出
    printf("%d, %d\n", y.x, y.y);
    return 0;
}

struct point* getStruct(struct point *p) {
    scanf("%d %d", &p->x, &p->y);
    return p;
}
void print(struct point *p) {
    printf("%d, %d\n", p->x, p->y);
}
````

输入: 

````c
1 2
````

运行结果: 

````c
1, 2
````

### 结构的数组,嵌套的结构等

#### 结构的数组

````c
struct date {
    int month;
    int day;
    int year;
};	
struct date dates[] = {{7,12,2012}, {4,28,2004}};//初始化结构数组
````
 #### 数组的结构

````c
struct student {
    int id[];
    int classid[];
    double score[][3];
    double sum[];
};
````
#### 嵌套的结构

````c
struct point {
    int x;
    int y;
};
struct rectangle {
    struct point pt1;
    struct point pt2;
};
//若有变量
struct rectangle r;
//就可以有
r.pt1.x = ......;
//若定义指针指向r
struct rectangle *ptr = &r;
//则以下等价
r.pt1.x | ptr->pt1.x
````

## 联合 (Union)

- 存储

  - 所有成员共享一个空间
  - 同一空间只有一个成员是有效的

  - union变量的大小是其最大的成员

- 初始化
  - 对第一个成员做初始化

### 联合的用处

````c
#include <stdio.h>

typedef union {
    int x;
    char ch[sizeof(int)];
} CHI;					//命名这个 uion 为 CHI

int main() {
    CHI chi;
    chi.x = 1234;		//1234 = 0x000004d2
    int i;				//遍历
    for (i=0; i<sizeof(int); i++) {
        printf("%02hhx ", chi.ch[i]);
    }
    printf("\n");
    //通过这种方式得到一个 int 内部各个字节
    return 0;
}
````

![image-20230405155854739](https://github.com/Hhankyangg/WengKai_C_Programming/blob/main/notes/%E7%BB%93%E6%9E%84%E7%B1%BB%E5%9E%8B.assets/image-20230405155854739.png?raw=true)

存储方式如上, 由于 x86 小端存储, 运行结果为: 

````c
d2 04 00 00 
````



