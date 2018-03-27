//Implementation of stack using array

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack{
	int top; //indicates top value
	unsigned container; 
	int *array;
};

// function to create a stack of given capacity. It initializes size of stack as 0
typdedef struct Stack STACK;
struct Stack* createStack(unsigned capacity){
	STACK* stack=(STACK*)malloc(sizeof(STACK));
	stack->capacity=capacity;
	// Stack is empty when top is equal to -1
	stack->top=-1;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));
	return stack;    
}

//stack is full when top is equal ot last index of array [-1]

int isFull(STACK* stack){
return stack->top==stack->capacity -1;  //returns true or false
}

//Stack is empty when top is equal to -1
int isEmpty(STACK* stack)
{ return stack->top==-1}


//Function to add an item to stack. It increases top by 1
void push(struct Stack* stack, int item){
	if(isFull(stack))
		return;
	stack->array[++stack->top]=item; //increasing index of array- top value increases
	printf("%d pushed to stack \n",item);
}

//Function to remove an item from stack. It decreases top by 1
int pop(STRCUT stack){
	if(isEmpty(stack))	
		return INT_MIN;
}

    if (isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

