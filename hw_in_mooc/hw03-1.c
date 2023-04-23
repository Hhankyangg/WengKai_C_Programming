// 超速判断(10)
// 时间限制
// 400 ms
// 内存限制
// 65536 kB
// 代码长度限制
// 8000 B
// 判题程序
// Standard
// 作者
// 杨起帆（浙江大学城市学院）
// 模拟交通警察的雷达测速仪。输入汽车速度，如果速度超出60 mph，则显示“Speeding”，否则显示“OK”。
// 输入格式：
// 输入在一行中给出1个不超过500的非负整数，即雷达测到的车速。
// 输出格式：
// 在一行中输出测速仪显示结果，格式为：“Speed: V - S”，其中V是车速，S或者是Speeding、或者是OK。
// 输入样例1：
// 40
// 输出样例1：
// Speed: 40 - OK
// 输入样例2：
// 75
// 输出样例2：
// Speed: 75 - Speeding

#include <stdio.h>

int main(){
	int v;
	scanf("%d", &v);
	if (v >= 60) {
		printf("Speed: %d - Speeding", v);
	}
	else {
		printf("Speed: %d - OK",v);
	}
	
	return 0;
}
