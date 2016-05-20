#include <stdio.h>
#include <stdlib.h>
#define MAX_USER 20
#define MAX_MS 40
int main(int argc,char** argv)
{
	char* ms[MAX_USER]={0};
	int uid[MAX_USER]={-1};	
	FILE* fp=fopen("aaa","r+b");
	if (fp!=NULL)
		printf("open aaa successfully\n");
	else
		printf("failed open aaa\n");
	int i=0;
	int j=0;
	while(feof(fp)){
		ms[i]=(char *)malloc(MAX_MS*sizeof(char));
		fscanf(fp,"%d %s",&uid[i],ms[i]);
		printf("%d %s",uid[i],ms[i]);
		i++;
	}
	for(j=0;j<i;j++)
	{
		printf("%d:%s",uid[i],ms[i]);
	}
}
