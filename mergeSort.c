#include <stdio.h>

void merge(int a[], int start, int mid, int end) {
	int i, j, k;
	int n1 = mid - start + 1;
	int n2 = end - mid;
	int L[n1], R[n2];
	for(i = 0; i < n1; i++)
		L[i] = a[start + i];
	for(j = 0; j < n2; j++)
		R[j] = a[mid + 1 + j];
	i = 0;
	j = 0;
	k = start;
	while(i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			a[k] = L[i];
			i++;
		}
		else {
			a[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1) {
		a[k] = L[i];
		i++;
		k++;
	}
	while(j < n2) {
		a[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int a[], int start, int end) {
	if(start < end) {
		int mid = (start + end)/2;
		mergeSort(a, start, mid);
		mergeSort(a, mid + 1, end);
		merge(a, start, mid, end);
	}
}

void readArray(int a[], int n) {
	int i;
	for(i = 0; i < n; i++)
		scanf("%d", &a[i]);
}

void printArray(int a[], int n) {
	int i;
	for(i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main(){
	int n;
	printf("Enter how many numbers in array : ");
	scanf("%d", &n);
	int a[n];
	printf("Enter %d numbers in Array : \n", n);
	readArray(a, n);
	printf("The Array is : \n");
	printArray(a, n);
	mergeSort(a, 0, n - 1);
	printf("Sorted Array is : \n");
	printArray(a, n);
}