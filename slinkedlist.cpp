//ctrl shift h opens git-plus menu
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
}; // CREATING A STRUCTURE NODE

typedef struct node NODE; // defininf struct node as one word "NODE"

NODE* head=NULL; //note: *warning dont declare it inside main without passing it to other functions!
// note: *DONT ALLOCATE HEAD ITS JUST A NORMAL POINTER*
NODE* current=NULL; //note: *warning dont declare it inside main without passing it to other functions!
NODE* temp=NULL;//note: *warning dont declare it inside main without passing it to other functions!

int AddNodes(); // function for adding nodes
int PrintList(); // function to print the singly linked list
int CountNodes(); //function to count nodes

int main()
{
	int choice;
	current=(NODE*)malloc(sizeof(NODE));//allocation of traversing variable must be done only once
	printf("Choose what to do: \n");
	printf("1. Add nodes\n 2. Create nodes 3. Count nodes\n 9. Exit");

	switch (choice) {
		case 1: AddNodes();
						break;
		case 2: PrintList();
						break;
		case 3: CountNodes();
						break;
		case 9: exit();
						break
		default: printf("Enter Proper Input");
						 break;

	}



}

int AddNodes()
{
	int n,loop,value;


	printf("How many nodes do you want to add? ");
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
			while(current!=NULL){ //condition such that current will reach last block and become equal to NULL and then stop
			printf("%2d" ,current->data );
			current=current->link;

		}


}
//INT PrintList ENDS
int count=0;
int CountNodes(){
			current=head;
			while(current!=NULL){
						count++;
						current=current->link;
			}

			printf("Number of nodes is= %d \n",count);
}// INT CountNodes ENDS
