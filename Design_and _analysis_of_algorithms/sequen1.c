#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
int seq(int ,int *,int);
void main()
{
	int i,ele,res;	
	int n;
        
	
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++)
	{ scanf("%d",&a[i]);}
	scanf("%d",&ele);
	struct timespec start,end;
        clock_gettime(CLOCK_REALTIME,&start);
	res=seq(n,a,ele);
	clock_gettime(CLOCK_REALTIME,&end);
	if(res==0)
 	{ printf("Element not  found");}
	else
	{ printf("Last occurence of %d=%d",ele,res);}
	printf("\nStart Time =%ldsec \t %ldns",start.tv_sec,start.tv_nsec);
	printf("\nEnd Time =%ldsec\t%ldns",end.tv_sec,end.tv_nsec);
	printf("\nDifference in time=%ldns \n",(end.tv_nsec - start.tv_nsec));
}
int seq(int n,int *a,int ele)
{	int i,r;r=0;
	for(i=0;i<n;i++)
	{ if(ele==a[i])
	  { r++; }
	}
	   return r;
}
