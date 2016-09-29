
#include<stdio.h>
#include<stdlib.h>

typedef void *Value;

typedef struct ArrayList{
	void **data;
	unsigned int length;
	unsigned int _allocated;
}ArrayList;

ArrayList *CreateArrayList(){
	int allocated = 3;
	ArrayList *list = (ArrayList *)malloc(sizeof(ArrayList));
	if (list == NULL)
		return NULL;

	list->_allocated = 3;
	list->length = 0;
	list->data = malloc(allocated * sizeof(Value));
	return list;
}

void _resizeArrayList(ArrayList *list, long length){
	printf("inside resize");
	list->_allocated = length;
	list->data = realloc(list->data, list->_allocated * sizeof(Value));
}

void _moveForward(ArrayList *list, unsigned int index){
	if (list->length == 0)
		return;
	unsigned int i = 0;
	for(i = list->length; i > index; i--)
		list->data[i] = list->data[i - 1];
}

void _moveBackward(ArrayList *list, unsigned int index){
	if (list->length == 1)
		return;
	for(unsigned int i = index; i < list->length - 1; i++)
		list->data[i] = list->data[i + 1];
}

void _insert_at(ArrayList *list, unsigned int index, void *data){
	int i = 0;
	if (list == NULL)
		return;
	if (list->length + 1 > list->_allocated)
		_resizeArrayList(list, list->_allocated * 2);
	_moveForward(list, index);
	list->data[index] = data;
	list->length++;
}

void *_remove_at(ArrayList *list, unsigned int index){
	if (index > list->length)
		return NULL;
	void *item = list->data[index];
	_moveBackward(list, index);
	list->length--;
	if (list->length < list->_allocated / 2){
		_resizeArrayList(list, list->_allocated / 2);
	}
	return item;
}

void append(ArrayList *list, void *data){
	_insert_at(list, list->length, data);
}

void *pop(ArrayList *list){
	return _remove_at(list, list->length - 1);
}

void printArrayList(ArrayList *list){
	for(unsigned int i = 0; i < list->length; i++){
		char *c = (char *)list->data[i];
		printf("\n%u %u %s", i, list->length, c);
	}
}

int main(){
	ArrayList *list = CreateArrayList();
	//int data = 10;
	//int data1 = 20;
	//int data3 = 30;
	//int data4 = 40;
	//append(list, &data);
	//append(list, &data1);
	//append(list, &data3);
	//append(list, &data4);
	//printArrayList(list);
	//int *d = (int *)pop(list);
	//d = (int *)pop(list);
	//d = (int *)pop(list);
	//d = (int *)pop(list);
	//printArrayList(list);
	//append(list, &data);
	//append(list, &data1);
	//printArrayList(list);
	char *str1 = "Sanket";
	char *str2 = "Payghan";
	char *str3 = "is";
	char *str4 = "my name";
	append(list, str1);
	append(list, str2);
	append(list, str3);
	append(list, str4);
	printArrayList(list);
	char *d = (char *)pop(list);
	printf("%s", d);
	printArrayList(list);
	d = (char *)pop(list);
	printf("%s", d);
	printArrayList(list);
	//d = (int *)pop(list);
}
