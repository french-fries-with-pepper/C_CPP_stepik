#include <stdio.h>
#include <stdlib.h>
int countChildren(int pid)
{
	int SIZE = 1024;
	int res = 0;
	char path[SIZE];
	FILE *fp;
	sprintf(path, "/proc/%d/task/%d/children", pid, pid);
	fp = fopen(path, "r");
	if (fp == NULL)
		printf("cant find file...");
	while (1)
	{
		int child = 0;
		if (fscanf(fp, "%d", &child) == EOF)
			break;
		++res;
		res += countChildren(child);
	}
	return res;
}
int main(int agrc, char *argv[])
{
	int pid = atoi(argv[1]);
	int res = countChildren(pid);
	printf("%d\n", ++res);
	return 0;
}