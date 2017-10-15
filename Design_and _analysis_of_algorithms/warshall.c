#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void warshall(int n);
double time_elapsed(struct timespec *start,struct timespec *end);
void print(int n);
int a[10][10];
int main()
{
	int n,i,j;
	struct timespec start,end;
	
	scanf("%d",&n);
	//a[n][n];
	for(i=0;i<n;i++)
	{	for(j=0;j<n;j++)
		{	scanf("%d",&a[i][j]);
		}
	}
	clock_gettime(CLOCK_REALTIME, &start);
	warshall(n);
	clock_gettime(CLOCK_REALTIME, &end);
	print(n);
	printf("Execution time=%lfms\n",time_elapsed(&start,&end));
}
void warshall(int n)
{
	int i,j,k;
	for(k=0;k<n;k++)
	{	for(j=0;j<n;j++)
		{	for(i=0;i<n;i++)
			{
				a[i][j]=a[i][j] || (a[i][k] && a[k][j]);
			}
		}
	}
	
}
void print(int n)
{
	int i,j;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}
double time_elapsed(struct timespec *start,struct timespec *end)
{	double t=0.0;
	t=(end->tv_sec - start->tv_sec)*1000;
	t+=(end->tv_nsec -start->tv_nsec)*0.000001;
}
