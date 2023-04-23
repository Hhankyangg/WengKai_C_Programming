// 成绩转换(15)
// 时间限制
// 400 ms
// 内存限制
// 65536 kB
// 代码长度限制
// 8000 B
// 判题程序
// Standard
// 作者
// 沈睿（浙江大学）
// 本题要求编写程序将一个百分制成绩转换为五分制成绩。转换规则：
// 大于等于90分为A；
// 小于90且大于等于80为B；
// 小于80且大于等于70为C；
// 小于70且大于等于60为D；
// 小于60为E。
// 输入格式：
// 输入在一行中给出1个整数的百分制成绩。
// 输出格式：
// 在一行中输出对应的五分制成绩。
// 输入样例：
// 90
// 输出样例：
// A

#include <stdio.h>

int main(){
	int score;
	scanf("%d", &score);
	switch(score/10){
		case 6 :
			printf("D");
			break;
		case 7 :
			printf("C");
			break;
		case 8 :
			printf("B");
			break;
		case 9 : case 10 :
			printf("A");
			break;
		default :
			printf("E");
			break;
	}
	
	return 0;
}
