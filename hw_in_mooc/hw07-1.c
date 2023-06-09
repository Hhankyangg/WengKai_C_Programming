// 多项式加法（5分）
// 题目内容：
// 一个多项式可以表达为x的各次幂与系数乘积的和，比如：
// 2x6+3x5+12x3+6x+20
// 现在，你的程序要读入两个多项式，然后输出这两个多项式的和，也就是把对应的幂上的系数相加然后输出。
// 程序要处理的幂最大为100。
// 输入格式:
// 总共要输入两个多项式，每个多项式的输入格式如下：
// 每行输入两个数字，第一个表示幂次，第二个表示该幂次的系数，所有的系数都是整数。第一行一定是最高幂，最后一行一定是0次幂。
// 注意第一行和最后一行之间不一定按照幂次降低顺序排列；如果某个幂次的系数为0，就不出现在输入数据中了；0次幂的系数为0时还是会出现在输入数据中。
// 输出格式：
// 从最高幂开始依次降到0幂，如：
// 2x6+3x5+12x3-6x+20
// 注意其中的x是小写字母x，而且所有的符号之间都没有空格，如果某个幂的系数为0则不需要有那项。
// 输入样例：
// 6 2
// 5 3
// 3 12
// 1 6
// 0 20
// 6 2
// 5 3
// 2 12
// 1 6
// 0 20
// 输出样例：
// 4x6+6x5+12x3+12x2+12x+40

#include <stdio.h>

int main() {
	
	int polynomial[2][100] = {0};
	int coefficient, power;
	int max[2] = {0};
	int i, j;
	
	//initialize the polynomial
	int cache;
	scanf("%d %d", &power, &coefficient);
	for (i=0; i<2; i++){
		max[i] = power;
		do {
			cache = power;
			polynomial[i][power] = coefficient;
			if (power==0 && i ==1) {
				break;
			}
			scanf("%d %d", &power, &coefficient);
		}while (power < cache);
	}
	
	//plus two polynomials
		//find the max power
	int finalmax;
	if (max[0] > max[1]) {
		finalmax = max[0];
	}
	else {
		finalmax = max[1];
	}
		//traversal two ploynomials
	for (i=finalmax; i>-1; i--) {
		if (polynomial[0][i]+polynomial[1][i] != 0 && i!=0) {
			if (polynomial[0][i]+polynomial[1][i] > 0 && i != finalmax) {
				printf("+");
			}
			printf("%dx%d", polynomial[0][i]+polynomial[1][i], i);
			
		}
		else if (polynomial[0][i]+polynomial[1][i] != 0 && i == 0) {
			if (polynomial[0][i]+polynomial[1][i] > 0) {
				printf("+");
			}
			printf("%d", polynomial[0][i]+polynomial[1][i]);
		}
	}

	return 0;
}
