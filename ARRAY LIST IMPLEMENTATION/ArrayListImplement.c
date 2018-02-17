#include "ArrayList.h"
/*
!!!!!!!!ArrayList.h available in Header Files and Definitions folder outside this folder!!!!!!!!
THIS IS SAMPLE DEMO OF IMPLEMENTATION OF ARRAY LIST IN C LANGUAGE
*/
int main()
{
	ArrayList a1,*ab=&a1;
	int i;
	Status sc;
	sc=CreateArrayList(ab,0,1);
	for(i=0;i<5;i++)
	{
		sc=AddToArrayList(ab,i);
		if(sc==FAILURE)
		{
			printf("FAILED\n");
		}
	}
	
	TraverseArrayList(ab);
	printf("DELETING ELEMENT(INDEX=2) STATUS=%d\n",DeleteFromArrayList(ab,2));
	printf("DELETING ELEMENT(INDEX=100 WHICH DOESN'T EXIST) STATUS=%d\n",DeleteFromArrayList(ab,100));

	if(DeleteArrayList(ab))
	{
		printf("\nWHOLE ARRAY LIST DELETED\n\n");
		TraverseArrayList(ab);
	}
	printf("DONE SHOWCASING ARRAY LIST IMPLEMENTATION IN C\nMORE FUNCTIONS COMING SOON!");
	return 0;
}
