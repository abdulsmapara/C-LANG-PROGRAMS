#ifndef ARRAY_LIST_H_INCLUDED
#define ARRAY_LIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
typedef int ItemType;
typedef enum{FAILURE,SUCCESS} Status;
typedef enum{FALSE,TRUE} Bool;
typedef struct ArrayListTag
{
	ItemType* list;
	int nextFill;
	int size;
	int CapacityIncrement;
}ArrayList;
void InitializeArrayList(ArrayList* arrListPtr);
Status CreateArrayList(ArrayList* arrListPtr,int InitialSize,int CapacityIncrement);
Bool isArrayListFull(ArrayList* arrListPtr);
Bool isArrayListEmpty(ArrayList* arrListPtr);
Status DeleteArrayList(ArrayList* arrListPtr);
Status AddToArrayList(ArrayList* arrListPtr,ItemType val);
Status DeleteFromArrayList(ArrayList* arrListPtr,int index);
void TraverseArrayList(ArrayList* arrListPtr);
#endif