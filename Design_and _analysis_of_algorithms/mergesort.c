#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int mergesort(long int *,int ,int,int);
int merge(long int *, int , int , int,int);
struct timespec start,end;

int main()
{
	int i,l=0;
	int n;
	printf("\n Please Enter the Size of the array\n");
	scanf("%d",&n);	
	long int *arr;
	int r=n-1;
	arr=(long int*)malloc(n*sizeof(long int));
	printf("\nEnter Values into the array\n");
	for(i=0;i<n;i++){
		scanf("%ld",&arr[i]);
	}
	clock_gettime(CLOCK_REALTIME, &start);
	mergesort(arr,l,r,n);
	clock_gettime(CLOCK_REALTIME, &end);
	printf("\n The Array is Sorted now : \n");
	for(i=0;i<n;i++){
		printf("-> %ld",arr[i]);
	}
	printf("\n\nSTART : %ld.%ld\n  END : %ld.%ld\n",start.tv_sec,start.tv_nsec,end.tv_sec,end.tv_nsec);
   	
	printf("\n\nTIME Difference:\t %ld.%ld\n",end.tv_sec-start.tv_sec,end.tv_nsec-start.tv_nsec);
	
	return 0;
}

int mergesort(long int arr[],int l, int r, int n){
	int mid;
	if(l<r){
		mid=((l+r)/2);
		mergesort(arr,l,mid,n);
		mergesort(arr,mid+1,r,n);
		merge(arr,l,mid,r,n);
	}
	return -1;	
}

int merge(long int arr[], int l, int mid , int r,int n){
	int i , j , k;
	long int *c;
	c=(long int*)malloc(n*sizeof(long int));
	k=0;
	i=l;
	j=mid+1;
	while(i<=mid && j<=r){
		if(arr[i]<arr[j]){
			c[k++]=arr[i++];
		}
		else{
			c[k++]=arr[j++];
		}
	}
	while(i<=mid){
		c[k++]=arr[i++];
	}
	while(j<=r){
		c[k++]=arr[j++];
	}
	for(i=r;i>=l;i--){
		arr[i]=c[--k];
	}
	return -1;
}
