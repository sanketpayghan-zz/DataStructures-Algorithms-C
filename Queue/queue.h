#ifndef MY_H_   /* Include guard */
#define MY_H_

typedef struct node {
        //int data;
	void *data;
        struct node *next;
        struct node *prev;
}Node;

typedef struct Queue {
        Node *start;
        Node *end;
}Queue;

Node* createNode(void *data);
Queue* createQueue();
void enQueue(Queue *que, void *data);
void enQueueStart(Queue *que, void *data);
void printQueue(Queue *que);
void* deQueue(Queue *que);  /* An example function declaration */
void* deQueueEnd(Queue *que);  /* An example function declaration */

#endif // MY_H_
