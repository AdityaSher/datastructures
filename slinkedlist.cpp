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

void CreateList(); // function for creating list
void PrintList(); // function to print the singly linked list
int CountNodes(); //function to count nodes
void InsertNode();// function to insert node at selected position
void DeleteNode();//function to delete node from selected position
void SearchNode();//finding node by data
void PrintReverse(); //print the list in reverse without actually reversing the list
int main()
{
	int choice=0;
	current=(NODE*)malloc(sizeof(NODE));//allocation of traversing variable must be done only once


while(choice!=9)
{

	printf("\nChoose what to do: \n");
	printf("\n1.Create List\n2.Print List \n3.Count nodes\n4.Insert Node \n5.Delete Node \n6.Search Node by value \n7.Print List in reverse \n9. Exit \n");
	scanf("%d",&choice);
	switch (choice) {
		case 1: CreateList();
						break;
		case 2: PrintList();
						break;
		case 3: CountNodes();
						break;
		case 4: InsertNode();
						break;
		case 5: DeleteNode();
						break;
		case 6: SearchNode();
						break;
		case 7: PrintReverse();
					  break;
		case 9: exit;
						break;
		default: printf("Enter Proper Input");
						 break;

	}


}

}

void CreateList()
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
//INT CreateList ENDS

void PrintList(){

			current=head;
			while(current!=NULL){ //condition such that current will reach last block and become equal to NULL and then stop
			printf("%2d ->" ,current->data );
			current=current->link;

		}


}
//INT PrintList ENDS

int count=0;
int  CountNodes(){
	int count=0;
			current=head;
			while(current!=NULL){
						count++;
						current=current->link;
			}

			printf("Number of nodes is= %d \n",count);
return count;
		
}// INT CountNodes ENDS


void InsertNode(){
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
			case 1://first position node deleted
						{	temp->link=current;
							head=temp;
							 //linking temp to second node by overriding existing node
							break;
						}
			case 2:
						{
							temp->link=NULL;
							current=head;
							for(int x=1;x<(int)count/2;x++){

								current=current->link;}

								temp->link=current->link;
								current->link=temp;

							break;
						}

			case 3:
						{
							  if (head == NULL) {
    { 
       							head = temp; 
       							temp->link=NULL;
       						}
       							break; 
    } 	
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
							for(int x=1;x<custom-1;x++){
										current=current->link;
							}
							temp->link=current->link;
							current->link=temp;
							break;
						}
		}

		printf("Lets check the list now\n");
		PrintList();

}//InsertNode ENDS

void DeleteNode(){
	int position;
	temp=NULL; // avoiding temp pointing to garbage value
	temp=(NODE*)malloc(sizeof(NODE)); // allocating temp
	count=CountNodes(); // because we need size of list
	current=head;
	printf("\n");
	printf("Current number of nodes is as below\n");
	printf("\n");
	CountNodes();
	printf("Which Node do you want to delete?");
	printf("\n1. Beginning \n2. Middle \n3. Last \n4.Custom ");
	scanf("%d",&position);
	switch(position){
		case 1://delete node at beginning
					{	temp=head;
						head=head->link;
					free(temp);//linking new first (originally second)with
						break;
					}
		case 2:
					{//delete middle node
						temp->link=NULL;
						current=head;
						for(int x=1;x<=(int)count/2-1;x++){

										current=current->link;// for traversing till middle-1
										temp=current; //save middle-1 node as temp
						}
						temp=current->link;
						current->link=current->link->link;
						free(temp);
						break;
					}

		case 3:
					{//delete last node
						temp=head;//initializing temp
					//go to next node
						while(temp->link->link!=NULL)
						{
							temp=temp->link;
						}
						temp->link=NULL;

						break;
					}
		case 4://removing value at custom node!
					{	int custom;
						temp->link=NULL;//initializing temp
						current=head;//start traversing

						printf("Which node do you wish to remove\n");\
						scanf("%d",&custom);
						for(int x=1;x<=custom-2;x++){
							 //first save currents old value (present node-1) in NULL
							current=current->link;//go to next node
						}
						temp=current->link;
						current->link=current->link->link;
						free(temp);
						/* as we reach last node
						current is last node
						but temp is the second last node*/
						
						/*we over-ride the link of last node
						present in second last node:
						in order to remove the last node*/

						break;
					}
	}
	printf("\n");
	printf("Let's Check the list now!\n");
	PrintList();
}


void SearchNode(){//finding a node by value
		int value;
		printf("Enter value to be found\n");
		scanf("%d",&value );
		int n=CountNodes();
		current=head;//start traversing
		for(int x=0;x<n;x++){
				if(current->data==value){
					printf("The element %d you searched is at node number%d\n",value,x+1);
				printf("You can check it as below\n");
				PrintList();
				break;

			}//if ends
			 else{
			 current=current->link;//traverse to next node
		}
	}
}

void PrintReverse(){//print linked list in reverse without actually reversing
				NODE* rev;

				int i,j,n,value;
				n=CountNodes();
				printf("The reversed list is\n" );
				for(i=n;i>0;i--){
					rev=head;

					for(j=1;j<i;j++){
						rev=rev->link;

					}
						printf("i=%d j=%d \n",i,j );
						printf("%d-> \n",rev->data);
					}
}
