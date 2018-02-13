#ifndef QUEUES_H_INCLUDED
#define QUEUES_H_INCLUDED
#include "Types.h"
typedef int ItemType
typedef struct 
{
	int rear;
	int front;
	int maxSize;									//for dynamic size of data array
	ItemType *data;
}Queue;
void InitializeQueue(Queue *qPtr);					//Initializes rear,front variables in qptr queue
Queue * CreateQueues(Queue *qptr,int maxSize);		//creates a queue with data array of size=maxSize
Bool isQueueFull(Queue *qptr);						//returns true if queue is full else returns false
Bool isQueueEmpty(Queue *qptr);						//returns true if queue is empty else returns false
Status InsertInQueue(Queue *qptr,ItemType val);		//inserts an element in queue if isQueueFull returns false
Status DeleteFromQueue(Queue *qptr,ItemType *val);	//deletes an element in queue if isQueueEmpty returns false
#endif