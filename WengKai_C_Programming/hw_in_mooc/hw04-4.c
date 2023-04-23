// 统计素数并求和(20)
// 时间限制
// 400 ms
// 内存限制
// 65536 kB
// 代码长度限制
// 8000 B
// 判题程序
// Standard
// 作者
// 张彤彧（浙江大学）
// 本题要求统计给定整数M和N区间内素数的个数并对它们求和。
// 输入格式：
// 输入在一行中给出2个正整数M和N（1<=M<=N<=500）。
// 输出格式：
// 在一行中顺序输出M和N区间内素数的个数以及它们的和，数字间以空格分隔。
// 输入样例：
// 10 31
// 输出样例：
// 7 143

#include <stdio.h>

int main(){
	int low, up;
	scanf("%d %d", &low, &up);
	
	int i, ii;
	int count = 0;
	int sum = 0;
	for (i=low; i <=up; i++) {
		int isprime = 1;
		for (ii=2; ii<i; ii++) {
			if (i % ii == 0) {
				isprime = 0;
				break;
			} 
		}
		if (isprime == 1) {
			count ++;
			sum += i;
			//printf("%d\n", i);
		}
	}
	printf("%d %d\n", count, sum);
	
	
	return 0;
}
