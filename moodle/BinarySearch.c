#include <stdio.h>

int BinarySearch(int list[], int leftnum, int rightnum, int x) {
	while (leftnum <= rightnum) {
		int mid = (leftnum + rightnum) / 2;
		if (x == list[mid]) {
			return mid;
		}
		else if (x < list[mid]) {
			rightnum = mid - 1;
		}
		else {
			leftnum = mid + 1;
		}
	}
	return -1;	// if not find
}


