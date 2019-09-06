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
int nbstateproduct(int numberOfTask, int backlogs[])
{	int nbstate=1;

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



int main(int argc, char *argv[])
{
	if (argc <3) {
    printf("Usage: final nbtasks backlog1 backlog2\n");
    exit(1);
  }
	int nbtasks;
	double combinations;
	int products;
	int maxK;
    nbtasks = atoi(argv[1]);
    int backlogs[nbtasks];
    for(int i=0; i< nbtasks; i++){
    backlogs[i]=atoi(argv[i+2]);
	}
	maxK=maxbacklog(nbtasks,backlogs);
	products=nbstateproduct(nbtasks,backlogs);
        combinations=nbcombinations(nbtasks,maxK);
	printf("nombre des produits possible est %d\n", products);
	printf("nombre des combinaisons possible est %g\n", combinations);
	return combinations;
}


