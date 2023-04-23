#include <stdio.h>

int main() {
	// enter the array
	int n=10, i, input=0;;
	int array[10] = {0};
	for (i=0; i<n; i++) {
		scanf("%d", &input);
		array[i] = input;
	}
	
	//selection sort
	int j;
	for (i=1; i<n; i++) {
		int minid = i-1;
		for (j=i; j<n; j++) {
			if (array[minid] > array[j]) {
				minid = j;
			}
		}
		//swap
		int tmp = array[i-1];
		array[i-1] = array[minid];
		array[minid] = tmp;
	}
	
	//print
	for (i=0; i<n; i++) {
		printf("%d ", array[i]);
	}
	
	return 0;
}

