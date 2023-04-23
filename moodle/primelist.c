#include <stdio.h>

int main() {
	int up, i, k;
	scanf("%d", &up);
	int prime[up+1];
	int len = sizeof(prime)/sizeof(prime[0]);
	
	//initialize the array
	for (i=0; i<len; i++) {
		prime[i] = 1;
	} 
	
	//judge the array
	for (i=2; i<len; i++) {
		if (prime[i]) {
			for (k=2; k*i<len; k++) {
				prime[k*i] = 0;
			}
		}
	}
	
	//print
	for (i=2; i<len; i++) {
		if (prime[i]) {
			printf("%d\t", i);
		}
	}
	
	return 0;
}
