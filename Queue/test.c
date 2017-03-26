#include<stdio.h>
#include "queue.h"
#include<stdlib.h>
void printQueue(Queue *que) {
	printf("\n");
	for(Node *tmp = que->start;tmp; tmp = tmp->next){
		printf("%s ", (char *)tmp->data);
	}
}

void printReverseQueue(Queue *que) {
	printf("\n");
	for(Node *tmp = que->end;tmp; tmp = tmp->prev){
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
        printReverseQueue(que);
        void *tmp = deQueueEnd(que);
        printf("\n%s", (char *)(tmp));
        printQueue(que);
        printReverseQueue(que);
        tmp = deQueue(que);
        printf("\n%s", (char *)(tmp));
        printQueue(que);
        printReverseQueue(que);
        tmp = deQueue(que);
        printf("\n%s", (char *)(tmp));
        printQueue(que);
        tmp = deQueue(que);
        if (tmp)
                printf("\n%d", *(int *)tmp);
        printQueue(que);
	data = (char *)malloc(sizeof(char));
	data = "Ahemadnagar";
        enQueue(que, data);
        printQueue(que);
        printReverseQueue(que);
	/*
	int a = 10;
	void * b = &a;
	printf("%d", *(int *)b);
	*/
}
