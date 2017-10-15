#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
void bsort(int *,int);
void out(int *,int);
double time_elapsed(struct timespec *start, struct timespec *end);
void main()
{
	int n,i, *a;
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++)
	{	scanf("%d",&a[i]);}
	
	struct timespec start,end;
        clock_gettime(CLOCK_REALTIME,&start);
	bsort(a,n);
	clock_gettime(CLOCK_REALTIME,&end);
	
	printf("\nExecution time=%lfms \n",time_elapsed(&start,&end));
}
void bsort(int *a,int n)
{
	int i,j,temp;
	for(i=0;i<n-2;i++)
	{	for(j=0;j<n-2-i;j++)
		{ 	if(a[j+1]<a[j])
			{	temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	//out(a,n);
	for(i=0;i<n;i++)
	{	printf("%d \n",a[i]);
	}
}	



double time_elapsed(struct timespec *start, struct timespec *end) {
	double t = 0.0;
	t = (end->tv_sec - start->tv_sec) * 1000;
	t += (end->tv_nsec - start->tv_nsec) * 0.000001;
	return t;
}

