#include <stdio.h>

int main() {
	// enter the array
	int n=10, i, input=0;;
	int array[10] = {0};
	for (i=0; i<n; i++) {
		scanf("%d", &input);
		array[i] = input;
	}
	
	//bubble sort
	int j;
	for (i=0; i<n-1; i++) {
		for (j=0; j<n-i-1; j++) {
			if (array[j] > array[j+1]) {
				int t = array[j];
				array[j] = array[j+1];
				array[j+1] = t;
			}
		}
	}
	
	//print
	for (i=0; i<n; i++) {
		printf("%d ", array[i]);
	}
	
	return 0;
}

