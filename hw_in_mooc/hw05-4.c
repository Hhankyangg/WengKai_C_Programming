// 求a的连续和(15)
// 时间限制
// 400 ms
// 内存限制
// 65536 kB
// 代码长度限制
// 8000 B
// 判题程序
// Standard
// 作者
// 翁恺（浙江大学）
// 输入两个整数a和n，a的范围是[0,9]，n的范围是[1,8]，求数列之和S = a+aa+aaa+...+aaa...a（n个a）。如a为2、n为8时输出的是2+22+222+...+22222222的和。
// 输入格式：
// 输入在一行中给出两个整数，先后表示a和n。
// 输出格式：
// 在一行中输出要求的数列之和。
// 输入样例：
// 2 4
// 输出样例：
// 2468

#include <stdio.h>
#include <math.h>

int main() {
	int a, n;
	scanf("%d %d", &a, &n);
	int sum = 0;
	
	n = pow(10, n-1);
	for (n; n!=0; n/=10) {
		int i = n;
		int tmp = 0;
		for (i; i!=0; i/=10) {
			tmp += a*i;
		}
		sum += tmp;
	}
	printf("%d", sum);
	
	
	return 0;
}
