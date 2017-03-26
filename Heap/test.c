#include<stdio.h>
#include "heap.h"
#include<stdlib.h>

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

/*
void printQueue(Queue *que) {
        Node *node = que->start;
        for(;node; node=node->next) {
                HeapNode * hn = (HeapNode *)node->data;
                printf("->%d",*(int *)hn->data);
        }
}
*/

void testIntHeap() {
	int a = 10;
        int b = 20;
        int c1 = 5;
        int c2 = 15;
        int c3 = 25;
        int c4 = 21;
        void *num1 = &a;
        void *num2 = &b;

	Heap *heap = createHeap(&campInt, &printMyData);
        insertHeapNode(heap, num1);
        insertHeapNode(heap, num2);
        insertHeapNode(heap, &c1);
        insertHeapNode(heap, &c2);
        printf("\nAfter 4 insert");
        printHeap(heap, heap->root);

	removeHeapNode(heap);
        removeHeapNode(heap);
        removeHeapNode(heap);
	printf("\nAfter 3 remove");
	printHeap(heap, heap->root);

        removeHeapNode(heap);
        printf("\nAfter 4 remove");
        printHeap(heap, heap->root);

        removeHeapNode(heap);
        printf("\nAfter 5 Remove");
        printHeap(heap, heap->root);

	insertHeapNode(heap, &c3);
        insertHeapNode(heap, &c4);
        printf("\nAfter 2 insert");
        printHeap(heap, heap->root);

        removeHeapNode(heap);
        printf("\nAfter 1 remove");
        printHeap(heap, heap->root);

        removeHeapNode(heap);
        printf("\nAfter 2 remove");
        printHeap(heap, heap->root);
}

int campString(void *s1, void *s2) {
	char *str1 = (char *) s1;
	char *str2 = (char *) s2;
	while(*str1 != '\0' && *str2 != '\0') {
		if (*str1 < *str2)
			return 1;
		else if (*str1 > *str2)
			return 0;
		str1++;
		str2++;
	}
	if (*str1 == '\0' && *str2 == '\0') 
		return 0;
	else if (*str1 == '\0')
		return 1;
	else
		return 0;
}
void printMyString(void *data) {
	printf("%s", (char *)data);
}

void testStringHeap() {
	Heap *heap = createHeap(&campInt, &printMyString);
	char *s1 = (char *)malloc(sizeof(char));
	s1 = "Hi!";
	char *s2 = (char *)malloc(sizeof(char));
	s2 = "I am Sanket.";
	char *s3 = (char *)malloc(sizeof(char));
	s3 = "How are you.";
	char *s4 = (char *)malloc(sizeof(char));
	s4 = "What are your views on void pointers.";
	char *s5 = (char *)malloc(sizeof(char));
	s5 = "Isn\'t if amazing.";
	char *s6 = (char *)malloc(sizeof(char));
	s6 = "I bet you like them.";
	char *s7 = (char *)malloc(sizeof(char));
	s7 = "OK. Bye.";
	
	char *tmp = NULL;
	insertHeapNode(heap, s1);
	insertHeapNode(heap, s2);
	insertHeapNode(heap, s3);
	insertHeapNode(heap, s4);
        
	printf("\nAfter 4 insert");
        printHeap(heap, heap->root);
        
	tmp = (char *)removeHeapNode(heap);
	printf("\nRemoved: %s\n", tmp);
        tmp = (char *)removeHeapNode(heap);
	printf("\nRemoved: %s\n", tmp);
        tmp = (char *)removeHeapNode(heap);
	printf("\nRemoved: %s\n", tmp);
        printf("\nAfter 3 remove");
        printHeap(heap, heap->root);
	
	insertHeapNode(heap, s5);
	insertHeapNode(heap, s6);
        printf("\nAfter 2 insert");
        printHeap(heap, heap->root);
        
	tmp = (char *)removeHeapNode(heap);
	printf("\nRemoved: %s\n", tmp);
        tmp = (char *)removeHeapNode(heap);
	printf("\nRemoved: %s\n", tmp);
        tmp = (char *)removeHeapNode(heap);
	printf("\nRemoved: %s\n", tmp);
        printf("\nAfter 3 remove");
        printHeap(heap, heap->root);
        
	tmp = (char *)removeHeapNode(heap);
        printHeap(heap, heap->root);
	printf("\nRemoved: %s\n", tmp);
}

int main() {
	printf("\n Test integers");
        testIntHeap();
	printf("\n Test Strings");
	testStringHeap();
	return 0;
}
