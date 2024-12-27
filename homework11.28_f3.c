#include<stdio.h>
#include<stdlib.h>
typedef struct list_item{ //define a struct
	int data;
	struct list_item *next;
}list_item;
void erase_list(list_item *head){  //free a memory
	list_item*current = head;
	list_item*next;
        while(current != NULL){
		next = current->next;
	        free(current);
	        current = next;
	}
}
int main(){
	list_item *head = (list_item*)malloc(sizeof(list_item));//create a chaintable
	if(head == NULL){
		fprintf(stderr,"Failed to allocate memory for head\n");
		return 1;
	}
	list_item *node1 = (list_item*)malloc(sizeof(list_item));
	if(node1 == NULL){
		fprintf(stderr,"Failed to allocate memory for node1\n");
		free(head);
		return 1;
	}
	list_item *node2 = (list_item*)malloc(sizeof(list_item));
	if(node2 == NULL){
		fprintf(stderr,"Failed to allocate memory for node2\n");
		free(head);
		free(node1);
		return 1;
	}
	head->data = 0;  //initialize the chain table
	head->next = node1;
	node1->data = 1;
	node1->next = node2;
	node2->data = 2;
	node2->next = NULL;
	erase_list(head);//destroy the chain table
	return 0;
}
