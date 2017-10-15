#include<stdio.h>
#include<time.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>
double time_elapsed(struct timespec *start,struct timespec *end);
int stringmatch(char * a,char *p);
int main()
{
	char *a,*p;
	int n,m,res;
	
	a=(char*)malloc(10000*sizeof(char));
	p=(char*)malloc(10000*sizeof(char));
	gets(a);
	gets(p);
	/*n=strlen(a);
	m=strlen(p);*/
	struct timespec start,end;
	clock_gettime(CLOCK_REALTIME,&start);
	res=stringmatch(a,p);
	clock_gettime(CLOCK_REALTIME,&end);
	if(res==-1)
	{	printf("String not found");
	}
	else{
		printf("Index=%d",res);
	}
	printf("\nExecution time=%lfms\n",time_elapsed(&start,&end));free(a);free(p);
}
int stringmatch(char *a,char*p)
{	int i,j,n,m;
	n=strlen(a);
	m=strlen(p);
	for(i=0;i<n-m;i++)
	{	j=0;
		while(j<m && p[j]==a[i+j])
		{	j=j+1;
		}
		if(j==m){
			return i;
		}
	}
	//return -1;
}
double time_elapsed(struct timespec *start,struct timespec *end)
{	double t=0.0;
	t=(end->tv_sec - start->tv_sec)*1000;
	t+=(end->tv_nsec -start->tv_nsec)*0.000001;
	return t;
}
