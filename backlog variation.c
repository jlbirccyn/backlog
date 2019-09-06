#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <float.h>
 double fact (int n)
{
   int i; 
   double f=1;
   for(i=1;i<=n;i++)
    {
      f=f*i;
     }
   return f;
}

 double nbcombinations (int n, int k)
{
    double ncr,first, second;
    first=fact(n+k);
    second=fact(k)*fact(n);
    ncr=first/second;
    return ncr;
		

}

int max(int a)
{
  return (a > 0) ? a : 0;
}
double nbstateproduct(int numberOfTask, int backlogs[])
{	double nbstate=1;

	for(int task = 0; task < numberOfTask; task++)
	{
 		nbstate=nbstate*(backlogs[task]+1);
	}
 
  return nbstate;
}



int maxbacklog(int numberofTask, int backlogs[])
{	int max=0;
	int maxK;
	for (int i=0; i<numberofTask; i++)
     	{
     	 if(backlogs[i]>backlogs[max]) max=i;
     	}
	maxK=backlogs[max];
	return maxK;
}
void main()
{
	FILE *fptr;
 	fptr = fopen("data1.dat","w");
 	int kmax=1, nbtasks=10,iteration=0;
 	bool val= false;
	double comb,prod;
	int backlogs[nbtasks];
 	while(val==false)
	{
	comb=nbcombinations(nbtasks,kmax);
	for(int i=0; i< nbtasks; i++){
   	 backlogs[i]=kmax;
	}
	prod=nbstateproduct(nbtasks,backlogs);
        if(comb==prod) val=true;
	fprintf(fptr,"%d ",kmax);
	fprintf(fptr,"%g ",prod);
	fprintf(fptr,"%g ",comb);
	fprintf(fptr,"\n");
	iteration=iteration+1;
	if(iteration==10) val=true;
	kmax=kmax+1;
	}

        fclose(fptr);
}
