#include "Queues.h"
#include <stdio.h>
#include <stdlib.h>
/*
									QUEUE-ABSTRACT DATA STRUCTURE
										FIRST IN FIRST OUT
									VALUES INSERTED AFTER INCREMENTING REAR POSITION
									VALUES DELETED AT FRONT POSITION
void InitializeQueue(Queue *qPtr);					//Initializes rear,front variables in qPtr queue
Queue * CreateQueues(Queue *qPtr,int maxSize);		//creates a queue with data array of size=maxSize
Bool isQueueFull(Queue *qPtr);						//returns true if queue is full else returns false
Bool isQueueEmpty(Queue *qPtr);						//returns true if queue is empty else returns false
Status InsertInQueue(Queue *qPtr,ItemType val);		//inserts an element in queue if isQueueFull returns false
Status DeleteFromQueue(Queue *qPtr,ItemType *val);	//deletes an element in queue if isQueueEmpty returns false
*/
void InitializeQueue(Queue *qPtr)
{
//Initializes rear,front variables in qPtr queue
	qPtr->rear=-1;
	qPtr->front=0;
}
Queue* CreateQueues(Queue *qPtr,int maxSize)
{
//creates a queue with data array of size=maxSize
	Queue *qPtr=(Queue *)malloc(sizeof(Queue));
	InitializeQueue(qPtr);
	qPtr->maxSize=maxSize;
	Queue->data=(ItemType *)malloc(sizeof(ItemType)*maxSize);
	return qPtr;
}
Bool isQueueFull(Queue *qPtr)
{
//returns true if queue is full else returns false
	return ((((qPtr->rear+1)%((qPtr->maxSize)))==qPtr->front)&&qPtr->rear!=-1);
}
Bool isQueueEmpty(Queue *qPtr)
{
//returns true if queue is empty else returns false
	return ((((qPtr->rear+1)%((qPtr->maxSize)))==qPtr->front)&&qPtr->rear==-1);

}
Status InsertInQueue(Queue *qPtr,ItemType val)
{
//inserts an element in queue if isQueueFull returns false
	Status retval=SUCCESS;
	if(isQueueFull(qPtr))
	{
		retval=FAILURE;
	}
	else
	{
		(qPtr->rear)++;

		qPtr->data[qPtr->rear]=val;

	}
	return retval;

}
Status DeleteFromQueue(Queue *qPtr,ItemType *val)
{
//deletes an element in queue if isQueueEmpty returns false
	Status retval=SUCCESS;
	if(isQueueEmpty(qPtr))
	{
		retval=FAILURE;
	}
	else
	{

		*val=qPtr->data[qPtr->front];
		(qPtr->front)--;

		if(((qPtr->rear+1)%(qPtr->maxSize))==qPtr->front)
		{
			InitializeQueue(qPtr);
		}
	}
	return retval;
}