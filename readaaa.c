#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_USER 20
#define MAX_MS 40
#define USR 4
int main(int argc,char** argv)
{
	int ruid = 1001;
	char* ms[MAX_USER]={0};
	int uid[MAX_USER]={-1};	
	FILE* fp=fopen("aaa","r+b");
	if (fp!=NULL)
		printf("open aaa successfully\n");
	else
		printf("failed open aaa\n");
	int i=0;
	int j=0;
	while(!feof(fp)){
		ms[i]=(char *)malloc(MAX_MS*sizeof(char));
		fscanf(fp,"%d %s",&uid[i],ms[i]);
		i++;
	}
	fclose(fp);
	for(j=0;j<USR;j++)
	{
		printf("%d:%s\n",uid[j],ms[j]);
	}
	if (strcmp(argv[1], "-read") == 0)
	{
		for (j = 0; j<USR; j++)
		{
			if (ruid == uid[j])
				printf("your ms:%s", ms[j]);
		}
	}
	if (strcmp(argv[1], "-write") == 0)
	{
		for (j = 0; j<USR; j++)
		{
			if (ruid == uid[j])
			{
				memset(ms[j], 0, MAX_MS);
				memcpy(ms[j], argv[2], strlen(argv[2]));
			}
		}
		FILE *fp = fopen("aaa", "w");
		for (j = 0; j<USR; j++)
		{
			fprintf(fp, "%d:%s\n", uid[j], ms[j]);
		}
	}
	return 0;
}
