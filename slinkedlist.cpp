#include<stdio.h>
#include<cstdlib.h>
typedef struct node NODE;
struct node{
	int data;
	struct node *next;
};

int main()
{   
	int n,loop,value;
	NODE head=NULL;
	NODE current=NULL;
	
	head=(struct node*)malloc(sizeof(struct node));
	current=(struct node*)malloc(sizeof(struct node));

	printf("How many nodes do you want to add");
	scanf("%d",&n);
	
	printf("\n Enter value at node %d= ",loop+1);
	scanf("%d",value);
	
	if(n>1)	
	{
	for(loop=1;loop<n;loop++)
	{
		printf("\n Enter value at node %d= ",loop+1);
		scanf("%d",value);
			
	}
	}
	

	
}

