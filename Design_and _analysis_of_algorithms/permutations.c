#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#include<time.h>
int get_next_permutation(int *permutation, int n);
void print_permutation(int *permutation, int n);
int tsp(int n,int **arr);

struct timespec start,end;

int main() {
	int n;//permutation of n symbols
	int i,j; //loop index
	int *permutation; // permutation array

	scanf("%d", &n); //n > 1
	permutation = (int *) malloc(n * sizeof(int));
	int *arr[n];

	for(i=0;i<n;i++)
	{	arr[i]=(int *)malloc(sizeof(int)*n);
		for(j=0;j<n;j++)
		{	
			scanf("%d ",&arr[i][j]);
		}
	}
	//first permutation
	for(i = 0; i < n; i++) {
		permutation[i] = i;
	}

	//do while there is a next permutation in lexicographic order
	clock_gettime(CLOCK_REALTIME, &start);
	do {
		
		print_permutation(permutation, n);
		
	} while (get_next_permutation(permutation, n));
	printf("%d\n",tsp(n,arr));
	clock_gettime(CLOCK_REALTIME, &end);
	printf("\n\nSTART : %ld.%ld\n  END : %ld.%ld\n",start.tv_sec,start.tv_nsec,end.tv_sec,end.tv_nsec);
   	
	printf("\n\nTIME Difference:\t %ld.%ld\n",end.tv_sec-start.tv_sec,end.tv_nsec-start.tv_nsec);	


	return 0;
	

	
	
}

// Get the next permutation in lexicographic order
int get_next_permutation(int *permutation, int n) {
	int i;
	int j;
	int k;
	int temp_int;
	int swaps;

	//find i
	for(i = n-2; i >= 0; i--) {
		if(permutation[i] < permutation[i+1]) {
			break;
		}
	}
	if(i == -1) {
		return 0;
	}

	for(j = i+1; j < n; j++) {
		if(permutation[j] < permutation[i]) {
			break;
		}
	}
	j--;

	temp_int = permutation[i];
	permutation[i] = permutation[j];
	permutation[j] = temp_int;

	//printf("DEBUG*i=%d,j=%d*", i, j); print_permutation(permutation, n);
	swaps = (n-1-i)/2;	
	for(k = 0; k < swaps; k++) {
		temp_int = permutation[i+1+k];
		permutation[i+1+k] = permutation[n-1-k];
		permutation[n-1-k] = temp_int;
	}
	return 1;
}

void print_permutation(int *permutation, int n) {
	int i;
	printf("[");
	for(i = 0; i < n-1; i++) {
		printf("%d, ", permutation[i]);
	}
	printf("%d]\n", permutation[n-1]);
	
}

// Function to be used as algorithm for the given problem
int tsp(int n,int **arr)
{	
	int mincost=INT_MAX;
	int permutation[n-1];
	int i;
	for(i=1;i<n;i++)
		permutation[i-1]=i;
	int cost;
	do
	{	cost=arr[0][permutation[0]];
		for(i=0;i<=n-3;i++)
			cost+=arr[permutation[i]][permutation[i+1]];
		cost+=arr[permutation[n-2]][0];
		if(cost<mincost)
			mincost=cost;
	}while(get_next_permutation(permutation,n-1));
	return mincost;
}
