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
	printf("How many nodes do you want to add");
	scanf("%d",&n);  // ASKING USER THE LENGTH OF THE LIST


	printf("\n Enter value at node %d= ",loop+1);
	scanf("%d",value); // VALUE AT FIRST NODE

	if(head==NULL){

			head=current; // LINKING HEAD TO CURRENT NODE!
  		current->data=
  	}

	else{
				for(loop=1;loop<n;loop++)
		  {

		printf("\n Enter value at node %d= ",loop+1);
		scanf("%d",value);

	}
	}
}

int main()
{

	NODE head=NULL;
	NODE current=NULL;

	head=(struct node*)malloc(sizeof(struct node));
	current=(struct node*)malloc(sizeof(struct node));

	AddNodes();



}
