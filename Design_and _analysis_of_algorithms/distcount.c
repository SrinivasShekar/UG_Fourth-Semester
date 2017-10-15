#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>
#include<string.h>
struct stud
{
	char *usn;
	char *name;
	int gpa;
};
double time_elapsed(struct timespec *start, struct timespec *end);
void print(struct stud *s,int n);
void distcount(struct stud *s,int n,int l,int u);
int main()
{
	int i,n;
	struct timespec start,end;
	scanf("%d",&n);
	struct stud *s1=(struct stud *)malloc(n*sizeof(struct stud));
	struct stud *s=(struct stud *)malloc(n*sizeof(struct stud));
	
	for(i=0;i<n;i++)
	{	s[i].usn=(char *)malloc(20*sizeof(char));
		s[i].name=(char *)malloc(25*sizeof(char));
		scanf("%s",s[i].usn);
		scanf("%s",s[i].name);
		scanf("%d",&s[i].gpa);
	}
	clock_gettime(CLOCK_REALTIME,&start);
	distcount(s,n,0,101);
	clock_gettime(CLOCK_REALTIME,&end);
	//print(s1,n);
	
	//free(s1);
	printf("execution time : %lf ms\n", time_elapsed(&start, &end));
}

void  distcount(struct stud *s,int n,int l,int u)
{
	int j,i,*d;struct stud *s1,*temp;
	d=(int *)malloc(n*sizeof(int));
	s1=(struct stud *)malloc(u*sizeof(struct stud));
	for(j=0;j<u;j++)
	{	d[j]=0;
	}
	for(i=0;i<n;i++)
	{	d[(s[i].gpa)-l]=d[(s[i].gpa)- l]+1;
	}
	
	for(j=1;j<u;j++)
	{	d[j]=d[j-1]+d[j];
	}
	for(i=n-1;i>=0;i--)
	{
		j=s[i].gpa-l;
		s1[d[j]-1].name=s[i].name;
		s1[d[j]-1].usn=s[i].usn;
		s1[d[j]-1].gpa=s[i].gpa;
		
		//strcpy(s1[d[j]-1].name,s[i].name);
		
		d[j]=d[j]-1;
	}
	
	print(s1,n);

}
double time_elapsed(struct timespec *start, struct timespec *end) 
{
	double t = 0.0;
	t = (end->tv_sec - start->tv_sec) * 1000;
	t += (end->tv_nsec - start->tv_nsec) * 0.000001;
	return t;
}

void print(struct stud *s,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%s ",s[i].usn);
		printf("%s ",s[i].name);
		printf("%d\n ",s[i].gpa);
	}

}

