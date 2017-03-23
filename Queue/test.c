#include<stdio.h>
#include "queue.h"
#include<stdlib.h>
void printQueue(Queue *que) {
	printf("\n");
	for(Node *tmp = que->start;tmp; tmp = tmp->next){
		printf("%s ", (char *)tmp->data);
	}
}

int main() {
        Queue *que = NULL;
        if(que == NULL){
                que = createQueue();
        }
        //int *data = (int *)malloc(sizeof(int));
	char *data = (char *)malloc(sizeof(char));
	data = "Sanket";
        enQueue(que, data);
        //data = (int *)malloc(sizeof(int));
	//*data = 20;
	data = (char *)malloc(sizeof(char));
	data = "Payghan";
        enQueue(que, data);
        //data = (int *)malloc(sizeof(int));
	//*data = 30;
	data = (char *)malloc(sizeof(char));
	data = "Shevgaon";
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
