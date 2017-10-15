#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>


double time_elapsed(struct timespec *,struct timespec *);
void insertion_sort(int);
void print(int);
int *a;
int main(){
	int size,i;
	scanf("%d",&size);
	a=(int *)malloc(size*sizeof(int));
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	struct timespec start,end;
	clock_gettime(CLOCK_REALTIME,&start);
	
	insertion_sort(size);
	
	clock_gettime(CLOCK_REALTIME,&end);
	print(size);
	printf("execution time : %lf ms\n", time_elapsed(&start, &end));
return 0;
}

void insertion_sort(int n){
	int i,r;
	for(i=1;i<n;i++){
		r=arr[i];
		int j=i-1;
		while(j>=0 && strcmp(arr[j].reg_num,v.reg_num)<0){
			arr[j+1].reg_num=arr[j].reg_num;
			arr[j+1].name=arr[j].name;
			arr[j+1].cgpa=arr[j].cgpa;
			j=j-1;
		}
		arr[j+1]=v;
	}
return arr;
}

void print(struct reg *arr,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%s %s %lf\n",arr[i].reg_num,arr[i].name,arr[i].cgpa);
	}
printf("\n");
}

double time_elapsed(struct timespec *start, struct timespec *end) {
	double t = 0.0;
	t = (end->tv_sec - start->tv_sec) * 1000;
	t += (end->tv_nsec - start->tv_nsec) * 0.000001;
	return t;
}
