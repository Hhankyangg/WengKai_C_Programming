#include <stdio.h>

int main() {
	int array[21] = {10,11,12,13,14,15,16,17,18,19,110,111,112,113,114,115,116,117,118,119,120};
	int key, ret = -1;
	scanf("%d", &key);
	int leftnum = 0;
	int rightnum = sizeof(array)/sizeof(array[0])-1;
	while (rightnum > leftnum) {
		if (array[(rightnum+leftnum)/2] < key) {
			leftnum = (rightnum+leftnum)/2+1;
		} 
		else if (array[(rightnum+leftnum)/2] > key) {
			rightnum = (rightnum+leftnum)/2-1;
		} 
		else {
			ret = (rightnum+leftnum)/2;
			break;
		}
	}
	printf("%d", ret);
	return 0;
}

