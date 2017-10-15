#include<stdio.h>
#include<malloc.h>
#include<time.h>
#include<string.h>

struct stud{
char id[20];
char name[20];
float gpa;
};

float time_elapsed(struct timespec *start, struct timespec *end);
struct stud * insertion(struct stud *s,int n);
int main()
{
	int n,i;struct timespec start,end;
	struct stud *s;
	scanf("%d",&n);
	s=(struct stud*)malloc(sizeof(struct stud)*n);
	for(i=0;i<n;i++)
	{	scanf("%s %s %lf",s[i].id,s[i].name,&s[i].gpa);
	}
	
	
	clock_gettime(CLOCK_REALTIME,&start);
	s=insertion(s,n);
	clock_gettime(CLOCK_REALTIME,&end);
	for(i=0;i<n;i++)
	{
		printf("%s ",s[i].id);
		printf("%s ",s[i].name);
		printf("%lf\n",s[i].gpa);
	}
	
	
	printf("Time taken is %f milliseconds\n",time_elapsed(&start,&end));
	free(s);
}
float time_elapsed(struct timespec *start, struct timespec *end)
{
	float t=0.0;
	t=(end->tv_sec-start->tv_sec)*1000;
	t=t+((end->tv_nsec-start->tv_nsec)*0.000001);
	return t;
}


struct stud *insertion(struct stud *s,int n)
{
	int i,j;
	struct stud ele;
	for(i=1;i<=n-1;i++);
	{
		ele=s[i];
		j=i-1;
		while(j>=0 && (strcmp(s[j].id,ele.id) <=0))
		{
			s[j+1]=s[j];
			j=j-1;
		}
		s[j+1]=ele;
	}
	return s;
}


