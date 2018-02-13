#ifndef STACKS_H_INCLUDED
#define STACKS_H_INCLUDED
#include "Types.h"
typedef int ItemType;
typedef struct 
{
	int top;
	int size;
	ItemType *array;
}Stack;

void InitializeStack(Stack *PointStack);//Initialize the stack top variable
Stack* CreateStacks(int size);//Implements  stack based on size given by user|||data structure on which it gets implemented is array currently.Can be changed by making changes in this file
Status PushOnStack(Stack *PointStack,ItemType val);//Push val on top of stack
Status PopFromStack(Stack *PointStack,ItemType *here);//Pop val from top of stack in 'here' variable
Bool isStackEmpty(Stack *PointStack);//returns true if stackisempty else returns false
Bool isStackFull(Stack *PointStack);//returns true if stackisfull else returns false

#endif