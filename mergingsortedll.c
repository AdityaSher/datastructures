//ctrl shift h opens git-plus menu
#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node* link;
};

typedef struct node NODE;

NODE* head1=NULL;
NODE* head2=NULL;
NODE* current=NULL;
NODE* temp=NULL;

int CreateList1();
int CreateList2();
int MergeList();
int PrintList();
int main()
{
  int choice;
  printf("Do you want to create both linked list? Enter 1 for yes ");
  scanf("%d",&choice);

  if(choice==1)
  {
  	CreateList1();
  	CreateList2();

  }

  printf("Enter 1 to merge and display the linked list ");
  scanf("%d",&choice);

  if(choice==1)
  {
    MergeList();
 	  PrintList();
  }
}


int CreateList1()
{
	int n,loop,value;


	printf("How many nodes do you want to add in list 1? ");
	scanf("%d",&n);  // ASKING USER THE LENGTH OF THE LIST

		for(loop=0;loop<n;loop++){
				temp=(NODE*)malloc(sizeof(NODE));
				temp->link=NULL;
				printf("\n Enter value at node %d= ",loop+1);
				scanf("%d",&temp->data);

				if(head1==NULL)
					{
						head1=temp;
					}
				else{

					current->link=temp;
				}

				current=temp;
			}//end of for

}
//INT CreateList1 ENDS


int CreateList2()
{
	int n,loop,value;


	printf("How many nodes do you want to add in list 2 ? ");
	scanf("%d",&n);  // ASKING USER THE LENGTH OF THE LIST

		for(loop=0;loop<n;loop++){
				temp=(NODE*)malloc(sizeof(NODE));
				temp->link=NULL;
				printf("\n Enter value at node %d= ",loop+1);
				scanf("%d",&temp->data);

				if(head2==NULL)
					{
						head2=temp;
					}
				else{

					current->link=temp;
				}

				current=temp;
			}//end of for

}
//INT CreateList2 ENDS


int mergeList()
{ current=head1;
  while(current->link!=NULL)
  {
    current=current->link;
  }
  current->link=head2;
}

int PrintList()
{
  current=head1;
	while(current!=NULL)
  {   //condition such that current will reach last block and become equal to NULL and then stop
	  printf("%2d ->" ,current->data );
	  current=current->link;
  }
}
