// 鞍点（5分）
// 题目内容：
// 给定一个n*n矩阵A。矩阵A的鞍点是一个位置（i，j），在该位置上的元素是第i行上的最大数，第j列上的最小数。一个矩阵A也可能没有鞍点。
// 你的任务是找出A的鞍点。
// 输入格式:
// 输入的第1行是一个正整数n, （1<=n<=100），然后有n行，每一行有n个整数，同一行上两个整数之间有一个或多个空格。
// 输出格式：
// 对输入的矩阵，如果找到鞍点，就输出其下标。下标为两个数字，第一个数字是行号，第二个数字是列号，均从0开始计数。
// 如果找不到，就输出
// NO
// 题目所给的数据保证了不会出现多个鞍点。
// 输入样例：
// 4 
// 1 7 4 1 
// 4 8 3 6 
// 1 6 1 2 
// 0 7 8 9
// 输出样例：
// 2 1

#include <stdio.h>
#define n 4

int main() {
	
	int matrix[n][n];
	
	//input the matrix
	int i, j;
	int num;
	for (i=0; i<n; i++) {
		for (j=0; j<n; j++) {
			scanf("%d", &num);
			matrix[i][j] = num;
		}
	}
	
	/*
	for (i=0; i<n; i++){
		for (j=0; j<n; j++) {
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}
	*/
	//find the point
		//check the rows
	int maxnum[2][n];
	for (i=0; i<n; i++) {
		maxnum[0][i] = matrix[i][0];
		for (j=1; j<n; j++) {
			if (maxnum[0][i] < matrix[i][j]) {
				maxnum[0][i] = matrix[i][j];
				maxnum[1][i] = j;
				//printf("%d\n", maxnum[1][i]);

			}
		}
	}
	
	/*
	for (i=0; i<n; i++) {
		printf("%d ", maxnum[0][i]);
	}printf("\n");
	for (i=0; i<n; i++) {
		printf("%d ", maxnum[1][i]);
	}printf("\n");
	*/
	
	//check the columns
	int r = 0;
	for (i=0; i<n; i++) {
		int ret = 0;
		for (j=0; j<n; j++) {
			if (maxnum[0][i]> matrix[j][maxnum[1][i]]) {
			ret++;
			}
		}
		if (ret == 0) {
			printf("%d %d", i, maxnum[1][i]);		
			r = 1;
			break;
		}
	}
	
	if (r == 0) {
		printf("NO");
	}
	
	return 0;
}

