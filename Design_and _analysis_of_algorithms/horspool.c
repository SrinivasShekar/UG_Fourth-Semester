#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<malloc.h>
#include<string.h>
void shifttable(char *p);
int horspool(char *p,char *t);
int table[255];
double time_elapsed(struct timespec *start, struct timespec *end);
int main()
{
	char *t,*p;int c;
	t=(char *)malloc(10000000*sizeof(char));
	p=(char *)malloc(100*sizeof(char));
	gets(t);
	gets(p);
	c=horspool(p,t);
	printf("String found at:%d\n",c);
}
void shifttable(char *p)
{
	int i,j,m=strlen(p);
	
	for(i=0;i<=255;i++)
	{
		table[i]=m;
	}
	for(j=0;j<=m-2;j++)
	{
		table[p[j]]=m-1-j;
	}
	
}
int horspool(char *p,char *t)
{
	shifttable(p);
	int i,k,m=strlen(p),n=strlen(t);
	i=m-1;
	while(i<=n-1)
	{
		k=0;
		while(k<=m-1 && p[m-1-k]==t[i-k])
		{	k=k+1;
	
		}
		if(k==m)
		{	return i-m+1;
		}
		else
		{
			i=i+table[t[i]];
		}
	}
	//return -1;
}
