#include<stdio.h>
#include "queue.h"
#include<stdlib.h>
void printQueue(Queue *que) {
	printf("\n");
	for(Node *tmp = que->start;tmp; tmp = tmp->next){
		printf("%d ", *(int *)tmp->data);
	}
}

int main() {
        Queue *que = NULL;
        if(que == NULL){
                que = createQueue();
        }
        int *data = (int *)malloc(sizeof(int));
	*data = 10;
        enQueue(que, data);
        data = (int *)malloc(sizeof(int));
	*data = 20;
        enQueue(que, data);
        data = (int *)malloc(sizeof(int));
	*data = 30;
        enQueue(que, data);
        printQueue(que);
        void *tmp = deQueue(que);
        printf("\n%d", *(int *)(tmp));
        printQueue(que);
        tmp = deQueue(que);
        printf("\n%d", *(int *)(tmp));
        printQueue(que);
        tmp = deQueue(que);
        printf("\n%d", *(int *)(tmp));
        printQueue(que);
        tmp = deQueue(que);
        if (tmp)
                printf("\n%d", *(int *)tmp);
        printQueue(que);
	/*
	int a = 10;
	void * b = &a;
	printf("%d", *(int *)b);
	*/
}
