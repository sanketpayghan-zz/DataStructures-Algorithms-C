
#include<stdio.h>
#include "../Heap/heap.h"

int campInt(void *num1, void *num2) {
        int *p1 = (int *) num1;
        int *p2 = (int *) num2;
        if (*p1 < *p2)
                return 1;
        return 0;
}

void printMyData(void *data) {
        printf("%d", *(int *)data);
}


void nearSorted(int input[], int output[], int k, int n) {
	Heap *heap = createHeap(&campInt, &printMyData);
	for (int i = 0; i < k; i++) {
		insertHeapNode(heap, &input[i]);
	}
	int *num = NULL;
	int j = 0;
	for(int i = k; i < n; i++, j++) {
		num = (int *)removeHeapNode(heap);
		insertHeapNode(heap, &input[i]);
		output[j] = *num;
	}
	while((num = (int *)removeHeapNode(heap)) != NULL) {
		output[j++] = *num;
	}
}

int main() {
	int k = 0;
	int n = 0;
	printf("\nEnter value of K and N:");
	scanf("%d %d", &k, &n);
	int arr[n], sorted[n];
	printf("\nEnter N elements:");
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);
	nearSorted(arr, sorted, k, n);
	printf("\nSorted Array");
	for (int i = 0; i < n; i++)
		printf("->%d", sorted[i]);
}	
