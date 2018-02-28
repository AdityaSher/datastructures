#include<stdio.h>
#include<stdlib.h>
typedef struct node NODE;
struct node{
	int data;
	struct node *next;
}; // CREATING A STRUCTURE NODE

void AddNodes()
{
	int n,loop,value;
	NODE *temp;
	temp=(struct node*)malloc(sizeof(struct node));
	printf("How many nodes do you want to add");
	scanf("%d",&n);  // ASKING USER THE LENGTH OF THE LIST

	printf("\n Enter value at node %d= ",loop+1);
	scanf("%d",value); // VALUE AT FIRST NODE

		if(n=1){ //condition when user wants to enter only 1 node

		  		head->link=current->link; // LINKING HEAD TO CURRENT NODE!
  				current->data=value;
					current->link=NULL;
					printf("Single Node added=> %2d\n",current->data);
  		}

	else{
					for(loop=1;loop<n;loop++){


								printf("\n Enter value at node %d= ",loop+1);
								scanf("%d",value);
								temp->data=value;
								current->link

						}
	}
}

int main()
{

	NODE *head=NULL; //note: *
	NODE *current=NULL; //note: *

	head=(struct node*)malloc(sizeof(struct node));
	current=(struct node*)malloc(sizeof(struct node));

	AddNodes();



}
