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
	int i,j,k,n,temp,f=0;
	printf("Enter number of elements: ");
	scanf("%d",&n);
	int a[n];
	srand( (unsigned) time(NULL) * getpid());	
	for(i = 0; i < n; i++)
	{	
		a[i]=rand()%100;
    }
    
    for(i = 0; i < n- 1; i++)
    {       
        for(j = 0; j < n- i - 1; j++)
        {          
            if(a[j] > a[j + 1])
            {               
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    
    printf("\n");
    for(i = 0; i < n; i++)
	{	
		printf("%d\n",a[i]);
    }
    
    printf("Enter element to search: ");
    scanf("%d",&k);
     gettimeofday(&t0, NULL);
    int l=0,h=n-1,m;
    while(l<=h)
    {
    	m=(l+h)/2;
    	if(a[m]==k)
    	{
    		f=1;
    		printf("element found at position %d\n",m+1);
    		break;
    	}
    	else if(k>a[m])
    		l=m+1;
    	else
    		h=m-1;
    }
    if(f==0)
    	printf("element not found\n");
     gettimeofday(&t1, NULL);
    elapsed = timedifference_msec(t0, t1);
	printf("Code executed in %f milliseconds.\n", elapsed);
}

