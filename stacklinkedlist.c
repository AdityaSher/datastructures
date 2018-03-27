// C program for linked list implementation of stack
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct StackNode{
	int data;
	struct StackNode* next;
};
 
typedef struct StackNode SNODE;
 
 //creation of new node in stack
SNODE* newNode(int data){
	SNODE* snode=(SNODE*)malloc(sizeof(SNODE));
	
	snode->data=data;
	snode->next=NULL;
	return snode;
}

//check whether stack is empty
int isEmpty(SNODE *root){
	return !root;
}

//add new node!
void push(SNODE** root, int data){
	SNODE* snode=newNode(data);
	 snode->next = *root;
	*root=snode;
	printf("%d pushed to stack \n",data);
} 

int pop(SNODE** root){
	if(isEmpty(*root))
		return INT_MIN;
	SNODE* temp=*root;
	*root=(*root)->next;
	int popped=temp->data;
	free(temp);
	return popped;
}

int peek(SNODE* root){
	if(isEmpty(root))
		return INT_MIN;
	return root->data;
}

int main(){
	SNODE* root=NULL;
	push(&root, 10);
    push(&root, 20);
    push(&root, 30);
 
    printf("%d popped from stack\n", pop(&root));
 
    printf("Top element is %d\n", peek(root));
 
    return 0;

}

