#include<stdio.h>
#include<stdlib.h>
#include "heap.h"
#include "../Queue/queue.h"

Heap *createHeap(int (*fp)(void *, void *), void (*printFunc)(void *)) {
	Heap *heap = (Heap *)malloc(sizeof(Heap));
	if (!heap) {
		printf("Malloc Failed: Create Heap!!!!");
		exit(0);
	}
	heap->root = NULL;
	heap->size = 0;
	heap->dataCamp = fp;
	heap->printData = printFunc;
	heap->que = createQueue();
	return heap;
}

HeapNode *createHeapNode(void *data) {
	HeapNode *node = (HeapNode *)malloc(sizeof(HeapNode));
	if (!node) {
		printf("Malloc Failed: Create Heap Node");
		exit(0);
	}
	node->data = data;
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	return node;
}

HeapNode *getParent(Queue *que) {
	HeapNode *parent = NULL;
	if (!que->start)
		parent = NULL;
	else{
		HeapNode *tmp = (HeapNode *)que->start->data;
		if (tmp)
			parent = tmp;
	}
	return parent;
}

void swapNodeData(HeapNode *node1, HeapNode *node2) {
	void *tmp = node1->data;
	node1->data = node2->data;
	node2->data = tmp;
}

void bubbleUp(Heap *heap, HeapNode *node) {
	for(;node->parent;node = node->parent) {
		if(heap->dataCamp(node->data, node->parent->data))
			swapNodeData(node, node->parent);
		else
			break;
	}
}

void checkAndSwap(Heap *heap, HeapNode *node1, HeapNode *node2)	{
	if(!node1 || !node2) {
		printf("NULL parameter: Heap checkAndSwap -> <Line:59 heap.c>");
		exit(0);
	}
	if(heap->dataCamp(node1->data, node2->data))
		swapNodeData(node1, node2);
}

void settleDown(Heap *heap, HeapNode *root) {
	if(!root)
		return;
	if(root->left == NULL && root->right == NULL){
		return;
	}
	if(root->left && root->right){
		if(heap->dataCamp(root->left->data, root->right->data)) {
			//checkAndSwap(heap, root->left, root);
			if(heap->dataCamp(root->left->data, root->data)){
				swapNodeData(root->left, root);
				settleDown(heap, root->left);
			}
		}
		else {
			if(heap->dataCamp(root->right->data, root->data)) {
				swapNodeData(root->right, root);
				settleDown(heap, root->right);
			}
		}
	}
	else if(!root->right) {
		if(heap->dataCamp(root->left->data, root->data)){
			swapNodeData(root->left, root);
			settleDown(heap, root->left);
		}
	}
	else {
		printf("Heap left tree is NULL but not right: Heap settleDown -> <Line:79 heap.c>");
	}		
}

void insertHeapNode(Heap *heap, void *data) {
	HeapNode *parent = NULL;
	HeapNode *node = createHeapNode(data);
	parent = getParent(heap->que);
	if (!parent){
		heap->root = node;
	}
	else if(!parent->left){
		parent->left = node;
	}
	else{
		parent->right = node;
		deQueue(heap->que);
	}
	enQueue(heap->que, node);
	node->parent = parent;
	bubbleUp(heap, node);
}

void *removeHeapNode(Heap *heap) {
	if (!heap)
		return NULL;
	if (!heap->root)
		return NULL;
	HeapNode *last = (HeapNode *)deQueueEnd(heap->que);
	if (!last) {
		heap->root = NULL;
		return NULL;
	}
	void *data = heap->root->data;
	heap->root->data = last->data;
	if(last->parent) {
		if(last->parent->left == last)
			last->parent->left = NULL;
		if(last->parent->right == last) {
			last->parent->right = NULL;
			enQueueStart(heap->que, last->parent);
		}
	}
	else {
		heap->root = NULL;
	}
	free(last);
	settleDown(heap, heap->root);
	return data;	
}

void printHeap(Heap *heap, HeapNode *root) {
        if(root) {
		printf("->");
                heap->printData(root->data);
                printHeap(heap, root->left);
                printHeap(heap, root->right);
        }
}

/*
int campInt(void *num1, void *num2) {
	int *p1 = (int *) num1;
	int *p2 = (int *) num2;
	if (*p1 < *p2)
		return 1;
	return 0;
}

void printHeap(Heap *heap, HeapNode *root) {
	if(root){
		heap->printData(root->data);
		printHeap(heap, root->left);
		printHeap(heap, root->right);
	}
}

void printQueue(Queue *que) {
	Node *node = que->start;
	for(;node; node=node->next) {
		HeapNode * hn = (HeapNode *)node->data;
		printf("->%d",*(int *)hn->data);
	}
}

int main() {
	int a = 10;
	int b = 20;
	int c1 = 5;
	int c2 = 15;
	int c3 = 25;
	int c4 = 21;
	void *num1 = &a;
	void *num2 = &b;
	int c = campInt(num1, num2);
	Heap *heap = createHeap(&campInt);
	insertHeapNode(heap, num1);
	printf("\n");
	printHeap(heap->root);
	insertHeapNode(heap, num2);
	printf("\n");
	printHeap(heap->root);
	insertHeapNode(heap, &c1);
	printf("\n");
	printHeap(heap->root);
	insertHeapNode(heap, &c2);
	printf("\n");
	printHeap(heap->root);
	removeHeapNode(heap);
	printf("\n");
	printHeap(heap->root);
	removeHeapNode(heap);
	printf("\n");
	printHeap(heap->root);
	removeHeapNode(heap);
	printf("\n");
	printHeap(heap->root);
	removeHeapNode(heap);
	printf("\n");
	printHeap(heap->root);
	removeHeapNode(heap);
	printf("\n");
	printHeap(heap->root);
	if(heap->que)
		printf("Queue there");
	else
		printf("no queue");
	insertHeapNode(heap, &c3);
	printf("\n");
	printHeap(heap->root);
	printHeap(heap->root);
	insertHeapNode(heap, &c4);
	printf("\n Heap lz");
	printHeap(heap->root);
	removeHeapNode(heap);
	printf("\n");
	printHeap(heap->root);
	removeHeapNode(heap);
	printf("\nsdjhfejrkherhg");
	printHeap(heap->root);
	return 0;
}
*/
