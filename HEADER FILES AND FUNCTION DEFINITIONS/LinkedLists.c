#include "LinkedLists.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void GetData(ItemType* d)
{
	scanf("%d",d);	//------!!CHANGE HERE IF ITEM TYPE CHANGES!!-------
	return;
}
node* InsertNodeAtStart(node* head,ItemType data)
{
	//CREATES a node AND PUTS IN data in its data field..returns new head pointer
	node* ptr;
	ptr=(node *)malloc(sizeof(node));
	if(ptr!=NULL)
	{
		ptr->data=data;
		ptr->next=head;

	}
	head=ptr;
	return head;
}
node* CreateList(int num)
{
	//CREATES num NUMBER OF NODES and RETURNS HEAD TO THE START OF THE LINKED LIST
	node *head;
	head=NULL;
	int i;
	ItemType d;
	for(i=0;i<num;i++)
	{
		GetData(&d);
		head=InsertNodeAtStart(head,d);
	}
	return head;
}
void TraverseList(node* head)
{
	//TAKES in POINTER TO START OF THE LIST prints DATA PRESENT IN THE NODES AND RETURNS
	node* ptr=head;
	while(ptr!=NULL)
	{
		printf("%d ",ptr->data);	//------!!CHANGE HERE IF ITEM TYPE CHANGES!!-------
		ptr=ptr->next;
	}
	return;
}
Status DeleteAtStart(node** head,ItemType* dptr)
{
	//TAKES POINTER TO POINTER TO HEAD AND POINTER TO DATA AS INPUT and STORES DATA TO BE DELETED AND FREE UP THE LOACTION *head POINTS TO 
	Status sc=SUCCESS;
	node* ptr=*head;
	if(ptr==NULL)
	{
		//CASE OF EMPTY LIST WHICH MEANS DELETING A NODE IS IMPOSSIBLE
		sc=FAILURE;
	}
	else
	{
		//atleast a node is present in the list
		*head=ptr->next;
		*dptr=ptr->data;
		free(ptr);
		ptr=NULL;
	}
	return sc;
}
void DeleteList(node *head)
{					
	//DELETES COMPLETE LIST
	Status sc;
	ItemType data;
	while(head!=NULL)
	{
		sc=DeleteAtStart(&head,&data);
		printf("DATA %d JUST GOT DELETED FROM THE LIST\n",data);	//------!!CHANGE HERE IF ITEM TYPE CHANGES!!-------

	}
	return;
	//USER SHOULD TAKE CARE THAT AFTER THE LIST IS DELETED (after call to DeleteList())head should not be accessed OTHERWISE A CASE OF DANGLING POINTER WILL ARISE ACC TO THE WAY THE FUNCTION DELETELISTS IS WRITTEN
}
Bool MatchKeyData(ItemType data,KeyType key)
{
	//returns true if data and key matches
	//if data is large and key is value of element of data then changes can be made in this function 
	return (data==key);
}
Status SwapTwoNodes(node** head,KeyType key1,KeyType key2)
{
	//swaps nodes whose keys are given here
	//NOTE: nodes are swapped by changing links as swapping data of nodes may be expensive in many situations when data contains many fields
	node *ptr1,*prev1,*ptr2,*prev2,*temp;
	ptr1=*head;
	ptr2=*head;
	prev1=NULL;
	prev2=NULL;
	Bool found1=FALSE;
	Bool found2=FALSE;
	Status sc=SUCCESS;
	while((ptr1!=NULL)&&(!found1)&&(ptr2!=NULL)&&(!found2))
	{
		if(MatchKeyData(ptr1->data,key1))
		{
			found1=TRUE;
		}
		else
		{
			prev1=ptr1;
			ptr1=ptr1->next;
		}
		if(MatchKeyData(ptr2->data,key2))
		{
			found2=TRUE;
		}
		else
		{
			prev2=ptr2;
			ptr2=ptr2->next;
		}
	}
	while((ptr1!=NULL)&&(!found1))
	{
		if(MatchKeyData(ptr1->data,key1))
		{
			found1=TRUE;
		}
		else
		{
			prev1=ptr1;
			ptr1=ptr1->next;
		}
	
	}
	while((ptr2!=NULL)&&(!found2))
	{
		if(MatchKeyData(ptr2->data,key2))
		{
			found2=TRUE;
		}
		else
		{
			prev2=ptr2;
			ptr2=ptr2->next;
		}
	}
	if((!found1)||(!found2))
	{
		sc=FAILURE;
	}
	else if(ptr1!=ptr2)
	{
		//if ptr1==ptr2 then swapping them doesnot make sense
		if(prev1==NULL)
		{
			*head=ptr2;
		}
		else
		{
			prev1->next=ptr2;
		}
		if(prev2==NULL)
		{
			*head=ptr1;
		}
		else
		{
			prev2->next=ptr1;
		}
		temp=ptr1->next;
		ptr1->next=ptr2->next;
		ptr2->next=temp;

	}
	return sc;

}