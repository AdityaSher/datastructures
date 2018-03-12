//ctrl shift h opens git-plus menu
#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* link;
}; // CREATING A STRUCTURE NODE

typedef struct node NODE; // defining struct node as one word "NODE"

NODE* head=NULL; //note: *warning dont declare it inside main without passing it to other functions!
// note: *DONT ALLOCATE HEAD ITS JUST A NORMAL POINTER*
NODE* current=NULL; //note: *warning dont declare it inside main without passing it to other functions!
NODE* temp=NULL;//note: *warning dont declare it inside main without passing it to other functions!

int AddNodes(); // function for adding nodes
int PrintList(); // function to print the singly linked list
int CountNodes(); //function to count nodes
int InsertNode();// function to insert node at selected position
int DeleteNode();//function to delete node from selected position
int main()
{
	int choice=0;
	current=(NODE*)malloc(sizeof(NODE));//allocation of traversing variable must be done only once


while(choice!=9)
{

	printf("Choose what to do: \n");
	printf("1. Add nodes\n2. Create nodes \n3. Count nodes\n4. Insert Node \n9. Exit \n");
	scanf("%d",&choice);
	switch (choice) {
		case 1: AddNodes();
						break;
		case 2: PrintList();
						break;
		case 3: CountNodes();
						break;
		case 4: InsertNode();
						break;
		case 5: DeleteNode();
						break;
		case 9: exit;
						break;
		default: printf("Enter Proper Input");
						 break;

	}


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


int InsertNode(){
		int position,count;
		temp=NULL; // avoiding temp pointing to garbage value
		temp=(NODE*)malloc(sizeof(NODE)); // allocating temp
		count=CountNodes(); // because we need size of list
		current=head;
		printf("Please enter the value you want at new node\n");
		scanf("%d",&temp->data); // storing data directly in temp
		printf("At what position do you want to add a node?");
		printf("\n1. First \n2. Middle \n3. Last \n4.Custom");
		scanf("%d",&position);
		switch(position){
			case 1:
						{	temp->link=NULL;
							current=head; //saving curren first node in current
							head=temp;// changing first node to temp
							temp->link=current;//linking new fiest node to old first node
							break;
						}
			case 2:
						{
							temp->link=NULL;
							current=head;
							for(int x=0;x<=count/2;x++){
										current=current->link;
							}
							current->link=temp;
							temp->link=NULL;
							break;
						}

			case 3:
						{
							temp->link=NULL;
							current=head;
							while(current->link!=NULL){
								current=current->link;
							}
							current->link=temp;
							temp->link=NULL;
							break;
						}
			case 4:
						{	int custom;
							temp->link=NULL;
							current=head;
							printf("At what location do you want to insert node?\n");\
							scanf("%d",&custom);
							for(int x=0;x<custom;x++){
										current=current->link;
							}
							current->link=temp;
							temp->link=NULL;
							break;
						}
		}

		printf("Lets check the list now\n");
		PrintList();

}//InsertNode ENDS
