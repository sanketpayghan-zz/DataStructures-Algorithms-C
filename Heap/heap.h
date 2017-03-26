#include<stdio.h>
#include "../Queue/queue.h"

typedef struct HeapNode {
	void *data;
	struct HeapNode *left;
	struct HeapNode *right;
	struct HeapNode *parent;
}HeapNode;

typedef struct Heap {
	HeapNode *root;
	int size;
	int (*dataCamp)(void *arg1, void *arg2);
	/*
        For Min Heap::
                Campare function must return 1 if arg1 is smaller than( i.e. <) arg2.
                For all other cases it should return 0.
        For Max Heap::
                Compare function must return 1 if arg1 is greater than (i.e. >) arg2.
                For all other cases ir should return 0.
        */
	void (*printData)(void *);
	/*
	Print Function must type cast its argument to proer type and print.
	*/ 
	Queue *que;
}Heap;

Heap *createHeap(int (*fp)(void *, void *), void (*printFunc)(void *));

HeapNode *createHeapNode(void *data);

HeapNode *getRoot(Heap *heap);

void insertHeapNode(Heap *heap, void *data);

void *removeHeapNode(Heap *heap);

void printHeap(Heap *heap);
