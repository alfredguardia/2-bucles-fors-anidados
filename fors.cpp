#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>

using namespace std;

const int MAX = 10000;
double A[MAX][MAX], x[MAX], y[MAX];

void inicializarA()
{
	srand(time(NULL));
	for(int i=0; i<MAX; i++)
		for(int j=0; j<MAX; j++)
			A[i][j]=rand() % 100;
}

void inicializarX()
{
	srand(time(NULL));
	for(int i=0; i<MAX; i++)
		x[i]=rand() % 100;
}

void inicializarY()
{
	srand(time(NULL));
	for(int i=0; i<MAX; i++)
		y[i]=0;
}

int main()
{
	unsigned t0, t1, t2, t3;
	inicializarA();
	inicializarX();
	inicializarY();
	
	t0 = clock();
	for(int i=0; i<MAX; i++)
		for(int j=0; j<MAX; j++)
			y[i]+=A[i][j]*x[j];
	t1 = clock();
	
	
	inicializarY();
	
	t2 = clock();		
	for(int j=0; j<MAX; j++)
		for(int i=0; i<MAX; i++)
			y[i]+=A[i][j]*x[j];
	t3 = clock();
	
	double time1 = (double(t1-t0)/CLOCKS_PER_SEC);
	double time2 = (double(t3-t2)/CLOCKS_PER_SEC);	
	cout<<"el 1er FOR: "<<time1<<endl;
	cout<<"el 2do FOR: "<<time2<<endl;
}

