// 打印九九口诀表(15)
// 时间限制
// 400 ms
// 内存限制
// 65536 kB
// 代码长度限制
// 8000 B
// 判题程序
// Standard
// 作者
// 徐镜春（浙江大学）
// 下面是一个完整的下三角九九口诀表：
// 1*1=1   
// 1*2=2   2*2=4   
// 1*3=3   2*3=6   3*3=9   
// 1*4=4   2*4=8   3*4=12  4*4=16  
// 1*5=5   2*5=10  3*5=15  4*5=20  5*5=25  
// 1*6=6   2*6=12  3*6=18  4*6=24  5*6=30  6*6=36  
// 1*7=7   2*7=14  3*7=21  4*7=28  5*7=35  6*7=42  7*7=49  
// 1*8=8   2*8=16  3*8=24  4*8=32  5*8=40  6*8=48  7*8=56  8*8=64  
// 1*9=9   2*9=18  3*9=27  4*9=36  5*9=45  6*9=54  7*9=63  8*9=72  9*9=81  
// 本题要求对任意给定的1位正整数N，输出从1*1到N*N的部分口诀表。
// 输入格式:
// 输入在一行中给出一个正整数N（1<=N<=9）。
// 输出格式：
// 输出下三角N*N部分口诀表，其中等号右边数字占4位、左对齐。
// 输入样例：
// 4
// 输出样例：
// 1*1=1   
// 1*2=2   2*2=4   
// 1*3=3   2*3=6   3*3=9   
// 1*4=4   2*4=8   3*4=12  4*4=16 

#include <stdio.h>

int main(){
	/*
	n=3
	for 1-3
	int zuobian = 0,youbian = i
		for 
		
	
	*/
	
	int n;
	scanf("%d", &n);
	
	int i, ii;
	for ( i=1; i<=n; i++ ) {
		int leftnum = 0; int rightnum = i;
		for ( ii=1; ii<=i; ii++ ) {
			leftnum += 1;
			if (leftnum*rightnum < 10) {
				printf("%d*%d=%d   ", leftnum, rightnum, leftnum*rightnum);
			}
			else {
				printf("%d*%d=%d  ", leftnum, rightnum, leftnum*rightnum);
			}
		}
		printf("\n");
	}
	
	return 0;
}
