#include <stdio.h>
#include <stdlib.h>
#ifndef INDEX_INVALID
#define INDEX_INVALID -1
#endif
//CHECK FOR GENERALIZATION OF BUBBLE SELECTION INSERTION SORTS-----AN EXPERIMENT
#include "Arrays.h"
//!!!!!ARRAYS SORTED IN ASCENDING ORDER ONLY!!!!
/*A is the name for ARRAY
void BubbleSort(int A[],int low,int high);//low is the start from which sorting is to be started
void InsertionSort(int A[],int low,int high);//high is the index upto which sorting should be done
void SelectionSort(int A[],int low,int high);
void MergeSelf(int A[],int low,int upto,int high);
void MergeSort(int A[],int low,int high);
int partitionAlgo(int A[],int low,int high,int x);//partitions array about x and returns position upto which elements<=x
void QuickSort(int A[],int low,int high);//QuickSort Algorithm
*/
//BUBBLE SORT (n is ARRAY SIZE)
void BubbleSort(int A[],int low,int high)
{
   int i,j,temp,sorted=0,k=0;
    for(i=low;i<high&&sorted==0;i++,k++)
    {
        sorted=1;
        for(j=low;j<high-k;j++)
        {
            if(A[j]>A[j+1])
            {
                temp=A[j];
                A[j]=A[j+1];
                A[j+1]=temp;
                sorted=0;
            }
        }
    }
}
//INSERTION SORT
void InsertionSort(int A[], int low,int high)
{
    int i,min=A[low],pos=low,x,j;
    for(i=low+1;i<=high;i++)
    {
        if(A[i]<min)
        {
            min=A[i];
            pos=i;
        }

    }
    A[pos]=A[low];
    A[low]=min;//minimum stored at 0th index
    for(i=low+2;i<=high;i++)
    {

        j=i-1;
        x=A[i];
        while(x<A[j])
        {
            A[j+1]=A[j];
            j--;
        }
       A[j+1]=x;

    }
    return;
}
void SelectionSort(int A[], int low,int high)
{
    int i,j,min,pos;
    for(i=low;i<high+1;i++)
    {
        min=A[i];
        pos=i;
        for(j=i+1;j<high+1;j++)
        {
            if(A[j]<min)
            {
                min=A[j];
                pos=j;
            }
        }

        A[pos]=A[i];
        A[i]=min;
    }
    return;
}
//MERGE SELF
void MergeSelf(int A[],int low,int upto,int high)
{
    int i,j,k,*temp;
    temp=(int *)malloc(sizeof(int)*(high-low+1));
    i=low;
    j=upto+1;
    k=0;
    while(i<=upto&&j<=high)
    {
        if(A[i]<A[j])
        {
            temp[k++]=A[i++];
        }
        else
        {
            temp[k++]=A[j++];
        }
    }
    while(i<=upto)
    {
        temp[k++]=A[i++];
    }
    while(j<=high)
    {
        temp[k++]=A[j++];
    }
    k-=1;
    while(k>=0)
    {
        A[low+k]=temp[k];
        k--;
    }
    free(temp);
    temp=NULL;
    return;
}
//MERGE SORT
void MergeSort(int A[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        MergeSelf(A,low,mid,high);
    }
    return;
}
int partitionAlgo(int A[], int low, int high, int x)
{
    int left=low,right=high,temp;
    while(left<=high&&A[left]<=x)
    {
        left++;
    }
    while(right>=low&&A[right]>x)
    {
        right--;
    }
    while(left<right)
    {
        temp=A[left];
        A[left]=A[right];
        A[right]=temp;
        while(A[left]<=x)
        {
            left++;
        }
        while(A[right]>x)
        {
            right--;
        }
    }
    return right;//or left-1
}
void QuickSort(int A[],int low,int high)
{
    int pos,temp;
    if(low<high)
    {
        pos=partitionAlgo(A,low,high,A[low]);
        temp=A[pos];
        A[pos]=A[low];
        A[low]=temp;
        QuickSort(A,low,pos-1);
        QuickSort(A,pos+1,high);

    }
    return;
}
/*
int LinearSearch(int A[],int low,int high,int searchThis);//low=index of element to start from;high=index of element to end at in an array
int BinarySearch(int A[],int low,int high,int searchThis);//low=index of element to start from;high=index of element to end at in a SORTED array
*/
int LinearSearch(int A[], int low,int high,int searchThis)//returns index of 1st occurence of the element being searched if found||||else returns -1(invalid)
{
    int ret_val=INDEX_INVALID,i;
    for(i=low;i<=high&&ret_val==INDEX_INVALID;i++)
    {
        if(A[i]==searchThis)
        {
            ret_val=i;
        }
    }
    return ret_val;
}
int BinarySearch(int A[], int low, int high,int searchThis)//A is required to be SORTED
{
    //!!!ForSorted ARRAY only!!!
    //returns index of an occurence of the element being searched(not necessarily 1st occurence) if found||||else returns -1(invalid)
    int ret_val=INDEX_INVALID,mid;
    while(low<=high&&ret_val==INDEX_INVALID)
    {
        mid=(low+high)/2;
        if(A[mid]==searchThis)
        {
            ret_val=mid;
        }
        else if(A[mid]<searchThis)
        {
            low=mid+1;
        }
        else    //A[mid]>searchThis
        {
            high=mid-1;
        }
    }
    return ret_val;

}
