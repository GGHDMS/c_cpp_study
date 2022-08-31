//작성자 허석문 HW52

#include<stdio.h>
FILE *fileOpen(const char *filename, const char *mode);
int fileRead(FILE *fp, int *dataArray);
void sort(int, int *);

int main()
{
	int testCnt;
	int dataCnt;
	int dataArray[100];
	int i, j;
	FILE *fp;
	fp = fileOpen("C:\\data\\hw52_sortData.txt", "rt");
	if (fp == NULL)return 1;

	fscanf(fp, "%d", &testCnt);
	for (i = 0; i < testCnt; i++)
	{
		printf("소트 전 데이터:");
		dataCnt = fileRead(fp, dataArray);
		for (j = 0; j < dataCnt; j++)
		{
			printf("%3d", dataArray[j]);
		}
		printf("\n");
		sort(dataCnt, dataArray);
		printf("소트 후 데이터:");
		for (j = 0; j < dataCnt; j++)
		{
			printf("%3d", dataArray[j]);
		}
		printf("\n\n");
	}
	fclose(fp);
	return 0;
}

FILE * fileOpen(const char *filename, const char *mode)
{
	FILE *fp;
	if ((fp = fopen(filename, mode)) == NULL) {
		printf("File open error!\n");
	}
	return fp;
}

int fileRead(FILE *fp, int *dataArray)
{
	int dataCnt = 0;
	while (1) {
		fscanf(fp, "%d", &dataArray[dataCnt]);
		if (dataArray[dataCnt] == 0)break;
		dataCnt++;
	}
	return dataCnt;
}

void sort(int dataCnt, int *dataArray)
{
	int i, j, min, calc;
	for (i = 0; i < dataCnt-1; i++)
	{
		min = dataArray[i];
		for (j = i + 1; j < dataCnt; j++)
		{
			if (dataArray[j] < min)
			{
				calc = min;
				dataArray[i] = dataArray[j];
				min = dataArray[j];
				dataArray[j] = calc;
			}
		}
	}
}