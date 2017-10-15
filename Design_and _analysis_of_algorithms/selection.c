#include<stdio.h>
#include<time.h>
#include<stdlib.h>
double time_elapsed(struct timespec *start,struct timespec *end);
void selection(int *a,int n);
void print(int *a,int n);
int *a;
int  main()
{ 
	int n,i;

	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
	{	scanf("%d",&a[i]);
	}
	struct timespec start,end;
	clock_gettime(CLOCK_REALTIME,&start);
	selection(a,n);
	clock_gettime(CLOCK_REALTIME,&end);
	print(a,n);
	printf("Execution time=%lfms\n",time_elapsed(&start,&end));
}
void selection(int *a,int n)
{	int i,min,temp,j;
	for(i=0;i<n-1;i++)
	{	min=i;
		for(j=i+1;j<n;j++)
		{	if(a[j]<a[min])
			{	min=j;
			}
		}
		temp=a[i];
		a[i]=a[min];
		a[min]=temp;
	}
}
void print(int *a,int n)
{
	int i;
	printf("\nSorted elements:\n");
	for(i=0;i<n;i++)
	{	printf("%d\n",a[i]);
	}
}
double time_elapsed(struct timespec *start,struct timespec *end)
{	double t=0.0;
	t=(end->tv_sec - start->tv_sec)*1000;
	t+=(end->tv_nsec -start->tv_nsec)*0.000001;
}
