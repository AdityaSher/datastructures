//ctrl shift h opens git-plus menu
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
}; // CREATING A STRUCTURE NODE

typedef struct node NODE; // defininf struct node as one word "NODE"

NODE* head=NULL; //note: *warning dont declare it inside main without passing it to other functions!
NODE* current=NULL; //note: *warning dont declare it inside main without passing it to other functions!
NODE* temp=NULL;//note: *warning dont declare it inside main without passing it to other functions!

int AddNodes(); // function for adding nodes
int PrintList(); // function to print the singly linked list


int main()
{
	current=(NODE*)malloc(sizeof(NODE));

	AddNodes();
	PrintList();

}

int AddNodes()
{
	int n,loop,value;


	printf("How many nodes do you want to add ");
	scanf("%d",&n);  // ASKING USER THE LENGTH OF THE LIST

		for(loop=0;loop<n;loop++){
				temp=(NODE*)malloc(sizeof(NODE));
				temp->link=NULL;
				printf("\n Enter value at node %d= ",loop+1);
				scanf("%d",&temp->data);

				if(head==NULL)
					{
						head=temp;
					}
				else{

					current->link=temp;
				}

				current=temp;
			}//end of for

}
//INT ADD NODES ENDS

int PrintList(){

						current=head;
						 while(current!=NULL){ //condition such that current will reach last block go to the null pointer and then stop
							 		printf("%2d" ,current->data );
									current=current->link;

						 }


}
