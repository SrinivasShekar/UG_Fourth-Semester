#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

double time_elapsed(struct timespec *start,struct timespec *end);

struct student{
	char usn[10];
	char name[50];
	char grade[10];
};

typedef struct student info;

void quicksort(info *,int ,int);
int partition(info *, int , int);
void swap(info *, int, int);

int main(){
	
	int n, i, j;
	struct timespec start,end;	
	scanf("%d",&n);	
	info * arr;
	
	arr=(info*)malloc(n*sizeof(info)*10);	
	int l=0;
	int r=n-1;
	
	for(i=0;i<n;i++){
		scanf("%s",arr[i].usn);
		scanf("%s",arr[i].name);
		scanf("%s",arr[i].grade);
		
	}
	clock_gettime(CLOCK_REALTIME, &start);
	quicksort(arr,l,r);
	clock_gettime(CLOCK_REALTIME, &end);
	printf("\n Sorted array: \n");
	for(i=0;i<n;i++){
		printf("%s %s %s\n",arr[i].usn, arr[i].name, arr[i].grade);
	}
	
	printf("Execution time=%lfms",time_elapsed(&start,&end));
	
	return 0;
}

void quicksort(info *arr,int l ,int r){

	int j;

   	if( l < r ) 
   	{
   		
	   	j = partition(arr,l,r);
       		quicksort(arr,l,j-1);
       		quicksort(arr,j+1,r);
   	}
}

int partition(info *arr, int l, int r) {
  char pivot[30];
	strcpy(pivot, arr[l].usn);
	int i=l,j=r+1;
	while(1){
		i++;
		for(; strcmp(arr[i].usn,pivot) < 0 && (i <= r); i++);
		j--;
		for(; strcmp(arr[j].usn, pivot) > 0 && (j >= 0); j--);
		if(i<j)
			swap(arr, i, j);
		else
			break;
	}
	swap(arr, l, j);
	return j;
}

void swap(info *arr, int i, int j){
	info temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}


double time_elapsed(struct timespec *start,struct timespec *end)
{	double t=0.0;
	t=(end->tv_sec - start->tv_sec)*1000;
	t+=(end->tv_nsec -start->tv_nsec)*0.000001;
}

