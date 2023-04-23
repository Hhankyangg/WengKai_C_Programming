// 水仙花数(20)
// 时间限制
// 2000 ms
// 内存限制
// 65536 kB
// 代码长度限制
// 8000 B
// 判题程序
// Standard
// 作者
// 徐镜春（浙江大学）
// 水仙花数是指一个N位正整数（N>=3），它的每个位上的数字的N次幂之和等于它本身。例如：153 = 13 + 53+ 33。本题要求编写程序,计算所有N位水仙花数。
// 输入格式：
// 输入在一行中给出一个正整数N（3<=N<=7）。
// 输出格式：
// 按递增顺序输出所有N位水仙花数，每个数字占一行。
// 输入样例：
// 3
// 输出样例：
// 153
// 370
// 371
// 407

#include <stdio.h>

int main(){
	int digit;
	scanf("%d", &digit);


	int up = 0; int low = 1; int i;
	for ( i=1; i<digit; i++ ) {
		low *= 10;
	}
	for ( i=1; i<=digit; i++ ) {
		up = up*10 + 9;
	}
	
	int shuzi;
	int ii;

	for ( i=low; i<=up; i++ ) {
	 	int mirror = i;
	 	int re = 0;
	 	while(mirror > 0) {
	 		shuzi = mirror % 10;
	 		int mi = 1;
	 		for ( ii=1; ii<=digit; ii++ ){
	 			mi *= shuzi;
			}
	 		re = re + mi;
	 		mirror /= 10;
		}
	 	if (re == i) {
	 		printf("%d\n", i);
		}
	}
	
	return 0;
}
