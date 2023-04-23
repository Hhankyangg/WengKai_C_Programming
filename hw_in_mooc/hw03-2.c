// 三天打鱼两天晒网(15)
// 时间限制
// 400 ms
// 内存限制
// 65536 kB
// 代码长度限制
// 8000 B
// 判题程序
// Standard
// 中国有句俗语叫“三天打鱼两天晒网”。假设某人从某天起，开始“三天打鱼两天晒网”，问这个人在以后的第N天中是“打鱼”还是“晒网”？
// 输入格式：
// 输入在一行中给出1个不超过1000的正整数N。
// 输出格式：
// 在一行中输出此人在第N天中是“Fishing”（即“打鱼”）还是“Drying”（即“晒网”），并且输出“in day N”。
// 输入样例1：
// 103
// 输出样例1：
// Fishing in day 103
// 输入样例2：
// 34
// 输出样例2：
// Drying in day 34

#include <stdio.h>

int main(){
	int n;
	scanf("%d", &n);
	if ((n%5 <= 3) || (n%5 >= 1)){
		printf("Fishing in day %d", n);
	}
	else {
		printf("Drying in day %d", n);
	}
	
	return 0;
}
