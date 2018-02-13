#ifndef LINKED_LISTS_H_INCLUDED
#define LINKED_LISTS_H_INCLUDED
#include "Types.h"
typedef int ItemType;	//change itemtype here
typedef int KeyType;	//change keytype here
typedef struct NodeTag
{
	struct NodeTag* next;
	ItemType data;
	
}node;

node* InsertNodeAtStart(node* head,ItemType data);	//CREATES a node AND PUTS IN data in its data field..returns new head pointer
void getData(ItemType* dptr);						//TAKES IN dptr , SCANS VALUE FROM USER AND STORES value WHERE dptr POINTS TO
node* CreateList(int num);							//CREATES num NUMBER OF NODES and RETURNS HEAD TO THE START OF THE LINKED LIST
void TraverseList(node* head);						//TAKES in POINTER TO START OF THE LIST prints DATA PRESENT IN THE NODES AND RETURNS
Status DeleteAtStart(node** head,ItemType* dptr);	//TAKES POINTER TO POINTER TO HEAD AND POINTER TO DATA AS INPUT and STORES DATA TO BE DELETED AND FREE UP THE LOACTION *head POINTS TO 
void DeleteList(node *head);					//DELETES COMPLETE LIST
Bool MatchKeyData(ItemType data,KeyType key);	//returns true if data and key matches
	//if data is large and key is value of element of data then changes can be made in this function 
Status SwapTwoNodes(node** head,KeyType key1,KeyType key2);//swaps nodes whose keys are given here
	//NOTE: nodes are swapped by changing links as swapping data of nodes may be expensive in many situations when data contains many fields

#endif