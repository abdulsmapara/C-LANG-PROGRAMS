#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
void InitializeArrayList(ArrayList* arrListPtr)
{
	arrListPtr->list=NULL;
	arrListPtr->CapacityIncrement=0;
	arrListPtr->nextFill=0;
	arrListPtr->size=0;
	return;
}
Status CreateArrayList(ArrayList* arrListPtr,int InitialSize,int CapacityIncrement)
{
	Status sc=SUCCESS;
	InitializeArrayList(arrListPtr);
	arrListPtr->list=(ItemType*)malloc(sizeof(ItemType)*InitialSize);
	if(arrListPtr!=NULL)
	{
		arrListPtr->CapacityIncrement=CapacityIncrement;
		arrListPtr->size=InitialSize;
	}
	else
	{
		sc=FAILURE;
	}
	return sc;
}
Bool isArrayListFull(ArrayList* arrListPtr)
{
	return (arrListPtr->nextFill==arrListPtr->size);
}
Bool isArrayListEmpty(ArrayList* arrListPtr)
{
	return (arrListPtr->nextFill==0);
}
Status DeleteArrayList(ArrayList* arrListPtr)
{
	Status sc=SUCCESS;
	if(arrListPtr->list!=NULL)
	{
		free(arrListPtr->list);
		InitializeArrayList(arrListPtr);
	}
	else
	{
		sc=FAILURE;
	}
	return sc;
}
Status AddToArrayList(ArrayList* arrListPtr,ItemType val)
{
	Status sc=SUCCESS;
	ItemType* newList;
	int i,trv;
	if(isArrayListFull(arrListPtr))
	{
		newList=(ItemType*)malloc(sizeof(ItemType)*(arrListPtr->size+arrListPtr->CapacityIncrement));
		if(newList==NULL)
		{
			//can't expand
			sc=FAILURE;
		}
		else
		{
			trv=arrListPtr->size;
			i=0;
			while(i<trv)
			{
				newList[i]=arrListPtr->list[i];
				i++;
			}
			arrListPtr->size=arrListPtr->size+arrListPtr->CapacityIncrement;
			if(i<arrListPtr->size)
			{
				newList[i]=val;
				free(arrListPtr->list);	//delete older list
				arrListPtr->list=newList;
				(arrListPtr->nextFill)++;
			}
			else
			{
				sc=FAILURE;
			}			
		}
	}
	else
	{
		//ARRAY LIST NOT FULL
		arrListPtr->list[arrListPtr->nextFill]=val;
		(arrListPtr->nextFill)++;
	}
	return sc;
}
Status DeleteFromArrayList(ArrayList* arrListPtr,int index)
{
	Status sc=SUCCESS;
	int i;
	if(index<0||index>=arrListPtr->nextFill)
	{
		sc=FAILURE;
	}
	else
	{
		i=index;
		while(i<arrListPtr->nextFill-1)
		{
			arrListPtr->list[i]=arrListPtr->list[i+1];
			i++;
		}
		(arrListPtr->nextFill)--;
	}
	return sc;
}
void TraverseArrayList(ArrayList* arrListPtr)
{
	int max=arrListPtr->nextFill,i=0;
	while(i<max)
	{
		printf("ELEMENT %d: %d\n",i,arrListPtr->list[i]);
		i++;
	}
	return;
}