#include<stdio.h>
#include<stdlib.h>
#include "queue.h"
/*
typedef struct node {
	//int data;
	void *data
	struct node *next;
	struct node *prev;
}Node;

typedef struct Queue {
	Node *start;
	Node *end;
}Queue;
*/
Node* createNode(void* data) {
	Node *node = (Node *)malloc(sizeof(Node));
	if (!node) {
		printf("Malloc Failed: for new Node");
		exit(0);
	}
	node->data = data;
	node->next = NULL;
	return node;
}

Queue* createQueue() {
	Queue *temp = (Queue *)malloc(sizeof(Queue));
	if (!temp) {
		printf("Malloc Failed: for new Queue");
		exit(0);
	}
	temp->start = NULL;
	temp->end = NULL;
	return temp;
}

void enQueue(Queue *que, void* data) {
	Node *node = createNode(data);
	if (que->start == NULL && que->end == NULL) {
		que->start = node;
		que->end = node;
	}
	else {
		que->end->next = node;
		que->end = node;
	}
}

void* deQueue(Queue *que) {
	if (!que->start)
		return NULL;
	Node *tmp = que->start;
	que->start = que->start->next;
	return tmp->data;
}

/*
void printQueue(Queue *que) {
	printf("\n");
	for(Node *tmp = que->start;tmp; tmp = tmp->next){
		printf("%d ", tmp->data);
	}
}

int main() {
	Queue *que = NULL;
	if(que == NULL){
		que = createQueue();
	}
	int data = 10;
	enQueue(que, data);
	data = 20;
	enQueue(que, data);
	data = 30;
	enQueue(que, data);
	printQueue(que);
	Node *tmp = deQueue(que);
	printf("\n%d", tmp->data);
	printQueue(que);
	tmp = deQueue(que);
	printf("\n%d", tmp->data);
	printQueue(que);
	tmp = deQueue(que);
	printf("\n%d", tmp->data);
	printQueue(que);
	tmp = deQueue(que);
	if (tmp)
		printf("\n%d", tmp->data);
	printQueue(que);
}
*/
