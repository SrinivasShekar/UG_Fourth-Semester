#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int values[30],weight[30];
int mfknapsack(int,int,int *,int *);
double time_elapsed(struct timespec *start,struct timespec *end);
int max(int,int);
int main()
{
	int i,j,n,W;
	scanf("%d",&n);
	struct timespec start,end;
	
	
	for(i=0;i<n;i++)
	{
		scanf("%d",&weight[i]);
	}

	for(i=0;i<n;i++)
	{
		scanf("%d",&values[i]);
	}
	scanf("%d",&W);

	
	clock_gettime(CLOCK_REALTIME, &start);
	int ans=mfknapsack(n,W,weight,values);
	clock_gettime(CLOCK_REALTIME, &end);
	printf("%d\n",ans);
	printf("Execution time=%lfms\n",time_elapsed(&start,&end));
}

int mfknapsack(int n,int W,int weight[],int values[])
{
	int i,j,f[n+1][W+1];
	for(i=0;i<=n;i++)
	{	
		for(j=0;j<=W;j++)
		{
			if(i==0 || j==0)
				f[i][j]=0;
			else if(weight[i-1]<=j)
				f[i][j]=max(values[i-1]+f[i-1][j-weight[i-1]],f[i-1][j]);
			else
				f[i][j]=f[i-1][j];
		}
	}
	return f[n][W];
}
				


int max(int a,int b)
{
	return (a>b)?a:b;
}

double time_elapsed(struct timespec *start,struct timespec *end)
{	double t=0.0;
	t=(end->tv_sec - start->tv_sec)*1000;
	t+=(end->tv_nsec -start->tv_nsec)*0.000001;
}
