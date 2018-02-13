
#include <stdio.h>
#include "Numbers.h"
/*
float SqrtOf(float n);		//calculates square root of n(floating point number)
float Power(float base, unsigned int power);//calculates the value of (base float)to the power (power integer>=0)
float AbsoluteOf(float n);		//calculates absolute value of n and returns it
!!!SPECIAL NUMBERS!!!
int GetNthFib(int n,int fterm,int sterm);//Function to get nth fibonacci number (support for Wrapper Function NthFib(int n))
int NthFib(int n);			//nth fibonacci number n=1 fib=0 n=2 fib=1 and so on...
int max(int a,int b);			//maximum of a and b
int min(int a,int b);			//minimum of a and b
*/
float AbsoluteOf(float n)
{
	//calculates absolute value of n and returns it
	if(n<0)
	{
		n*=-1;
	}
	return n;
}
float SqrtOf(float n)
{
	float guess1,guess2;
	guess1=2.0;
	guess2=n;
	const float error=0.0001;
	do
	{
		guess1=guess2;
		guess2=(guess1+n/guess1)/2.0;

	}while(AbsoluteOf(guess1-guess2)>error);
	return guess2;
}
float Power(float base, unsigned int power)//calculates the value of (base float)to the power (power integer>=0)
{
	float retVal;
	if(power==0)
	{
		retVal=1.0;
	}
	else	//power>0
	{
		retVal=Power(base,power/2);
		retVal=retVal*retVal;
		if(power%2==1)
		{
			retVal*=base;
		}
	}
	return retVal;
}
int GetNthFib(int n,int fterm,int sterm)
{	//Function to get nth fibonacci number (support for Wrapper Function NthFib(int n))
	int retVal;
	if(n==1)
	{
		retVal=fterm;
	}
	else if(n==2)
	{
		retVal=sterm;
	}
	else
	{
		retVal=GetNthFib(n-1,sterm,fterm+sterm);
	}
	return retVal;
}
int NthFib(int n)	//nth fibonacci number n=1 fib=0 n=2 fib=1 and so on...		
{
	//WrapperFunction
	int fterm=0;
	int sterm=1;
	int retVal=GetNthFib(n,fterm,sterm);
	return retVal;

}
int max(int a,int b)
{
	int retVal=a;
	if(b>retVal)
	{
		retVal=b;
	}
	return retVal;
}
int min(int a,int b)
{
	int retVal=a;
	if(b<retVal)
	{
		retVal=b;
	}
	return retVal;

}
