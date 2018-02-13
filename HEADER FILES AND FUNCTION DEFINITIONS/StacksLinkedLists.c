
#include "StacksLinkedLists.h"

node* MakeNode(ItemType data)
{
	//MAKES A SINGLE NODE and inserts data into it ..returns pointer to the newly made node if MEMORY IS AVAILABLE ELSE RETURNS NULL
	node* ptr;
	ptr=(node*)malloc(sizeof(node));
	if(ptr!=NULL)
	{
		ptr->data=data;
		ptr->next=NULL;			//initialize ptr->next with default value
	}
	return ptr;
}
void InitializeStackDS(StackDS *sptr)
{
	//INITIALIZES STACK TO DEFAULT VALUE
	sptr->top=NULL;
	return;
}
Bool isStackDSEmpty(StackDS *sptr)
{
	//returns true if stack is empty
	return ((sptr->top)==NULL);
}
Bool isStackDSFull(StackDS* sptr)
{
	//since LINKED LIST size is theoretically infinite,this function returns back FALSE always
	return FALSE;
}
Status PushOnStackDS(StackDS *sptr,ItemType data)
{
	//PUSH DATA ON STACKDS--returns SUCCESS when MEMORY NOT FULL ELSE RETURNS FAILURE
	Status sc=SUCCESS;
	node* ptr;
	ptr=MakeNode(data);
	if(ptr==NULL||(isStackDSFull(sptr)))
	{
		sc=FAILURE;
	}
	else
	{
		ptr->next=(sptr->top);
		sptr->top=ptr;
	}
	return sc;
	//BASICALLY THIS FUNCTION RESEMBLES InsertAtStart() of LINKEDLIST
}
Status PopFromStackDS(StackDS *sptr,ItemType* dptr)
{
	//POPS DATA FROM STACKDS and PROVIDES DATA DELETED THROUGH dptr(if atall data was deleted)-----returns SUCCESS if node is deleted else returns FAILURE(incase when stack is empty)
	Status sc=SUCCESS;
	node* ptr;
	if(isStackDSEmpty(sptr))
	{
		sc=FAILURE;
	}
	else
	{
		//atleast a node is present
		ptr=(sptr->top);
		(sptr->top)=ptr->next;
		*dptr=ptr->data;	//catch the data to be deleted
		free(ptr);
		ptr=NULL;
	}	
	return sc;
}