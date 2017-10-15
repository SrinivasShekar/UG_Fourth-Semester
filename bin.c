#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<stdlib.h>
int bin(int *,int,int,int);
int main()
{
	int n,i,ele,res,*a,pos;
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	
	for(i=0;i<n;i++)
	{ scanf("%d",&a[i]);}
	scanf("%d",&ele);
	struct timespec start,end;
        clock_gettime(CLOCK_REALTIME,&start);
	res=bin(a,0,n,ele);
	clock_gettime(CLOCK_REALTIME,&end);
	if(res==-1)
 	{ printf("Element not found");}
	else
	{ printf("POsition=%d",res+1);}
	printf("\nStart Time =%ldsec \t %ldns",start.tv_sec,start.tv_nsec);
	printf("\nEnd Time =%ldsec\t%ldns",end.tv_sec,end.tv_nsec);
	printf("\nDifference in time=%ldns \n",(end.tv_nsec - start.tv_nsec));
	return 0;
}
int bin(int *a,int l,int n,int ele)
{	int h,mid;
	h=n;
	while(l<h)
 	{ mid=(l+h)/2;
	  if(a[mid]==ele)
	  { return mid;}
	  else if(a[mid]>ele)
 	  {  h=mid-1;}
	  else
	  {  l=mid+1;}
	}
	return -1;
}

  
