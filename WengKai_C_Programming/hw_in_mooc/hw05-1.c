// 求序列前N项和(15)
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
// 本题要求编写程序,计算序列 2/1+3/2+5/3+8/5+... 的前N项之和。注意该序列从第2项起，每一项的分子是前一项分子与分母的和，分母是前一项的分子。
// 输入格式：
// 输入在一行中给出一个正整数N。
// 输出格式：
// 在一行中输出部分和的值，精确到小数点后2位。题目保证计算结果不超过双精度范围。
// 输入样例：
// 20
// 输出样例：
// 32.66

#include <stdio.h>

int main () {
	int n, i;
	double sum = 0;
	scanf("%d", &n);
	int fenzi = 2, fenmu = 1;
	int tmp;
	for (i=1; i<=n; i++) {
		sum += fenzi*1.0/fenmu;
		tmp = fenzi;
		fenzi = fenzi + fenmu;
		fenmu = tmp;
	}
	printf("%.2f", sum);
	
	
	return 0;
}
