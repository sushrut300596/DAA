#include <stdio.h>

int binarySearch(int a[], int x, int l, int h) {
	int mid;
	if(l > h)
		return -1;
	else {
		mid = (l + h)/2;
		if(a[mid] == x)
			return mid;
		else if(a[mid] < x)
			return binarySearch(a, x, mid + 1, h);
		else
			return binarySearch(a, x, l, mid - 1);
	}
}

int main() {
	int n, x, i, res;
	printf("Enter how many numbers in array : ");
	scanf("%d", &n);
	int a[n];
	printf("Enter %d numbers in ascending order : \n", n);
	for(i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	printf("The Array is : \n");
	for(i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}
	printf("\nEnter the number from the array which you want to find : ");
	scanf("%d", &x);
	res = binarySearch(a, x, 0, n - 1);
	if(res == -1)
		printf("Entered number is not present in array\n");
	else
		printf("Entered number found at position %d\n", (res + 1));
}