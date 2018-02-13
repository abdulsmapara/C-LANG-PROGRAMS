#ifndef STACKSLINKEDLISTS_H_INCLUDED
#define STACKSLINKEDLISTS_H_INCLUDED
#include "Types.h"
typedef int ItemType;
typedef struct ListNodeTag
{
	struct ListNodeTag* next;
	ItemType data;	
}listNode;
//WRAPPER FOR INFORMATION HIDING AND ABSTRCTION
typedef struct StackLinkedListTag
{
	listNode* top;
}StackDS;	//STACK DATA STRUCTURE BASED ON LINKED LIST--important for the case described--#include "Stacks.h" #include "StacksLinkedLists.h"---same name would cause problem
node* MakeNode(ItemType data);						//MAKES A SINGLE NODE and inserts data into it ..returns pointer to the newly made node if MEMORY IS AVAILABLE ELSE RETURNS NULL
void InitializeStackDS(StackDS *sptr);				//INITIALIZES STACK TO DEFAULT VALUE
Bool isStackDSEmpty(StackDS *sptr);					//returns true if stack is empty
Bool isStackDSFull(StackDS* sptr);					//since LINKED LIST size is theoretically infinite,this function returns back FALSE always
Status PushOnStackDS(StackDS *sptr,ItemType data);	//PUSH DATA ON STACKDS
Status PopFromStackDS(StackDS *sptr,ItemType* dptr);	//POPS DATA FROM STACKDS and PROVIDES DATA DELETED THROUGH dptr(if atall data was deleted)-----returns SUCCESS if node is deleted else returns FAILURE(incase when stack is empty)
#endif