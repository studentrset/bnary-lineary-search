#include <stdio.h>
#include <stdlib.h>
#include <time.h>

float timedifference_msec(struct timeval t0, struct timeval t1)
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

void main()
{
	struct timeval t0;
	struct timeval t1;
	float elapsed;
	int i,k,n,f=0;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int a[n];
	srand( (unsigned) time(NULL) * getpid());	
	for(i = 0; i < n; i++)
	{	
		a[i]=rand()%100;
		printf("%d\n",a[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d",&k);
    gettimeofday(&t0, NULL);
    for(i = 0; i < n; i++)
    {
    	if(a[i]==k)
    	{
    		printf("element found at position %d\n",i+1);
    		f=1;
    		break;
    	}
    }
    if(f==0)
    	printf("element not found\n");
    gettimeofday(&t1, NULL);
    elapsed = timedifference_msec(t0, t1);
	printf("Code executed in %f milliseconds.\n", elapsed);

}

