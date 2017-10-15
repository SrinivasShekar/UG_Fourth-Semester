#include<stdio.h>
#include<stdlib.h>
#include<time.h>

double time_elapsed(struct timespec *,struct timespec *);
int *heap_sort(int *,int);
int *heap_bottom_up(int *,int);
int *heapify(int *,int,int);
void print(int *,int);

int number_of_comps=0;

int main(){
	int i,j,size;
	int *list;
	scanf("%d",&size);
	list=(int *)malloc((size+1)*sizeof(int));
	for(i=1;i<size+1;i++){
		scanf("%d",&list[i]);
	}
	struct timespec start,end;
	clock_gettime(CLOCK_REALTIME,&start);

	list=heap_sort(list,size);

	clock_gettime(CLOCK_REALTIME,&end);
	
	print(list,size);
	printf("execution time : %lf ms\n", time_elapsed(&start, &end));
	printf("no_of_comps = %d \n",number_of_comps);
free(list);
return 0;
}
int *heap_sort(int *arr,int n){
	int i,temp;
	arr=heap_bottom_up(arr,n);
	for(i=n;i>=2;i--){
		temp=arr[i];
		arr[i]=arr[1];
		arr[1]=temp;
		arr=heapify(arr,1,i-1);
	}
return arr;
}
int *heap_bottom_up(int *arr,int n){
	int i;
	if(n<=1)
		return arr;
	for(i=n/2;i>=1;i--)
		arr=heapify(arr,i,n);
return arr;
}
int *heapify(int *arr,int k,int n){
	int temp;
	if(2*k>n)
		return arr;
	int j=2*k;
	if(j+1<=n)
		if(arr[j+1] > arr[j])
			j++;
	if(arr[j] > arr[k]){
		temp=arr[j];
		arr[j]=arr[k];
		arr[k]=temp;
		
		number_of_comps++;
	}
	arr=heapify(arr,j,n);
return arr;
}
void print(int *arr,int n){
	int i;
	for(i=1;i<=n;i++)
		printf("%d ,",arr[i]);
printf("\n");
}
double time_elapsed(struct timespec *start, struct timespec *end){
	double t = 0.0;
	t = (end->tv_sec - start->tv_sec) * 1000;
	t += (end->tv_nsec - start->tv_nsec) * 0.000001;
	return t;
}
