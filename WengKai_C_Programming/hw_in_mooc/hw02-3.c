// 逆序的三位数(10)
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
// 程序每次读入一个正3位数，然后输出按位逆序的数字。注意：当输入的数字含有结尾的0时，输出不应带有前导的0。比如输入700，输出应该是7。
// 输入格式：
// 每个测试是一个3位的正整数。
// 输出格式：
// 输出按位逆序的数。
// 输入样例：
// 123
// 输出样例：
// 321

#include <stdio.h>

int main(){
	int zhengxu, nixu;
	scanf("%d", &zhengxu);
	nixu = zhengxu/100 + (zhengxu/10-zhengxu/100*10)*10 + (zhengxu%100-(zhengxu/10-zhengxu/100*10)*10)*100;
	printf("%d",nixu);
	
	return 0;
}
