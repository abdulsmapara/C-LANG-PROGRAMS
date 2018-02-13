#ifndef NUMBERS_H_INCLUDED
#define NUMBERS_H_INCLUDED
float SqrtOf(float n);		//calculates square root of n(floating point number)
float Power(float base, unsigned int power);//calculates the value of (base float)to the power (power integer>=0)
float AbsoluteOf(float n);		//calculates absolute value of n and returns it
//!!!SPECIAL NUMBERS!!!
int GetNthFib(int n,int fterm,int sterm);//Function to get nth fibonacci number (support for Wrapper Function NthFib(int n))
int NthFib(int n);			//nth fibonacci number n=1 fib=0 n=2 fib=1 and so on...
int max(int a,int b);			//maximum of a and b
int min(int a,int b);			//minimum of a and b
#endif