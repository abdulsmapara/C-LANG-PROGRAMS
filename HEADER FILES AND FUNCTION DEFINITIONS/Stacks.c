#include <stdio.h>
#include <stdlib.h>
#include "Stacks.h"
/*
					STACKS-ABSTRACT DATA STRUCTURE
						FIRST-IN LAST-OUT
			VALUE INSERTED FIRST STORED AT BOTTOMMOST LOCATION
			VALUE INSERTED MOST RECENTLY STORED AT TOPMOST LOCATION
void InitializeStack(Stack *PointStack);//Initialize the stack top variable
Stack* CreateStacks(int size);//Implements  stack based on size given by user|||data structure on which it gets implemented is array currently.Can be changed by making changes in this file
Status PushOnStack(Stack *PointStack,ItemType val);//Push val on top of stack
Status PopFromStack(Stack *PointStack,ItemType *here);//Pop val from top of stack in 'here' variable
Bool isStackEmpty(Stack *PointStack);//returns true if stackisempty else returns false
Bool isStackFull(Stack *PointStack);//returns true if stackisfull else returns false
*/
void InitializeStack(Stack *PointStack)
{
	//INITIALIZING TOP VARIABLE OF STACKS 
	PointStack->top=-1;
	PointStack->size=0;
}
Stack* CreateStacks(int size)
{
//Implements stack based on size given by user|||data structure on which it gets implemented is array currently.Can be changed by making changes in this file
	Stack *PointStack=(Stack *)malloc(sizeof(Stack));
	InitializeStack(PointStack);
	PointStack->size=size;
	PointStack->array=(ItemType *)malloc(sizeof(ItemType)*size);
	return PointStack;
}
Bool isStackEmpty(Stack *PointStack)
{
//returns true if stackisempty else returns false
	/*Bool retval=FALSE;
	if(PointStack->top==-1)
	{
		retval=TRUE;
	}
	return retval;*/
	return ((PointStack->top)==-1);
}
Bool isStackFull(Stack *PointStack)
{
//returns true if stackisfull else returns false
	return ((PointStack->top)==((PointStack->size)-1));
}
Status PushOnStack(Stack *PointStack,ItemType val)
{
	//Push val on top of stack
	Status retval=SUCCESS;
	if(isStackFull(PointStack))
	{
		retval=FAILURE;
	}
	else
	{
		(PointStack->top)+=1;
		PointStack->array[PointStack->top]=val;
	}
	return retval;
}
Status PopFromStack(Stack *PointStack,ItemType *here)
{
//Pop val from top of stack in 'here' variable
	Status retval=SUCCESS;
	if(isStackEmpty(PointStack))
	{
		retval=FAILURE;
	}
	else
	{
		*here=PointStack->array[PointStack->top];
		(PointStack->top)-=1;
	}
	return retval;
}

