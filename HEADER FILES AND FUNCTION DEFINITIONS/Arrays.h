#ifndef ARRAYS_H_INCLUDED
#define ARRAYS_H_INCLUDED
void BubbleSort(int A[],int low,int high);//low is the start from which sorting is to be started
void InsertionSort(int A[],int low,int high);//high is the index upto which sorting should be done
void SelectionSort(int A[],int low,int high);
void MergeSelf(int A[],int low,int upto,int high);
void MergeSort(int A[],int low,int high);
int partitionAlgo(int A[],int low,int high,int x);//partitions array about x and returns position upto which elements<=x
void QuickSort(int A[],int low,int high);//QuickSort Algorithm

int LinearSearch(int A[],int low,int high,int searchThis);//low=index of element to start from;high=index of element to end at in an array
int BinarySearch(int A[],int low,int high,int searchThis);//low=index of element to start from;high=index of element to end at in a SORTED array
//!!!BINARY SEARCH ForSorted ARRAY only!!!
int RemDuplicatesSortedArr(int A[],int low,int high);//returns index in the array upto which it has non-repeating elements(after removing duplicates)---TIME COMPLEXITY=O(n)
#endif