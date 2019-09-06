#include<stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

unsigned long fact (int n)
{
   int i;
   unsigned long f=1;
   for(i=1;i<=n;i++)
    {
      f=f*i;
     }
   return f;
}

unsigned long nbcombinations (int n, int k)
{
    unsigned long ncr;
    ncr=fact(n+k)/(fact(k)*fact(n));
    return ncr;
		

}

int max(int a)
{
  return (a > 0) ? a : 0;
}
unsigned long nbstateproduct(int numberOfTask, int backlogs[])
{	unsigned long nbstate=1;

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
	if (argc <2) {
    printf("Usage: comparaison nbtasks\n");
    exit(1);
  }
	int nbtasks;
	unsigned long combinations;
        int products;
	int iterations=1;
	int k=1;
	bool val=false;
    nbtasks = atoi(argv[1]);
    int backlogs[nbtasks];
    while(val==false){

	for(int i=0; i< nbtasks; i++){
	backlogs[i]=k;
	}
	products=nbstateproduct(nbtasks,backlogs);
        combinations=nbcombinations(nbtasks,k);
	printf("nombre des produits possible est %d\n", products);
	printf("nombre des combinaisons possible est %li\n", combinations);
	if(products==combinations) val=true;
        if(iterations==1000) val=true;
        iterations++;
        k++;
	
}
}


